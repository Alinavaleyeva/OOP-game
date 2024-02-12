#include "Field.h"
#include <iostream>

void Field::clear_field() {
    if(field == nullptr) return;

    for(int i = 0; i < dimensions.get_y(); i++) {
        delete[] field[i];
    }
    delete[] field;
    field = nullptr;
}

Cell** Field::create_field(const Point& dimensions) {
    Cell** arr = new Cell* [dimensions.get_y()];
    
    for(int i = 0; i < dimensions.get_y(); i++) {
        arr[i] = new Cell[dimensions.get_x()];
    }
    return arr;
}

// третий конструктор
Field::Field(const Point& dimensions) : dimensions(dimensions), start({-1, -1}), finish({-1, -1}), field(nullptr) {
    if(dimensions.get_x() < MAP_SIZE_LOWER_BOUND || dimensions.get_y() < MAP_SIZE_LOWER_BOUND
        || dimensions.get_x() > MAP_SIZE_UPPER_BOUND || dimensions.get_y() > MAP_SIZE_UPPER_BOUND) {
        throw std::invalid_argument("Неверные значения размера карты");
    }
    field = create_field(dimensions);
}
// второй коструктор, реализовывается через 3
Field::Field(int x_size, int y_size) : Field(Point{x_size, y_size}) {}

Field::Field() : Field(MAP_SIZE_LOWER_BOUND, MAP_SIZE_LOWER_BOUND) {}
//первый, реализ через 2, который реализ через 3
Field::Field(const Field& other) : Field() {
    *this = other;
}

Field :: Field(Field&& other) : Field() {
    *this = std::move(other);
}

Field& Field :: operator= (const Field& other) {
    if(&other != this) {
        clear_field();
        field = create_field(other.dimensions);

        dimensions = other.dimensions;
        start = other.start;
        finish = other.finish;

        for(int i = 0; i < dimensions.get_y(); i++) {
            for(int j = 0; j < dimensions.get_x(); j++) {
                field[i][j] = other.field[i][j];
            }
        }
    }
    return *this;
}

Field& Field :: operator= (Field&& other) {
    if(&other != this) {
        clear_field();
        dimensions = std::move(other.dimensions);
        start = std::move(other.start);
        finish = std::move(other.finish);
        field = std::move(other.field);

        other.field = nullptr;
    }
    return *this;
}

bool Field::is_on_map(const Point& point) const {
    return point.get_x() >= 0 && point.get_y() >= 0 && point.get_x() < dimensions.get_x() && point.get_y() < dimensions.get_y();
}

Point& Field::get_start_point() {
    return start;
}

Point& Field :: get_finish_point() {
    return finish;
}

Point& Field :: get_dimensions() {
    return dimensions;
}

Cell& Field::get_cell(const Point& point) const {
    if(!is_on_map(point)) {
        throw std::out_of_range("Точка находится вне карты");
    }
    return field[point.get_y()][point.get_x()]; // возвращаем cell
}

void Field::set_start(const Point& point) {
    if(is_on_map(point) && get_cell(point).is_passable()) {
        if(start.get_x() != 1 && start.get_y() != 1) {
//            field[start.get_y()][start.get_x()].set_type(Cell::Type_cell::PASSABLE);
            field[point.get_y()][point.get_x()].set_type(Cell::Type_cell::PASSABLE);
        }
        start = point;
        field[start.get_y()][start.get_x()].set_type(Cell::Type_cell::ENTRANCE);
    }
}

void Field :: set_finish(const Point& point) {
    if(is_on_map(point) && get_cell(point).is_passable()) {
        if(finish.get_x() != 1 && finish.get_y() != 1) {
            field[point.get_y()][point.get_x()].set_type(Cell::Type_cell::PASSABLE);
        }
        finish = point;
        field[finish.get_y()][finish.get_x()].set_type(Cell::Type_cell::EXIT);
    }
}

void Field :: create_wall(const Point& point) {
    if(is_on_map(point) && get_cell(point).is_passable()) {
        field[point.get_y()][point.get_x()].set_type(Cell::Type_cell::WALL);
    }
}

void Field :: make_passable(const Point& point) {
    if(is_on_map(point) && !get_cell(point).is_passable()) {
        field[point.get_y()][point.get_x()].set_type(Cell::Type_cell::PASSABLE);
    }
}

void Field::add_event(const Point& point, Event* new_event){
    if(is_on_map(point) && get_cell(point).is_passable()){
        field[point.get_y()][point.get_x()].set_event(new_event);
    }
}

void Field::set_cell(const Point& point, const Cell& new_cell) {
    if(!is_on_map(point)) return;
    field[point.get_y()][point.get_x()] = new_cell;
}

void Field::set_cell(const Point& point, Cell&& new_cell) {
    if(!is_on_map(point)) return;
    field[point.get_y()][point.get_x()] = std::move(new_cell);
}

Field :: ~Field() {
    clear_field();
}