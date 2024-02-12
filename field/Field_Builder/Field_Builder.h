#ifndef MEGA_LIB_FIELD_BUILDER_H
#define MEGA_LIB_FIELD_BUILDER_H
#include "../../field/Field/Field.h"
#include "../../player/Player_Referance/Player_Referance.h"

//через оператор копирования заносить поле отсюда, затем вызывать деструктор у филда
class Field_Builder {
private:
    Field* field;
public:
    Field_Builder(int x_count, int y_count);
    void set_start(int x, int y);
    void set_finish(int x, int y);
    Field *get_field();
    void create_level(Player_Reference* controller, const std::string& level_path);
};

#endif
