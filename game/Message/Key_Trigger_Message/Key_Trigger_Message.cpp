#include "Key_Trigger_Message.h"
#include <sstream>

KeyTriggeredMessage::KeyTriggeredMessage(char key, Activity activity): key_(key), activity_(activity) {}

std::string KeyTriggeredMessage::toPrint() const {
    std::stringstream ss;
    ss << "Symbol: " << key_ << ", Activity: " << activity_;
    return ss.str();
}