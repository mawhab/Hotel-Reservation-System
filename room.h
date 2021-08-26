#ifndef ROOM_H
#define ROOM_H


class Room
{
public:
    Room(int ppn, int dcp, int sp); // constructor

    void changeNumberOfNights(int days); // extend reservation

    void addSpa(); // method to add service
    void removeSpa(); // method to remove service

    void addDryCleaning(); // similar to above
    void removeDryCleaning();

    // getters
    bool hasDryCleaning();
    bool hasSpa();
    int getNumberOfNights();
    bool isAvailable();
    int getTotalPrice();
    int getPricePerNight();
    int getdryCleaningPrice();
    int getspaPrice();
protected:
    const int pricePerNight; // constant price per night
    const int dryCleaningPrice; // constant dry cleaning price
    const int spaPrice; // constant spa price
    int numberOfNights; // number of reserved nights
    bool available; // room available or not
    bool dryCleaning; // room has dry cleaning or not
    bool spa; // room has spa or not
    int totalPrice; // total room price
};

#endif // ROOM_H
