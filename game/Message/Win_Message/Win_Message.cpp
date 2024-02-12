#include "Win_Message.h"
#include <sstream>

WinMessage::WinMessage(int health_value, int satiety_value, int points_value) : health(health_value), satiety(satiety_value), points(points_value){}

std::string WinMessage::toPrint() const {
    std::stringstream ss; // формируется строка для события
    ss << "HP: " << health << ", ST: " << satiety << ", PT: " << points;
    return ss.str(); // и возвращается
}