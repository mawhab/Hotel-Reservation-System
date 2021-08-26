#include "humanguest.h"

HumanGuest::HumanGuest(std::string usern, std::string classifi) : Guest(usern,classifi)
{

}


Room* HumanGuest::addRoom(int nights, bool spa, bool drycleaning){ // add human room
    Room* room = new HumanRoom(nights, spa, drycleaning);
    rooms.push_back(room);
    calculateTotalCost();
    return room;
}
