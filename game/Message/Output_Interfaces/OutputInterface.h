//
// Created by alina on 13.12.23.
//

#ifndef OOP_LB_6_OUTPUTINTERFACE_H
#define OOP_LB_6_OUTPUTINTERFACE_H
#include "../Message_Interface/Message_Interface.h"

class OutputInterface {
public:
    virtual void output(const MessageInterface& message) = 0;
    virtual ~OutputInterface() = default;
};



#endif //OOP_LB_6_OUTPUTINTERFACE_H
