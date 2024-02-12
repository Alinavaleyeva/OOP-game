#ifndef cell_h
#define cell_h
#include "../../interface/Event/Event.h"

class Cell{
public:
    enum Type_cell{
        ENTRANCE,
        EXIT,
        PASSABLE,
        WALL
    };

    Cell();
    Cell(Type_cell type_cell, Event* event = nullptr);
    Cell(const Cell& other); // конструтор копирования
    Cell(Cell&& other); // конструктор перемещения
    Cell& operator= (const Cell &other); // оператор присваивания с копированием
    Cell& operator= (Cell &&other); // оператор присваивания с перемещением

    void set_type(Type_cell new_type);

    bool is_entrance() const;
    bool is_exit() const;
    bool is_passable() const;
    bool is_wall() const;
    bool is_event() const;
    Event* get_event();
    void set_event(Event* event_value);
    void delete_event();
    void execute_event();
private:
    Type_cell type;
    Event* event;
};

#endif //MY_GAME_CELL_H
