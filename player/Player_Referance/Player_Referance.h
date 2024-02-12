#ifndef player_ref_h
#define player_ref_h

#include "../Player/Player.h"
#include "../../field/Field/Field.h"


class Field;
class Player_Reference {
private:
    Player* player_ref;
    Point coordinates;
    Field* field_ref;

public:
    enum class Player_steps {UP, DOWN, LEFT, RIGHT};
    Player_Reference() = delete; // нельзя создавать через пустой коструктор, только с переданными параметрами
    Player_Reference(Player* player, Field* field = nullptr);

    void set_player(Player* player);
    void set_field(Field* field);

    void set_coordinates(Point new_value);
    Point get_coordinates();

    void movement(Player_Reference::Player_steps steps);
    void print_coordinates();

    int get_health() const;
    int get_satiety() const;
    int get_points() const;

    void set_health(int health);
    void set_satiety(int satiety);
    void set_points(int points);

    void change_health(int value);
    void change_satiety(int value);
    void change_points(int value);

    ~Player_Reference();
}; 

#endif