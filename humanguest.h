#ifndef HUMANGUEST_H
#define HUMANGUEST_H
#include "guest.h"
#include "humanroom.h"

class HumanGuest : public Guest // inherets from guest
{
public:
    HumanGuest(std::string usern, std::string classifi);
    Room* addRoom(int nights, bool spa, bool drycleaning); // overrides addroom method
};

#endif // HUMANGUEST_H
