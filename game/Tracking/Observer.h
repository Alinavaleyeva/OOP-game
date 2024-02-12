#ifndef GAME_5_OBSERVER_H
#define GAME_5_OBSERVER_H
#include "../../field/Field/Field.h"
#include "../../player/Player_Referance/Player_Referance.h"
#include "vector"
class Observer{
public:
    virtual ~Observer(){};
    virtual void update(Field * field, Player_Reference &controller) = 0;
};
#endif //GAME_5_OBSERVER_H
