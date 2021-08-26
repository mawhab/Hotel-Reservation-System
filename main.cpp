#include <iostream>
#include "hotel.h"
#include "humanguest.h"
#include "monsterguest.h"

using namespace std;

void mainloop(); // main loop that has options menu
int loggedIn(Guest* guest); // logged in menu
int reception(); // receptionist menu

int main()
{
    mainloop();
    return 0;
}


void mainloop(){
    Guest* currentGuest;
    int id;
    while(true){
        int status;
        cout << "\n\nWelcome to Monsters Hotel! (Enter 0 in any prompt to quit)" << endl;
        cout << "Are you a new(1) or existing(2) member?" << endl;
        cin >> status;
        if(status==0){ // if input = 0 user wants to quit
            return;
        }else if(status==1){ // new user
            string username, classification;
            cout << "Please enter your desired username:" << endl;
            cin >> username;
            if(username.compare("0")==0) // if input = 0 user wants to quit
                return;
            cout << "Please enter your class(human or monster)" << endl;
            cin >> classification;
            while(classification.compare("human")!=0 && classification.compare("monster")!=0){ // loop until input is valid
                cout << "Invalid input!" << endl;
                cout << "Please enter your class(human or monster)" << endl;
                cin >> classification;
                if(classification.compare("0")==0) // if input = 0 user wants to quit
                    return;
            }
            if(classification.compare("human")==0){ // create new guest with given details
                currentGuest = new HumanGuest(username, classification);
            }else if(classification.compare("monster")==0){
                currentGuest = new MonsterGuest(username, classification);
            }else
                return;

            Hotel::addGuest(currentGuest); // add guest to hotel
            currentGuest->setId(Hotel::getGuestsSize()); // set unique id
            cout << "Your unique id is: " << currentGuest->getId() << endl; // show user his id
        }else if(status==2){ // existing user
            cout << "Please enter your id:" << endl;
            cin >> id;
            if(id==0){ // if input = 0 user wants to quit
                return;
            }else if(id==999){ // receptionsit id
                int rec = reception(); // call receptionist menu
                if(rec == -1) // if receptionist menu returned -1 then quit
                    return;
                else
                    continue;
            }
            currentGuest = Hotel::getGuest(id); // set current guest
            while(currentGuest==NULL){ // loop until valid input is given
                cout << "Invalid input!" << endl;
                cout << "Please enter your id:" << endl;
                cin >> id;
                if(id==0){
                    return;
                }else if(id==999){ // similar to before
                    int rec = reception();
                    if(rec == -1)
                        return;
                    else
                        continue;
                }
                currentGuest = Hotel::getGuest(id);
            }

        }else{ // if main input wasnt one of the options
            cout << "Invalid input!" << endl;
            continue;
        }

        int res = loggedIn(currentGuest); // call logged in menu

        if(res == -1) return; // if logged in menu returned -1 then quit
        else continue;


    }
}

int loggedIn(Guest* guest){
    int choice;
    while(true){
        cout << "\n\nWelcome " << guest->getUsername() << "!" << endl;

        cout << "What would you like to do?" << endl;

        cout << "1 - New Reservation" << endl;
        cout << "2 - Extend Reservation" << endl;
        cout << "3 - Add Services" << endl;
        cout << "4 - Remove Services" << endl;
        cout << "5 - Cancel Reservation" << endl;
        cout << "6 - View room details" << endl;
        cout << "9 - Logout" << endl;
        cout << "0 - Quit" << endl;

        cin >> choice;

        cout << "\n\n";
        switch (choice) { // switch to find out users input and deal with it accordingly

            Room* room;
            int result;
            case 0:// if input = 0 user wants to quit
                return -1;
            case 1:
                int nights, services;
                cout << "How many nights would you like this room for?" << endl;
                cin >> nights;
                room = Hotel::newReservation(guest, nights, false, false); // create new reservaiton with given number of nights
                if(room==NULL) return 1;
                cout << "Room added successfully!\t Current total: " << room->getTotalPrice() << endl;
                cout << "Would you like dry cleaning(1), spa(2), or both(3)? (any other input for neither) " << endl;
                cin >> services;
                if(services==0) // if input = 0 user wants to quit
                    return -1;
                if(services>=1 && services<=3){
                    guest->addServices(room, services); // add services according to user
                    cout << "Services added successfully!\t Current total: " << room->getTotalPrice() << endl;
                }
                break;
            case 2:
                int extension;
                cout << "Please enter number of days to extend by:" << endl;
                cin >> extension;
                if(extension==0) // if input = 0 user wants to quit
                    return -1;
                result = Hotel::changeReservation(guest, extension);
                if(result == 1) // if success show success message
                    cout << "Extension successful!" << endl;
                break;
            case 3:
                cout << "Which services would you like? dry cleaning(1), spa(2), or both(3)?" << endl;
                cin >> services;
                if(services==0) // if input = 0 user wants to quit
                    return -1;
                while(!(services>=1 && services<=3)){ // loop until input is valid
                    cout << "Invalid input please try again!" << endl;
                    cin >> services;
                    if(services==0) // if input = 0 user wants to quit
                        return -1;
                }
                result = Hotel::addService(guest, services);
                if(result == 1) // if success show success message
                    cout << "Services added successfully!" << endl;

                break;
            case 4:
                cout << "Which services would you like to remove? dry cleaning(1), spa(2), or both(3)?" << endl;
                cin >> services;
                if(services==0) // if input = 0 user wants to quit
                    return -1;
                while(!(services>=1 && services<=3)){ // loop until input is valid
                    cout << "Invalid input please try again!" << endl;
                    cin >> services;
                    if(services==0) // if input = 0 user wants to quit
                        return -1;
                }
                result = Hotel::removeService(guest, services);
                if(result == 1) // if success show success message
                    cout << "Services removed successfully!" << endl;

                break;
            case 5:
                result = Hotel::cancelReservation(guest);
                if(result == 1) // if success show success message
                    cout << "Room cancelled successfully!" << endl;
                break;
            case 6:
                guest->printRooms();
                break;
            case 9: // if input is 9 user wants to logout
                return 1;
                break;
            default:
                cout << "Invalid input, please try again!" << endl;
                break;
        }
    }
    return 1;

}

int reception(){
    int choice;
    while(true){
        cout << "\n\nWelcome Receptionist!" << endl;

        cout << "What would you like to do?" << endl;

        cout << "1 - View number of available rooms" << endl;
        cout << "2 - View number of occupied rooms" << endl;
        cout << "3 - View list of guests" << endl;
        cout << "9 - Logout" << endl;
        cout << "0 - Quit" << endl;

        cin >> choice;

        cout << "\n\n";
        switch (choice) {
            case 0:// if input = 0 user wants to quit
                return -1;
            case 1:
                Receptionist::printAvailable();
                break;
            case 2:
                Receptionist::printOccupied();
                break;
            case 3:
                Receptionist::printAllGuests();
                break;
            case 9: // if input is 9 user wants to logout
                return 1;
                break;
            default:
                cout << "Invalid input, please try again!" << endl;
                break;
        }
    }
    return 1;
}
