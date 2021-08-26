#ifndef MONSTERGUEST_H
#define MONSTERGUEST_H
#include "guest.h"
#include "monsterroom.h"

class MonsterGuest : public Guest // inherits from guest
{
public:
    MonsterGuest(std::string usern, std::string classifi);
    Room* addRoom(int nights, bool spa, bool drycleaning); // overrides add room method
};

#endif // MONSTERGUEST_H
