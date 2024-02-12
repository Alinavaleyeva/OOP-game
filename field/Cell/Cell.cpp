#include "Cell.h"
#include "algorithm"

Cell::Cell() : Cell(Type_cell::PASSABLE, nullptr) {} // инициализация type через список инициализации

Cell::Cell(Type_cell type_value, Event* event_value) : type(type_value), event(event_value) {}

Cell::Cell(const Cell& other) : Cell(){
    *this = other;
}

Cell::Cell(Cell&& other) : Cell() {
    *this = std::move(other);
}

Cell& Cell::operator=(const Cell& other) {
    if (this != &other){
        type = std::move(other.type);
        event = std::move(other.event);
    }
    return *this;
}

Cell& Cell :: operator=(Cell&& other) {
    if(this != &other) {
        type = std::move(other.type);
        event = std::move(other.event);

    }
    return *this;
}

void Cell :: set_type(Type_cell new_type){
    type = new_type;
}

bool Cell :: is_entrance() const {
    return type == Type_cell::ENTRANCE;
}

bool Cell :: is_exit() const {
    return type == Type_cell::EXIT;
}

bool Cell :: is_passable() const {
    return type == Type_cell::PASSABLE || type == Type_cell::ENTRANCE || type == Type_cell::EXIT;
}

bool Cell :: is_wall() const {
    return type == Type_cell::WALL;
}

bool Cell::is_event() const{
    return (event != nullptr);
}

void Cell::set_event(Event* event_value){
    if (event_value != nullptr){
        delete_event();
        event = event_value;
    }
}

void Cell::execute_event(){
    event->event_function();
}

void Cell::delete_event(){
    if (event != nullptr){
        delete event;
        event = nullptr;
    }
}

Event* Cell::get_event(){
    return event;
};





