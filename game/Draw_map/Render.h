#ifndef GAME_5_DRAW_MAP_H
#define GAME_5_DRAW_MAP_H
#include "../Game/Game.h"

class Renderer {

public:
    Renderer();
    void setNewValue(Field *field, Player_Reference &controller);
    char check_event(Event *event);
};

#endif //GAME_5_DRAW_MAP_H
