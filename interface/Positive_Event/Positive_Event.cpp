#include "Positive_Event.h"

Food::Food(Player_Reference* controller, int value) {
    pl_ref = controller;
    carrot_value = value;
}

void Food::event_function() {
    pl_ref->change_satiety(carrot_value);
    pl_ref->change_health(5);
//    std::cout << "Сытость: +" << carrot_value <<'\n' << "Здоровье: +5" << '\n' ;
//    std::cout << "Игрок съел морковку, ваши новые характеристики:" << '\n';
//    std::cout << "Уровень здоровья: " << pl_ref->get_health() << "\n";
//    std::cout << "Уровень сытости: " << pl_ref->get_satiety() << "\n";
}