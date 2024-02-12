#include <iostream>
#include "Player_Referance.h"

Player_Reference :: Player_Reference(Player* player, Field* field) : player_ref(player), field_ref(field) {
    if(player_ref == nullptr) {
        throw std::invalid_argument("В конструктор был передан nullptr - игрок");
    }
}

void Player_Reference :: set_player(Player* player) {
    if(player != nullptr) {
        player_ref = player;
    } else throw std::invalid_argument("Был передан nullptr - игрок");
}

void Player_Reference :: set_field(Field* field) {
    if(field != nullptr) {
        field_ref = field;
    } else throw std::invalid_argument("Был передан nullptr - поле");
}

Point Player_Reference::get_coordinates() {
    return coordinates;
}

void Player_Reference::movement(Player_Reference::Player_steps steps) {
    switch(steps){
        case Player_steps::LEFT:
            set_coordinates({coordinates.get_x()-1,coordinates.get_y()});
            break;
        case Player_steps::RIGHT:
            set_coordinates({coordinates.get_x() + 1,coordinates.get_y()});
            break;
        case Player_steps::UP:
            set_coordinates({coordinates.get_x(),coordinates.get_y() - 1});
            break;
        case Player_steps::DOWN:
            set_coordinates({coordinates.get_x(),coordinates.get_y() + 1});
            break;
    }

    if(field_ref != nullptr) {
        if(!field_ref->get_cell(coordinates).is_passable()) {
            std::cout << "Клетка поля непроходима";
        }
    }
}

void Player_Reference::set_coordinates(Point new_value) {
    if(field_ref != nullptr) {
        if (field_ref->is_on_map(new_value)){
            if(field_ref->get_cell(new_value).is_passable()) {
                coordinates = new_value;
            } else std::cout << ("Клетка поля непроходима") << '\n';
            if (field_ref->get_cell(new_value).is_event()){
                field_ref->get_cell(new_value).execute_event();
            }
        }else std::cout << ("Клетка находится вне карты") << '\n';
    }

//    else coordinates = new_value; - зачем????
}

void Player_Reference::print_coordinates() {
    std::printf("{ %d ; %d }\n", coordinates.get_x(), coordinates.get_y());
}

int Player_Reference::get_health() const{
    return player_ref->get_health_level();
}

int Player_Reference::get_satiety() const{
    return player_ref->get_indicator_satiety();
}

int Player_Reference::get_points() const{
    return player_ref->get_number_of_points();
}

void Player_Reference::set_health(int health){
    player_ref->set_health_level(health);
}
void Player_Reference::set_satiety(int satiety){
    player_ref->set_indicator_satiety(satiety);
}
void Player_Reference::set_points(int points){
    player_ref->set_number_of_points(points);
}

void Player_Reference::change_health(int value){
    player_ref->change_health_level(value);
}
void Player_Reference::change_satiety(int value){
    player_ref->change_indicator_satiety(value);
}
void Player_Reference::change_points(int value){
    player_ref->change_number_of_points(value);
}

Player_Reference :: ~Player_Reference() {
    if(player_ref != nullptr) delete player_ref;
    if(field_ref  != nullptr) delete field_ref;
}

