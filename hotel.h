#ifndef HOTEL_H
#define HOTEL_H
#include "room.h"
#include "guest.h"
#include "receptionist.h"
#include <vector>

class Hotel
{
public:
    Hotel();
    static void addGuest(Guest* guest); // method to create new guest
    static bool isMonstersFull(); // methodo to check if rooms are full for monsters
    static bool isHumansFull(); // same as above but for humans
    static Room* newReservation(Guest* guest, int numOfDays, bool dryCleaning, bool spa); // method to create a new reservation given the guest
    static int changeReservation(Guest* guest, int numOfDays); // change reservation given the guest
    static int addService(Guest* guest, int serviceNumber); // add service given the guest, this method lets the guest choose a room
    static int removeService(Guest* guest, int serviceNumber); // similar to above but remove service instead
    static int cancelReservation(Guest* guest); // similar to above methods

    // getters
    static int getHumanFree();
    static int getMonsterFree();
    static int getGuestsSize();
    static Guest* getGuest(int _id);
private:
    static std::vector<Guest*> guests; // guests in hotel
    static int avaialbleMonsterRooms; // available rooms
    static int avaialbleHumanRooms;

    friend class Receptionist; // friend class to be able to access variables
};

#endif // HOTEL_H
