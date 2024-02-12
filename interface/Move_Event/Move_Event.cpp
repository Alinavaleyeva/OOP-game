#include "Move_Event.h"

Move_Event::Move_Event(Player_Reference *contr, int x_val, int y_val){
    pl_ref = contr;
    new_coord.set_x(x_val);
    new_coord.set_y(y_val);
}

void Move_Event::event_function() {
    pl_ref->set_coordinates(new_coord);
//    std::cout << "Игрок наступил на телепорт. Ваши новые координаты:"<< ' ';
}