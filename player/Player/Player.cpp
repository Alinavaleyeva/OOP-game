#include <iostream>
#include "Player.h"

Player::Player(): Player(100, 0, 100) {}

Player::Player(int health, int points, int satiety){
    set_health_level(health);
    set_indicator_satiety(satiety);
    set_number_of_points(points);
}

Player :: Player(const Player& other) : Player() {
    *this = other;
}

Player :: Player(Player&& other) : Player() {
    *this = std::move(other);
}

Player& Player :: operator= (const Player& other) {
    if(this != &other) {
        health_level = other.health_level;
        number_of_points = other.number_of_points;
        indicator_satiety = other.indicator_satiety;
    }
    return *this;
}

Player& Player :: operator= (Player&& other) {
    if(this != &other) {
        health_level = std::move(other.health_level);
        number_of_points = std::move(other.number_of_points);
        indicator_satiety = std::move(other.indicator_satiety);
    }
    return *this;
}

int Player::get_health_level() const{
    return health_level;
}
int Player::get_indicator_satiety() const {
    return indicator_satiety;
}
int Player::get_number_of_points() const {
    return number_of_points;
}

void Player::set_health_level(int value){
    if(value >= 100){
        health_level = 100;
    }else if(value <= 0){
        health_level = 0;
        return;
    }else{
        health_level = value;
    }
}

void Player::set_indicator_satiety(int value){
    if(value >= 100){
        indicator_satiety = 100;
    }else if(value <= 0){
        indicator_satiety = 0;

    }else{
        indicator_satiety = value;
    }
}

void Player::set_number_of_points(int value){
    if (value < 0){
        number_of_points = 0;
    }else{
        number_of_points = value;
    }
}

void Player::change_health_level(int value) {
    set_health_level(value + get_health_level());
}

void Player::change_indicator_satiety(int value) {
    set_indicator_satiety(value + get_indicator_satiety());
}

void Player::change_number_of_points(int value) {
    set_number_of_points(value + get_number_of_points());
}
// для дальнейшего, проверка для game over
bool Player::does_allive(){
    return (health_level > 0 && indicator_satiety > 0);
}

