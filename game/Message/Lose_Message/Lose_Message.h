#ifndef OOP_LB_6_LOSE_MESSAGE_H
#define OOP_LB_6_LOSE_MESSAGE_H
#include <utility>
#include "../Message_Interface/Message_Interface.h"
#include "../LogOutput.h"
#include "../../../field/Point/Point.h"
class LoseMessage : public  MessageInterface{
public:
    LoseMessage(Point coords);
    ~LoseMessage() override = default;
    std::string toPrint() const override;
private:
    LogOutput * output_;
    Point coords_;
};

#endif //OOP_LB_6_LOSE_MESSAGE_H
