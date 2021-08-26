#include "receptionist.h"

using namespace std;

Receptionist::Receptionist()
{
}


int Receptionist::id = 999;


void Receptionist::printAllGuests(){ // prints each guests details
    for(Guest* guest: Hotel::guests){
        cout << "Username: " << guest->getUsername() << "\tClass: " << guest->getclass() << endl;
        guest->printRooms();
        cout << "\n\n";
    }
}


void Receptionist::printOccupied(){
    cout << "Number of occupied human rooms: " << 5 - Hotel::getHumanFree() << endl;
    cout << "Number of occupied monster rooms: " << 15 - Hotel::getMonsterFree() << endl;
}

void Receptionist::printAvailable(){
    cout << "Number of available human rooms: " << Hotel::getHumanFree() << endl;
    cout << "Number of available monster rooms: " << Hotel::getMonsterFree() << endl;
}
