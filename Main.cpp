#include <iostream>
#include <string>

#include "Member.h"
#include "House.h"
#include "Admin.h"
#include "System.h"

using std::string;
using std::cout;
using std::cin;

int main() {
    System sys;

    if(!sys.loadData()) {
        cout << "Fail to load data from database.";
        return -1;
    }

    while(1) {
        cout << "EEET2482/COSC2082 ASSIGNMENT\n" <<
                "VACATION HOUSE EXCHANGE APPLICATION\n\n" <<
                "Instructors: Mr. Linh Tran & Phong Ngo\n" <<
                "Group: Group Name\n" <<
                "s3916884, Kang Junsik\n" <<
                "s3864235, Lee Seungmin\n" <<
                "s3926977, Di Doan\n" <<
                "s3836278, Mai Le Anh Huy\n" << 
                "------------------------\n";
        cout << "Use the app as: \n";
        cout << "1. Guest    2. Member   3. Admin\n";
        cout << "Enter your choice: ";
        
        string choice;
        do {
            getline(cin, choice);
        } while (choice == "");

        if(choice == "1") { // customer chooses 'Guest'
            while(1) {
                cout << "------------------------\n"
                    << "This is guest menu: \n";  
                cout << "0. Exit\n"
                    << "1. Registration\n"
                    << "2. View information of all houses\n";
                cout << "Enter your choice: ";

                string guestChoice;
                do {
                    getline(cin, guestChoice);
                } while (guestChoice == "");

                if(guestChoice == "0") { // Guest chooses 0. exit
                    cout << "GOODBYE!";
                    break;
                } else if(guestChoice == "1") {  // Guest chooses 1. Registration
                    Member doRegister;
                    Member newMember = doRegister.registration(sys.getMemberList()); // After registration,
                    while(1) {
                        cout << "------------------------\n"   // go to member menu autonatically by system
                            << "This is member menu: \n";  
                        cout << "0. Exit\n"
                             << "1. View the user information\n"
                             << "2. View all house information\n"
                             << "3. List / Unlist a house to be occupied\n"
                             << "4. Search for all available suitable houses for a particular city\n";
                        cout << "Enter your choice: ";

                        string memberChoice;
                        do {
                            getline(cin, memberChoice);
                        } while (memberChoice == "");

                        if(memberChoice == "0") {
                            sys.saveAllDataByNewMember(newMember);
                            cout << "GOODBYE!\n";
                            break;
                        } else if (memberChoice == "1") {
                            sys.showMyInfo(newMember);
                        } else if(memberChoice == "2") { // Member chooses 2. View all house information
                            sys.showAllHouseByMember(sys.getHouseList());
                        } else if(memberChoice == "3") { // Member chooses 3. List / Unlist a house to be occupied
                            sys.listHouseAvailable(sys.getMemberList(), sys.getHouseList());
                        } else if(memberChoice == "4") { // Member chooses 4. Search for all available suitable houses for a particular city
                            sys.searchAllAvailableHouses(sys.getMemberList(), sys.getHouseList());
                        }
                    }
                    break;
                } else if(guestChoice == "2") { // Guest chooses 2. View information of all houses
                    sys.showAllHouseByGuest(sys.getHouseList());
                } else { // Member chooses invalid option
                    cout << "You've choosen wrong option!\n"
                        << "------------------------\n";
                }
            }
            break;
        } else if(choice == "2") { // customer chooses 'Member'
            cout << "------------------------\n";
            Member loggedInMember = sys.loginByMember(sys.getMemberList(), sys.getHouseList());
            while(1) {
                cout << "------------------------\n"   // go to member menu after logged in successfully
                     << "This is member menu: \n";  
                cout << "0. Exit\n"
                     << "1. View the user information\n"
                     << "2. View all house information\n"
                     << "3. List / Unlist a house to be occupied\n"
                     << "4. Search for all available suitable houses for a particular city\n";
                cout << "Enter your choice: ";

                string memberChoice;
                do {
                    getline(cin, memberChoice);
                } while (memberChoice == "");

                if(memberChoice == "0") { // Member chooses 0. Exit
                    //sys.saveAllDataByExistMember(loggedInMember);
                    cout << "GOODBYE!\n";
                    break;
                } else if(memberChoice == "1") { // Member chooses 1. View the user information
                    sys.showMyInfo(loggedInMember);
                } else if(memberChoice == "2") { // Member chooses 2. View all house information
                    sys.showAllHouseByMember(sys.getHouseList());
                } else if(memberChoice == "3") { // Member chooses 3. List / Unlist a house to be occupied
                    sys.listHouseAvailable(sys.getMemberList(), sys.getHouseList());
                } else if(memberChoice == "4") { // Member chooses 4. Search for all available suitable houses for a particular city
                    sys.searchAllAvailableHouses(sys.getMemberList(), sys.getHouseList());
                }
            }
            break;
        } else if(choice == "3") { // customer chooses 'Admin'
            sys.loginByAdmin();
            while(1) {
                cout << "------------------------\n"
                     << "This is admin menu: \n";
                cout << "0. Exit\n"
                     << "1. View all user/house information\n";
                cout << "Enter your choice: ";

                string adminChoice;
                do {
                    getline(cin, adminChoice);
                } while (adminChoice == "");

                if(adminChoice == "0") { // Member chooses 0. Exit
                    cout << "GOODBYE!";
                    break;
                } else if(adminChoice == "1") { // Member chooses 1. View all user/house information
                    sys.showAllInfo(sys.getMemberList());
                } else { // Member chooses invalid option
                    cout << "You've choosen wrong option!\n"
                         << "------------------------\n";
                }
            }
            break;
        } else { // customer chooses invalid option
            cout << "You've choosen wrong option!\n"
                 << "------------------------\n";
        }
    }
}