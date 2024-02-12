#include <iostream>
#include "Game.h"
#include <thread>
#include <chrono>

#include "../Read_Command/Read_Command.h"
#include "../Terminal_Command/Terminal_Command.h"
#include "../Message/LogOutput.h"
#include "../Message/New_Message/New_Message.h"
#include "../Message/Lose_Message/Lose_Message.h"
#include "../Message/Win_Message/Win_Message.h"

void Game::create_new_game() {
    char user_choice_level;
    std::string level;
    Player* player = new Player(50, 70, 60);
    Field_Builder field_build = Field_Builder(10, 10);
    Field *my_field = field_build.get_field();
    Player_Reference pl_ref =  Player_Reference(player, my_field);
    // запросить у пользвателя куда выводить информация и передавать в конструктор лога
    LogOutput * output = new LogOutput();
    WinMessage winMessage(pl_ref.get_health(), pl_ref.get_satiety(), pl_ref.get_points());
    output->printLog(winMessage);
    std::cout<<"Choose game level. Enter the number from 1 to 2"<<std::endl;
    std::cin>>user_choice_level;
    int flag = 0;
    switch (user_choice_level) {
        case '1':
            level = "levels/path_level_1.txt";
            flag = 1;
            break;
        case '2':
            level = "levels/path_level_2.txt";
            flag = 1;
            break;
        default:
//            std::cout << "Такое уровня нет, введите корректное значение" << "\n";
            break;
    }
    if (flag == 1 ){
        field_build.create_level(&pl_ref, level);
        start_game(pl_ref, my_field,output);
    }
    else{
        std::cout << "Такого уровня нет. Поэтому Вам предложен начальный уровень игры." << '\n';
        field_build.create_level(&pl_ref, "levels/path_level_1.txt");
        start_game(pl_ref, my_field, output);
    }
}

void Game::start_game(Player_Reference &controller, Field *field_value, LogOutput* output){
    Read_Command readCommand("game/actions.txt");
    readCommand.write_menu();
    TerminalCommandChecker checker(readCommand.getUnorderedMap());

    while (true){
        checker.readCommand(controller, *this, *field_value, output);
        if(output->getMode()==0 || output->getMode()==2){
            std::this_thread::sleep_for(std::chrono::milliseconds(500));

        }
        notify(field_value, controller);
        is_win(controller, field_value, output);
        is_loose(controller, field_value, output);
    }
}
void Game::is_win(Player_Reference &controller, Field *field_value, LogOutput* output){
    if ((controller.get_coordinates().get_x() == field_value->get_finish_point().get_x()) &&
            (controller.get_coordinates().get_y() == field_value->get_finish_point().get_y())){
        WinMessage winMessage(controller.get_health(), controller.get_satiety(), controller.get_points());
        output->printLog(winMessage);
        std::cout << "You win! This is the finish" << "\n";
        finish_game(controller, field_value);
    }
}
void Game::is_loose(Player_Reference &controller, Field *field_value, LogOutput* output){
    if (controller.get_health() <= 0 || controller.get_satiety()<=0){
        LoseMessage loseMessage(controller.get_coordinates());
        output->printLog(loseMessage);
        std::cout << "Sorry, you died. Game over" << "\n";
        finish_game(controller, field_value);
    }
}

void Game::finish_game(Player_Reference &controller, Field *field_value) {
    std::cout << "Do you want to play again? (y/n): ";
    char choice;
    std::cin >> choice;
    if (choice == 'y' || choice == 'Y') {
        create_new_game();

    } else{
        std::cout << "Game over. Goodbye!" << std::endl;
        exit(0);    }
}
