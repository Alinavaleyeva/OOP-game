#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include "Field_Builder.h"
#include "../../interface/Negative_Event/Negative_Event.h"
#include "../../interface/Positive_Event/Positive_Event.h"
#include "../../interface/Move_Event/Move_Event.h"

Field_Builder::Field_Builder(int x_count, int y_count) {
    field = new Field(x_count, y_count);
}

Field* Field_Builder::get_field(){
    return field;
}

void Field_Builder::set_start(int x, int y){
    field->set_start(Point{x, y});
}
void Field_Builder::set_finish(int x, int y){
    field->set_finish(Point{x, y});
}

void Field_Builder::create_level(Player_Reference* controller, const std::string& level_path){
    int i = 0;
    std::string line;
    std::ifstream in(level_path);

    if (in.is_open()) {
        int line_counter = 0;
        while (std::getline(in, line)) {
            std::string num_str;
            std::istringstream iss(line);
            std::vector<int> numbers;

//            while (std::getline(iss, num_str, ',')){}
//                numbers.push_back(std::stoi(num_str));

            while (std::getline(iss, num_str, ',')) {
                try {
                    numbers.push_back(std::stoi(num_str));
                } catch (const std::invalid_argument& e) {
                    // Обработка некорректных данных
                    std::cerr << "Ошибка: " << e.what() << " в строке " << line_counter << std::endl;
                    // Продолжение обработки или прерывание в зависимости от требований
                } catch (const std::out_of_range& e) {
                    // Обработка переполнения
                    std::cerr << "Ошибка: " << e.what() << " в строке " << line_counter << std::endl;
                    // Продолжение обработки или прерывание в зависимости от требований
                }
            }

            if (line_counter < 2) {
                // Если в первых двух строках, сохраняем пары чисел
                int first_num = numbers[0];
                int second_num = numbers[1];
                if (i == 0) {
                    set_start(first_num, second_num);
                    i++;
                } else {
                    set_finish(first_num, second_num);
                }
                // Сохраните первые два числа где-либо
            } else {
                int first_num = numbers[0];
                int second_num = numbers[1];
                int third_num = numbers[2];
//                int fouth_num = numbers[3];

                Cell my_cell = get_field()->get_cell({first_num, second_num});
//                if(fouth_num == 1){
//                    my_cell.set_type(Cell::Type_cell::WALL);
//                    get_field()->set_cell({first_num, second_num}, my_cell);
//                }
                switch (third_num) {
                    case 0: { // положительное событие
                        Food *event = new Food(controller, 20);
                        my_cell.set_event(event);
                        get_field()->set_cell({first_num, second_num}, my_cell);

                        break;
                    }
                    case 1: { // негативное событие
                        Trap *event = new Trap(controller, 15);
                        my_cell.set_event(event);
                        get_field()->set_cell({first_num, second_num}, my_cell);
                        break;
                    }
                    case 2: { // нейтральное событие - смена координат
                        Move_Event * event = new Move_Event(controller, 2, 3);
                        my_cell.set_event(event);
                        get_field()->set_cell({first_num, second_num}, my_cell);
                        break;
                    }
                }
            }
            line_counter++;
        }
        in.close();
    } else {
        std::cout << "Не удалось открыть файл path_level.txt" << std::endl;
    }
}
