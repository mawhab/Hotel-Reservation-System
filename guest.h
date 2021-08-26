#ifndef GUEST_H
#define GUEST_H
#include "user.h"
#include "room.h"
#include <vector>

class Guest : public User // inherets from user class
{
public:
    Guest(std::string usern, std::string classifi); // constructor
    virtual Room* addRoom(int nights, bool spa, bool drycleaning); // virtual add room method that selects derived class to run from at runtime
    void cancelRoom(Room* room); // method to cancel room
    int modifyRoom(Room* room, int days); // method to extend room
    void addServices(Room* room, int service); // method to add services based on services user wanted
    void removeServices(Room* room, int service); // similar to above but this method removes services
    void printRooms(); // prints all rooms that guest has
    void calculateTotalCost(); // caluclates total cost fror guest for all his rooms and services

    // setters and getters
    Room* getRoom(int i); // gets a room with a specific id
    void setId(int _id); // set guest id
    int getId(); // get guest id
protected:
    std::vector<Room*> rooms; // rooms guest has
    int totalCost; // total cost for guest
    int id; // guest id
};

#endif // GUEST_H
