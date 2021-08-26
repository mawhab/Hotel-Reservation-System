#include "room.h"

Room::Room(int ppn, int dcp, int sp) : pricePerNight(ppn), dryCleaningPrice(dcp), spaPrice(sp) // constructor that sets member values
{

}
// SETTERS AND GETTERS
int Room::getPricePerNight(){
    return pricePerNight;
}

int Room::getdryCleaningPrice(){
    return dryCleaningPrice;
}

int Room::getspaPrice(){
    return spaPrice;
}

int Room::getNumberOfNights(){
    return numberOfNights;
}

bool Room::isAvailable(){
    return available;
}

bool Room::hasDryCleaning(){
    return dryCleaning;
}

bool Room::hasSpa(){
    return spa;
}

int Room::getTotalPrice(){
    return totalPrice;
}

void Room::addSpa(){
    if(!spa){
        spa = true;
        totalPrice += spaPrice;
    }
}

void Room::removeSpa(){
    if(spa){
        spa = false;
        totalPrice -= spaPrice;
    }
}

void Room::addDryCleaning(){
    if(!dryCleaning){
        dryCleaning = true;
        totalPrice += dryCleaningPrice;
    }
}

void Room::removeDryCleaning(){
    if(dryCleaning){
        dryCleaning = false;
        totalPrice -= dryCleaningPrice;
    }
}

void Room::changeNumberOfNights(int days){
    if(days>0){
        numberOfNights += days;
        totalPrice += pricePerNight*days;
    }
}
