#ifndef OOP_LB_6_MESSAGE_INTERFACE_H
#define OOP_LB_6_MESSAGE_INTERFACE_H
#include <iosfwd>
#include <string>

class MessageInterface {
private:
public:
    virtual ~MessageInterface() = default;
    virtual std::string toPrint() const= 0; // переопределение, тут нужная строка  о событии
    friend std::ostream& operator << (std::ostream &os, const MessageInterface &messageInterface);
};

#endif //OOP_LB_6_MESSAGE_INTERFACE_H
