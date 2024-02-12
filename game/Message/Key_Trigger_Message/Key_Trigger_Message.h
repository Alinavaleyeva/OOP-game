#ifndef OOP_LB_6_KEY_TRIGGER_MESSAGE_H
#define OOP_LB_6_KEY_TRIGGER_MESSAGE_H
#include "../Message_Interface/Message_Interface.h"
#include <utility>
#include "../../Activity.h"
#include "../LogOutput.h"
class KeyTriggeredMessage : public MessageInterface{
public:
    KeyTriggeredMessage(char key, Activity activity);
    ~KeyTriggeredMessage() override = default;
    std::string toPrint() const override;
private:
    char key_;
    Activity activity_;
    LogOutput* output_;
};

#endif //OOP_LB_6_KEY_TRIGGER_MESSAGE_H
