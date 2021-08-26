#include "monsterguest.h"

MonsterGuest::MonsterGuest(std::string usern, std::string classifi) : Guest(usern, classifi)
{

}


Room* MonsterGuest::addRoom(int nights, bool spa, bool drycleaning){ // add monster room
    Room* room = new MonsterRoom(nights, spa, drycleaning);
    rooms.push_back(room);
    calculateTotalCost();
    return room;
}
