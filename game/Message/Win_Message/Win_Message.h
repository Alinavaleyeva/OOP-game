#ifndef OOP_LB_6_WIN_MESSAGE_H
#define OOP_LB_6_WIN_MESSAGE_H

#include "../Message_Interface/Message_Interface.h"
#include "../LogOutput.h"

class WinMessage : public MessageInterface {

public:
    WinMessage(int hp, int st, int pt);
    ~WinMessage() override = default;
    std::string toPrint() const override;
protected:
    LogOutput * output_;
    int health; //уровень здоровья
    int satiety ; //индикатор сытости
    int points; // количество набранных очков
};

#endif //OOP_LB_6_WIN_MESSAGE_H
