#ifndef MEGA_LIB_POSITIVE_EVENT_H
#define MEGA_LIB_POSITIVE_EVENT_H
#include "../../interface/Event/Event.h"
#include "../../player/Player_Referance/Player_Referance.h"

class Food : public Event{
private:
    int carrot_value;
    Player_Reference* pl_ref;
public:
    Food(Player_Reference* pl_ref, int value);
    void event_function() override;
};
#endif //MEGA_LIB_POSITIVE_EVENT_H
