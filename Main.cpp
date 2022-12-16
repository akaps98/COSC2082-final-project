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

        if(choice == "1") {
                while(1) {
                cout << "------------------------\n"
                "This is guest menu: \n";  
                cout << "0. Exit\n"
                     << "1. Registration\n"
                     << "2. View information of all houses\n";
                cout << "Enter your choice: ";

                string guestChoice;
                do {
                    getline(cin, guestChoice);
                } while (guestChoice == "");

                if(guestChoice == "0") {
                    cout << "GOODBYE!";
                    break;
                } else if(guestChoice == "1") {
                    Member doRegister;
                    Member newMember = doRegister.registration(sys.getMemberList()); // After registration,
                    cout << "------------------------\n"   // go to member menu autonatically by system
                            "This is member menu: \n";  
                    cout << "0. Exit\n"
                        << "1. View the user information\n";
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
                    }

                } else if(guestChoice == "2") {
                    sys.showHouseByGuest(sys.getHouseList());
                } else {
                    cout << "You've choosen wrong option!\n"
                        << "------------------------\n";
                }
            }
            break;
        } else if(choice == "2") {
            cout << "------------------------\n";
            Member loggedInMember = sys.loginByMember(sys.getMemberList(), sys.getHouseList());
            cout << "------------------------\n";   // go to member menu after logged in successfully
                while(1) {
                "This is member menu: \n";  
                cout << "0. Exit\n"
                     << "1. View the user information\n";
                cout << "Enter your choice: ";

                string memberChoice;
                do {
                    getline(cin, memberChoice);
                } while (memberChoice == "");

                if(memberChoice == "0") {
                    //sys.saveAllDataByExistMember(loggedInMember);
                    cout << "GOODBYE!\n";
                    break;
                } else if (memberChoice == "1") {
                    sys.showMyInfo(loggedInMember);
                }
            }
            break;
        } else if(choice == "3") {
            while(1) {
                cout << "------------------------\n"
                     <<"This is admin menu: \n";
            }
            break;
        } else {
            cout << "You've choosen wrong option!\n"
                 << "------------------------\n";
        }
    }
}