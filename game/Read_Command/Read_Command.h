#ifndef MY_GAME_PROJECT_READ_COMMAND_H
#define MY_GAME_PROJECT_READ_COMMAND_H

#include <unordered_map>
#include <string>
#include "../../player/Player/Player.h"
#include "../Game/Game.h"
#include "../Activity.h"

class Read_Command {
private:
    std::unordered_map<char,Activity> activity_dict;
public:
    std::unordered_map<char,Activity> getUnorderedMap();
    Read_Command(const std::string path_file);
    void setDefaultValues();
    void write_menu();
    bool isValueAlreadyExist(Activity value) const;
    bool isKeyAlreadyExist(char key) const;
};

#endif //MY_GAME_PROJECT_READ_COMMAND_H
