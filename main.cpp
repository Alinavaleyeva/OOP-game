#include <iostream>
#include "player/Player_Referance/Player_Referance.h"
#include "player/Player/Player.h"
#include "game/Game/Game.h"
#include "game/Tracking/Listener.h"
int main() {
    Game my_game;
    Listener my_listen = Listener(my_game);
    my_game.attach(&my_listen);
    my_game.create_new_game();
    return 0;
}
