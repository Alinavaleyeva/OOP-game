#ifndef GAME_5_LISTENER_H
#define GAME_5_LISTENER_H
#include <iostream>
#include "Observer.h"
#include "Subject.h"
#include "../Draw_map/Render.h"

class Listener : public Observer{
private:
    Subject & subject;

public:
    Listener(Subject & subject1);
    virtual ~Listener(){};
    void update(Field *field, Player_Reference &controller, std::vector<bool> states) override {//TODO возможно сюда вынести проверку на победу или проигрыш пользователя
        Renderer render; // объект отрисовки поля
        render.setNewValue(field,controller);
    }
    void DeteleMe();
};
#endif //GAME_5_LISTENER_H
