#ifndef GAME_COMMAND_CHECKER_H
#define GAME_COMMAND_CHECKER_H
#include "../Game/Game.h"

class CommandChecker {
public:
    virtual void readCommand(Player_Reference& controller, Game& game, Field &field, LogOutput * output ) = 0;
};

#endif //GAME_COMMAND_CHECKER_H
