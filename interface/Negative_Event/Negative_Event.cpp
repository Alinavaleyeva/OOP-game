#include "Negative_Event.h"

Trap::Trap(Player_Reference *controller, int value) {
    pl_ref = controller;
    pain_value = value;
}

void Trap::event_function() {
    pl_ref->change_health(-pain_value);
//    std::cout << "Здоровье: " << -pain_value << '\n';
//    std::cout << "Игрок попал в ловушку. Ваши новые характеристики:" << '\n';
//    std::cout << "Уровень здоровья: " << pl_ref->get_health()<<"\n";
}