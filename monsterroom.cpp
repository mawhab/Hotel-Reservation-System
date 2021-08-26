#include "monsterroom.h"

MonsterRoom::MonsterRoom(int nights, bool _spa, bool _dryCleaning) : Room(200, 30, 50) // constructor that calculates total room cost
{
    numberOfNights = nights;
    spa = _spa;
    dryCleaning = _dryCleaning;
    totalPrice = nights * pricePerNight;
    if(dryCleaning){
        totalPrice += dryCleaningPrice;
    }
    if(spa){
        totalPrice += spaPrice;
    }
}

