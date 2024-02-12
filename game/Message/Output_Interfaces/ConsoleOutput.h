#ifndef OOP_LB_6_CONSOLEOUTPUT_H
#define OOP_LB_6_CONSOLEOUTPUT_H
#include "OutputInterface.h"
#include <iostream>
class ConsoleOutput : public  OutputInterface{
public:
    void output(const MessageInterface& message) override {
        std::cout << message << std::endl;
    }

};


#endif //OOP_LB_6_CONSOLEOUTPUT_H
