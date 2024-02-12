#include <iostream>
#include "Render.h"
#include <vector>
#include <thread>
#include <chrono>

#include "../../interface/Positive_Event/Positive_Event.h"
#include "../../interface/Negative_Event//Negative_Event.h"
#include "../../interface/Move_Event//Move_Event.h"

Renderer::Renderer() {
}

void Renderer::setNewValue(Field *field, Player_Reference &controller) {
    std::vector<bool> flags = {false, false, false};
    //std::this_thread::sleep_for(std::chrono::seconds(1));

    std::system("clear");
    std::cout<<"COORDS: ";
    controller.print_coordinates();
    std::cout<<"HP: "<<controller.get_health()<<std::endl;
    std::cout<<"ST: "<<controller.get_satiety()<<std::endl;
    for(int i = 0; i < field->get_dimensions().get_y(); i++) {
        for(int j = 0; j < field->get_dimensions().get_x(); j++) {
            if (field->get_cell({j,i}).is_exit()){
                std::cout << "#";
            }
            if(controller.get_coordinates().get_x() == j && controller.get_coordinates().get_y() == i) {
                std::cout << 'P'; // 'P' означает игрока
                if(field->get_cell({j,i}).is_event()){
                    char event = check_event(field->get_cell({j,i}).get_event());
                    if(event=='!'){
                        flags[0]= true;
                        Cell my_cage = field->get_cell({j,i});
                        my_cage.set_event(nullptr);//Костыль века
                        field->set_cell({j,i},my_cage);
                    }
                    else if(event=='@'){
                        flags[1] = true;
                        Cell my_cage = field->get_cell({j,i});//TODO спрятать как нибудь этот галимый костыль
                        my_cage.set_event(nullptr);//Костыль века
                        field->set_cell({j,i},my_cage);
                    }
                    else{
                        flags[2] = true;//возможно из-за этого падать будет
                        Cell my_cage = field->get_cell({j,i});
                        my_cage.set_event(nullptr);//Костыль века
                        field->set_cell({j,i},my_cage);
                    }
                }
            } else if(field->get_cell({j, i}).get_event() != nullptr) {
                char event = check_event(field->get_cell({j,i}).get_event());


                std::cout<<event;
                // Здесь вы можете использовать различные символы для разных типов событий

            } else if(field->get_cell({j, i}).is_passable()) {
                std::cout << '-'; // '-' означает доступную клетку
            } else {
                std::cout << '='; // '=' означает недоступную клетку
            }
        }
        std::cout << std::endl;
    }
    if(flags[0]){
        std::cout<<"Игрок съел морковку "<<std::endl;

        flags[0] = false;
    }else if(flags[1]){
        std::cout<<"Игрок попал в ловушку "<<std::endl;

        flags[1] = false;
    }
    else if(flags[2]){
        std::cout<<"Игрок наступил на телепорт : "<<std::endl;

        flags[2] = false;
    }
}

char Renderer::check_event(Event *event) {
    if(typeid(*event) == typeid(Food)){
        return '!';
    }
    else if(typeid(*event) == typeid(Trap)){
        return '@';
    }
    else if(typeid(*event)== typeid(Move_Event)){

        return 'T';
    }
    return 'a';
}