#ifndef OOP_LB_6_KEY_NOT_TRIGGER_MESSAGE_H
#define OOP_LB_6_KEY_NOT_TRIGGER_MESSAGE_H
#include "../Message_Interface/Message_Interface.h"
#include "../LogOutput.h"
class KeyNotTriggerredMessage : public MessageInterface{
public:
    KeyNotTriggerredMessage(char key);
    ~KeyNotTriggerredMessage() override = default;
    std::string toPrint() const override;
private:
    char key_;
    LogOutput* output_;
};
#endif //OOP_LB_6_KEY_NOT_TRIGGER_MESSAGE_H
