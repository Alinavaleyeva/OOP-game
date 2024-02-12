#ifndef MEGA_LIB_MOVE_EVENT_H
#define MEGA_LIB_MOVE_EVENT_H
#include "../../interface/Event/Event.h"
#include "../../player/Player_Referance/Player_Referance.h"

class Move_Event : public Event {
private:
    Point new_coord;
    Player_Reference* pl_ref;
public:
    Move_Event(Player_Reference* contr, int x, int y);
    void event_function() override;
};
#endif
