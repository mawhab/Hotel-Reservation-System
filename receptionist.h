#ifndef RECEPTIONIST_H
#define RECEPTIONIST_H
#include "user.h"
#include "hotel.h"

class Receptionist : public User // inhertis from user
{
public:
    Receptionist();
    static void printAllGuests(); // method to print all guest with all their details
    static void printAvailable(); // method to print available rooms
    static void printOccupied(); // method to print occupied rooms
private:
    static int id;
};

#endif // RECEPTIONIST_H
