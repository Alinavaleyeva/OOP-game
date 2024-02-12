#ifndef MEGA_LIB_NEGATIVE_EVENT_H
#define MEGA_LIB_NEGATIVE_EVENT_H
#include "../../interface/Event/Event.h"
#include "../../player/Player_Referance/Player_Referance.h"

class Trap : public Event{
protected:
    int pain_value;
    Player_Reference* pl_ref;
public:
    Trap(Player_Reference* controller, int value);
    void event_function() override;
};
#endif //MEGA_LIB_NEGATIVE_EVENT_H
