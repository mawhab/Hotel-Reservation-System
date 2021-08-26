#include "hotel.h"
using namespace std;
Hotel::Hotel()
{

}

// initialize variable
vector<Guest*> Hotel::guests;

int Hotel::avaialbleMonsterRooms = 15;
int Hotel::avaialbleHumanRooms = 5;
// --------------------------------------


bool Hotel::isMonstersFull()
{
    return avaialbleMonsterRooms<=0; // if no rooms available then monster rooms are full
}

bool Hotel::isHumansFull(){
    return avaialbleHumanRooms<=0; // if no rooms available then human rooms are full
}

int Hotel::getHumanFree(){ // returns number of avialable rooms
    return avaialbleHumanRooms;
}

int Hotel::getMonsterFree(){ // similar to above but for monsters
    return avaialbleMonsterRooms;
}

Room* Hotel::newReservation(Guest *guest, int numOfDays, bool dryCleaning, bool spa){

    if(guest->getclass().compare("monster")){ // if there are no avialable rooms for this type of guest, print error and return NULL
        if(isMonstersFull()){
            cout << "Sorry, all rooms are occupied!" << endl;
            return NULL;
        }
        avaialbleMonsterRooms--;
    }else{
        if(isHumansFull()){
            cout << "Sorry, all rooms are occupied!" << endl;
            return NULL;
        }
        avaialbleHumanRooms--;
    }
    return guest->addRoom(numOfDays, dryCleaning, spa); // else add room
}

int Hotel::changeReservation(Guest *guest, int numOfDays){ // let guest choose room and then extend that room
    guest->printRooms();
    cout << "\n\n Please enter number of room to modify:" << endl;
    int i;
    cin >> i;
    Room* room = guest->getRoom(--i);
    if(room==NULL){ // if room not found print error
        cout << "Invalid room, please try again!" << endl;
        return -1;
    }
    guest->modifyRoom(room, numOfDays);
    return 1;
}


int Hotel::cancelReservation(Guest *guest){ // let guest choose room and then cancel that room
    guest->printRooms();
    cout << "\n\n Please enter number of room to modify:" << endl;
    int i;
    cin >> i;
    Room* room = guest->getRoom(--i);
    if(room==NULL){ // if room not found print error
        cout << "Invalid room, please try again!" << endl;
        return -1;
    }
    guest->cancelRoom(room);
    if(guest->getclass().compare("monster")){
        avaialbleMonsterRooms++;
    }else
        avaialbleHumanRooms++;

    return 1;
}

int Hotel::addService(Guest* guest, int serviceNumber){ // let guest choose room and then modify that room
    guest->printRooms();
    cout << "\n\n Please enter number of room to modify:" << endl;
    int i;
    cin >> i;
    Room* room = guest->getRoom(--i);
    if(room==NULL){ // if room not found print error
        cout << "Invalid room, please try again!" << endl;
        return -1;
    }
    guest->addServices(room, serviceNumber);
    return 1;
}

int Hotel::removeService(Guest* guest, int serviceNumber){ // let guest choose room and then modify that room
    guest->printRooms();
    cout << "\n\n Please enter number of room to modify:" << endl;
    int i;
    cin >> i;
    Room* room = guest->getRoom(--i);
    if(room==NULL){ // if room not found print error
        cout << "Invalid room, please try again!" << endl;
        return -1;
    }
    guest->removeServices(room, serviceNumber);
    return 1;
}

void Hotel::addGuest(Guest *guest){ // given a guest, add to guests vector
    guests.push_back(guest);
}

int Hotel::getGuestsSize(){
    return guests.size();
}

Guest* Hotel::getGuest(int _id){ // returned guest with id, if none found return NULL
    for(Guest* guest: guests){
        if(guest->getId() == _id)
            return guest;
    }

    return NULL;
}
