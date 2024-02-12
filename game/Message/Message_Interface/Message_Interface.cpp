#include "Message_Interface.h"

std::ostream& operator << (std::ostream &os, const MessageInterface &messageInterface)
{
    os << messageInterface.toPrint();
    return os;
}
