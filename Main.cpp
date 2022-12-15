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
            cout << "------------------------\n"
            "This is guest menu: \n";  
            cout << "0. Exit\n"
                 << "1. Registration\n"
                 << "2. View information\n";
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
                Member newMember = doRegister.registration(); // After registration,
                cout << "------------------------\n"   // go to guest menu autonatically by system
                        "This is member menu: \n";  
                cout << "0. Exit\n"
                     << "1. View information\n";
                cout << "Enter your choice: ";

                string memberChoice;
                do {
                    getline(cin, memberChoice);
                } while (memberChoice == "");

                if(memberChoice == "0") {
                    cout << newMember.getPassword(); // recheck saveAllData function on System
                    //sys.saveAllData(newMember);
                    cout << "GOODBYE!\n";
                    //break;
                } else if (memberChoice == "1") {

                }

            } else if(guestChoice == "2") {

            } else {
                cout << "You've choosen wrong option!\n"
                     << "------------------------\n";
            }
        } else if(choice == "2") {
            cout << "------------------------\n"
                    "To use the app as member,\n";
        } else if(choice == "3") {
            cout << "------------------------\n"
                    "This is admin menu: \n";
        } else {
            cout << "You've choosen wrong option!\n"
                 << "------------------------\n";
        }
    }
}