#ifndef field_h
#define field_h

#include "../../field/Cell/Cell.h"
#include "../../field/Point/Point.h"
#include <cstdint>

#define MAP_SIZE_UPPER_BOUND 20
#define MAP_SIZE_LOWER_BOUND 5

class Field {
private:
    Cell** field; // двумерное поле клеток
    Point dimensions; // размер
    Point start, finish; // информация о начале и конце

    void clear_field();
    Cell** create_field(const Point& dimensions); // создание поля

public:
    Field();
    Field(int x_size, int y_size);
    Field(const Point& dimensions);

    Field(const Field& other); // копирование
    Field(Field&& other); // перемещение

    Field& operator= (const Field& other);
    Field& operator= (Field&& other);

    void set_start(const Point& point);
    void set_finish(const Point& point);
    void create_wall(const Point& point);
    void make_passable(const Point& point);
    void add_event(const Point& point, Event* new_event);
    void set_cell(const Point& point, const Cell& new_cell);
    void set_cell(const Point& point, Cell&& new_cell);

    Point& get_start_point();
    Point& get_finish_point();
    Point& get_dimensions();
    Cell& get_cell(const Point& point) const;

    bool is_on_map(const Point& point) const;

    ~Field();
};

#endif