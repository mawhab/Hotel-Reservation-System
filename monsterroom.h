#ifndef MONSTERROOM_H
#define MONSTERROOM_H
#include "room.h"

class MonsterRoom : public Room // inherits from room
{
public:
    MonsterRoom(int nights, bool spa, bool dryCleaning);
};

#endif // MONSTERROOM_H
