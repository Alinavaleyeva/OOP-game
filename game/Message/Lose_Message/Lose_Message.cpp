#include "Lose_Message.h"
#include <sstream>

LoseMessage::LoseMessage(Point coords) : coords_(coords){}

std::string LoseMessage::toPrint() const {
    std::stringstream ss;
    ss <<"X coord: " << coords_.get_x() <<", Y coord: " << coords_.get_y();
    return ss.str();
}