#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "Read_Command.h"

Read_Command::Read_Command(const std::string path_file){
    std::ifstream in(path_file);
    std::string line;
    if (in.is_open()) {
        while (std::getline(in, line)) {
            std::istringstream iss(line);
            std::string key, value;
            if (iss >> key >> value) {
                if (key.length() == 1) {
                    char symbol = key[0];
                    if (value == "UP") {
                        activity_dict[symbol] = UP;
                    } else if (value == "DOWN") {
                        activity_dict[symbol] = DOWN;
                    } else if (value == "LEFT") {
                        activity_dict[symbol] = LEFT;
                    } else if (value == "RIGHT") {
                        activity_dict[symbol] = RIGHT;
                    } else if (value == "START") {
                        activity_dict[symbol] = START;
                    } else if (value == "END") {
                        activity_dict[symbol] = END;
                    }
                }
            }
        }
        in.close();
    } else {
        // Если файл не открыт, устанавливаем значения по умолчанию
        setDefaultValues();
    }
    if (!(isValueAlreadyExist(UP) &&
          isValueAlreadyExist(DOWN) &&
          isValueAlreadyExist(LEFT) &&
          isValueAlreadyExist(RIGHT) &&
          isValueAlreadyExist(START) &&
          isValueAlreadyExist(END)))
    {
        setDefaultValues();
    }
}



void Read_Command::write_menu() {
    std::cout << "List of player control commands:\n";
    for(const auto& pair : activity_dict) {
        std::cout << "Key '" << pair.first << "': ";
        switch(pair.second) {
            case UP:
                std::cout << "up\n";
                break;
            case DOWN:
                std::cout << "down\n";
                break;
            case LEFT:
                std::cout << "left\n";
                break;
            case RIGHT:
                std::cout << "right\n";
                break;
            case START:
                std::cout << "start the game\n";
                break;
            case END:
                std::cout << "завершить игру\n";
                break;
        }
    }
    std::cout << "Have a good game!" << std::endl;
}

void Read_Command::setDefaultValues() {
    activity_dict.clear();
    activity_dict['w'] = UP;
    activity_dict['s'] = DOWN;
    activity_dict['a'] = LEFT;
    activity_dict['d'] = RIGHT;
    activity_dict['l'] = START;
    activity_dict['k'] = END;
}
bool Read_Command::isValueAlreadyExist(Activity value) const {
    for (const auto &i : activity_dict) {
        if (i.second == value)
            return true;
    }
    return false;
}


std::unordered_map<char,Activity> Read_Command::getUnorderedMap() {
    return activity_dict;
}

bool Read_Command::isKeyAlreadyExist(char key) const {
    return activity_dict.find(key) != activity_dict.end();
}
