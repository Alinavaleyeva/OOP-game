#ifndef OOP_LB_6_NEW_MESSAGE_H
#define OOP_LB_6_NEW_MESSAGE_H
#include "../Message_Interface/Message_Interface.h"
#include <utility>
#include "../LogOutput.h"
class NewGameMessage : public MessageInterface{
public:
    NewGameMessage(int x_count, int y_count, std::pair<int, int> coords);
    ~NewGameMessage() override = default;
    std::string toPrint() const override;
private:
//    LogOutput* output_;
    int x_count_;
    int y_count_;
    std::pair<int, int> coords_;
};

#endif //OOP_LB_6_NEW_MESSAGE_H
