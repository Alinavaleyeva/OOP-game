#include "Terminal_Command.h"
//#include "../../player/Player_Referance/Player_Referance.h"
#include <string>
#include <iostream>
#include "../Message/Key_Trigger_Message/Key_Trigger_Message.h"
#include "../Message/Key_Not_Trigger_Message/Key_Not_Trigger_Message.h"

TerminalCommandChecker::TerminalCommandChecker(std::unordered_map<char, Activity> map) {
    activity_dict = map;
}

void TerminalCommandChecker::readCommand(Player_Reference& controller, Game& game, Field &field, LogOutput * output) {
    std::string command;
    std::cin >> command;
    if (activity_dict.find(command[0]) != activity_dict.end()) {
        Activity activity = activity_dict[command[0]];
        switch (activity) {
            case UP:{
                controller.movement(Player_Reference::Player_steps::UP);
                KeyTriggeredMessage message(command[0], activity);
                output->printLog(message);
                break;}
            case DOWN:{
                controller.movement(Player_Reference::Player_steps::DOWN);
                KeyTriggeredMessage message(command[0], activity);
                output->printLog(message);
                break;}
            case LEFT:{
                controller.movement(Player_Reference::Player_steps::LEFT);
                KeyTriggeredMessage message(command[0], activity);
                output->printLog(message);
                break;}
            case RIGHT:{
                controller.movement(Player_Reference::Player_steps::RIGHT);
                KeyTriggeredMessage message(command[0], activity);
                output->printLog(message);
                break;}
            case START:{
                game.create_new_game();//create game поставить
                KeyTriggeredMessage message(command[0], activity);
                output->printLog(message);
                break;}
            case END:{
                game.finish_game(controller, &field);
                KeyTriggeredMessage message(command[0], activity);
                output->printLog(message);
                return;}
        }
    } else {
        std::cout << "Вы ввели неправильную команду" << std::endl;
        KeyNotTriggerredMessage message(command[0]);
        output->printLog(message);
    }
}