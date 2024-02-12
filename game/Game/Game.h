#ifndef MY_GAME_PROJECT_GAME_H
#define MY_GAME_PROJECT_GAME_H
#include <list>
#include "../../player/Player/Player.h"
#include "../../field/Field/Field.h"
#include "../../field/Field_Builder/Field_Builder.h"
#include "../Tracking/Subject.h"
#include "../Message/LogOutput.h"

class Game:public Subject{
private:
    std::list<Observer *> list_observer_;
public:
    ~Game(){};
    void create_new_game();
    void finish_game(Player_Reference &controller, Field *field_value);
    void start_game(Player_Reference &controller, Field *field_value, LogOutput* output);
    void is_win(Player_Reference &controller, Field *field_value, LogOutput* output);
    void is_loose(Player_Reference &controller, Field *field_value, LogOutput* output);

    void attach(Observer *observer) override {
        list_observer_.push_back(observer);
    }
    
    void detach(Observer *observer) override {
        list_observer_.remove(observer);
    }
    void notify(Field *field, Player_Reference &controller) override {
        auto iterator = list_observer_.begin();//Метод, вызывающий отправления обновления у игры.

        while (iterator != list_observer_.end()) {
            (*iterator)->update(field, controller);
            ++iterator;
        }
    }
};

#endif //MY_GAME_PROJECT_GAME_H
