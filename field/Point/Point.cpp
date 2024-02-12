#include "Point.h"

Point::Point():Point(0, 0) {}
Point::Point(int x_val, int y_val) : x(x_val), y(y_val){}

int Point::get_x() const {
    return x;
}
int Point::get_y() const {
    return y;
}

void Point::set_x(int value_x) {
    x = value_x;
}
void Point::set_y(int value_y) {
    y = value_y;
}
