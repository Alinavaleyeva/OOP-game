#include "Key_Not_Trigger_Message.h"
#include <sstream>
KeyNotTriggerredMessage::KeyNotTriggerredMessage(char key): key_(key){}

std::string KeyNotTriggerredMessage::toPrint() const {
    std::stringstream ss;
    ss << "Symbol: " <<key_;
    return ss.str();
}