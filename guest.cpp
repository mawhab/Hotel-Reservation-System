#include "guest.h"
using namespace std;
Guest::Guest(std::string usern, std::string classifi) // constructor sets required fields
{
    username = usern;
    classification = classifi;
}

void Guest::cancelRoom(Room* room){ // given a room, find it in vector and delete it
    for(int i=0;i<(int)rooms.size();i++){
        if(rooms[i]==room){
            rooms.erase(rooms.begin()+i);
            return;
        }
    }
    calculateTotalCost(); // recalculate guest cost
}

int Guest::modifyRoom(Room* room, int days){ // extend number of days for given room
    if(room==NULL) // if room not found return error
        return -1;
    room->changeNumberOfNights(days);
    calculateTotalCost(); // recalculate guest cost
    return 1;
}

void Guest::addServices(Room* room, int service){ // add services for given room
    switch (service) {
        case 1:
            room->addDryCleaning();
            break;
        case 2:
            room->addSpa();
            break;
        case 3:
            room->addSpa();
            room->addDryCleaning();
            break;
        default:
            break;
    }
    calculateTotalCost(); // recalculate guest cost
}

void Guest::removeServices(Room* room, int service){ // remove services for given room
    switch (service) {
        case 1:
            room->removeDryCleaning();
            break;
        case 2:
            room->removeSpa();
            break;
        case 3:
            room->removeSpa();
            room->removeDryCleaning();
            break;
        default:
            break;
    }
    calculateTotalCost(); // recalculate guest cost
}

void Guest::printRooms(){
    for(int i=0;i<(int)rooms.size();i++){ // for each room print room details
        cout << (i+1) << "\tNumber of Nights:" << rooms[i]->getNumberOfNights() << ", Has spa:";
        cout << rooms[i]->hasSpa() << ", Has dry cleaning:" << rooms[i]->hasDryCleaning();
        cout << "\t Total price: " << rooms[i]->getTotalPrice() << endl;
    }
}

Room* Guest::getRoom(int i){ // get room with id
    if(i>=(int)rooms.size()) // if room not found return NULL
        return NULL;
    return rooms[i];
}

void Guest::calculateTotalCost(){ // add each room total cost
    totalCost = 0;
    for(Room* room: rooms){
        totalCost += room->getTotalPrice();
    }
}

// setters and getters
void Guest::setId(int _id){
    id = _id;
}

int Guest::getId(){
    return id;
}


Room* Guest::addRoom(int nights, bool spa, bool drycleaning){
    return NULL;
}
