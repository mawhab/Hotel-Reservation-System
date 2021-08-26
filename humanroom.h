#ifndef HUMANROOM_H
#define HUMANROOM_H
#include "room.h"

class HumanRoom : public Room // inherets from room
{
public:
    HumanRoom(int nights, bool spa, bool dryCleaning);
};

#endif // HUMANROOM_H
