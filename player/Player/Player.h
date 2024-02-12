#ifndef player_h
#define player_h
#include <iostream>

class Player{
private:

    int health_level; //уровень здоровья
    int indicator_satiety ; //индикатор сытости
    int number_of_points; // количество набранных очков

public:

    Player();
    Player(int health_level, int number_of_points, int indicator_satiety);
    Player(const Player& other);
    Player(Player&& other);

    Player& operator= (const Player& other);
    Player& operator= (Player&& other);

    int get_health_level() const;
    int get_indicator_satiety() const;
    int get_number_of_points() const;

    void set_health_level(int health);
    void set_indicator_satiety(int satiety);
    void set_number_of_points(int points);

    void change_health_level(int value);
    void change_indicator_satiety(int value);
    void change_number_of_points(int value);

    bool does_allive();

};


#endif 