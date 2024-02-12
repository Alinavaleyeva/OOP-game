#ifndef GAME_TERMINAL_COMMAND_H
#define GAME_TERMINAL_COMMAND_H
#include <unordered_map>
#include "../Command_Checker/Command_Checker.h"
#include "../Read_Command/Read_Command.h"
class TerminalCommandChecker : public  CommandChecker{
private:
    std::unordered_map<char,Activity> activity_dict;
public:

    TerminalCommandChecker(std::unordered_map<char,Activity> map);
    void readCommand(Player_Reference& controller, Game& game, Field &field, LogOutput * output) override;
};

#endif //GAME_TERMINAL_COMMAND_H
