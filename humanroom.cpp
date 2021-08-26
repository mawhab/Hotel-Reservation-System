#include "humanroom.h"

HumanRoom::HumanRoom(int nights, bool _spa, bool _dryCleaning) : Room(500, 70, 100) // constructor that calculates total room cost
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
