#ifndef GAME_5_SUBJECT_H
#define GAME_5_SUBJECT_H
#include "Observer.h"
#include "../../player/Player_Referance/Player_Referance.h"
#include "../../field/Field/Field.h"

class Subject{
public:
//    virtual ~Subject(){} ;
    virtual ~Subject() = 0;
    virtual void attach(Observer *observer) = 0;
    virtual void detach(Observer *observer) = 0;
    virtual void notify(Field *field, Player_Reference &controller) = 0;
};
#endif //GAME_5_SUBJECT_H
