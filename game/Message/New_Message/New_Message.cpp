#include "New_Message.h"
#include <sstream>

NewGameMessage::NewGameMessage(int x_count, int y_count, std::pair<int, int> coords) : x_count_(x_count), y_count_(y_count), coords_(coords){}

std::string NewGameMessage::toPrint() const {
    std::stringstream ss;
    ss << "X count: " << x_count_ << ", Y count: " << y_count_ << ", X coord: " << coords_.first <<", Y coord: " << coords_.second;
    return ss.str();
}