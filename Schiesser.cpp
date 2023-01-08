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
                    sys.pushMemberList(newMember);
                    sys.pushHouseList(newMember.getHouse());
                    bool checkNewMember = true;
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
                            sys.saveAllData(checkNewMember, sys.getMemberList(), newMember);
                            cout << "GOODBYE!\n";
                            break;
                        } else if (memberChoice == "1") {
                            sys.showMyInfo(newMember);
                        } else if(memberChoice == "2") { // Member chooses 2. View all house information
                            sys.showAllHouseByMember(newMember, sys.getHouseList());
                        } else if(memberChoice == "3") { // Member chooses 3. List / Unlist a house to be occupied
                            newMember = sys.listHouseAvailable(newMember, sys.getHouseList());
                        } else if(memberChoice == "4") { // Member chooses 4. Search for all available suitable houses for a particular city
                            sys.searchAllAvailableHouses(newMember, sys.getHouseList());
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
        	menu:
            cout << "------------------------\n";
            Member loggedInMember = sys.loginByMember(sys.getMemberList(), sys.getHouseList());
            bool checkNewMember = false;
            while(1) {
                cout << "------------------------\n"   // go to member menu after logged in successfully
                     << "This is member menu: \n";
                cout << "0. Exit\n"
                     << "1. View the user information\n"
                     << "2. View all house information\n"
                     << "3. List / Unlist a house to be occupied\n"
                     << "4. Search for all available suitable houses for a particular city\n"
                		//Huy
                		<< "5. Request to occupy a house\n";
                cout << "Enter your choice: ";

                string memberChoice;
                do {
                    getline(cin, memberChoice);
                } while (memberChoice == "");

                if(memberChoice == "0") { // Member chooses 0. Exit
                    sys.saveAllData(checkNewMember, sys.getMemberList(), loggedInMember);
                    cout << "GOODBYE!\n";
                    break;
                } else if(memberChoice == "1") { // Member chooses 1. View the user information
                    sys.showMyInfo(loggedInMember);
                } else if(memberChoice == "2") { // Member chooses 2. View all house information
                    sys.showAllHouseByMember(loggedInMember, sys.getHouseList());
                } else if(memberChoice == "3") { // Member chooses 3. List / Unlist a house to be occupied
                    loggedInMember = sys.listHouseAvailable(loggedInMember, sys.getHouseList());
                } else if(memberChoice == "4") { // Member chooses 4. Search for all available suitable houses for a particular city
                    sys.searchAllAvailableHouses(loggedInMember, sys.getHouseList());
                }
                //Huy works
                else if(memberChoice == "5"){
                	// Show all houses first then let the user choose
                	int i = 0;
                	vector<House> hvt = sys.getHouseList();
                	vector<House> res = {}; //

                	 for (House s: sys.getHouseList()){

                		 if(!s.getListed() ||
                	 loggedInMember.getHouse().getDescription() == s.getDescription()||
					(s.getOccupied())||
					(loggedInMember.getcredit()<s.getRequiredCredit())||
					(loggedInMember.getAvg()<s.getRequiredRating()))	// Filtered by requirements
                		 <%

                			 continue;
                		 %>

                	   	   cout <<  i + 1 << ": "<<s.getLocation() << ": "
                	   							   <<s.getDescription()<< std::endl
												   << "Requirements: " << "Required Credits: "<<s.getRequiredCredit()
												   << " Required Rating: "<<s.getRequiredRating()
												   << " Trial: "<<s.getStartPoint()<<'-'<<s.getEndPoint()<<'\n';
                		 res.push_back(s);
                	   	   i++;

                	     }
                	 if(i==0){
                		 cout<<"There is no house suitable for you based on your credit and rating! \n";
                		 goto menu; // Bad practice but fine anyway
                	 }
                	 int pick = 0;
                	 House huser;
                	 again:
                	 cout<<"Choose a house to request base on the number: \n";
                	 cin>>pick;
                	 if(!(pick >= 1 && pick <= i)){
                		 goto again; // Bad practice but we will use it
                	 }
                	 // House is chosen
                	 huser = res[pick-1];

                	 // Show inner information of this house
                	 int sizeInfo = huser.getComment().size();
                	 int ratingInfo = huser.getRating().size();
                	 <%
					 if(sizeInfo==0){
						 cout<<"There is no comment just yet:\n";
					 }
                	 if(ratingInfo==0){
                		 cout<<"There is no rating just yet:\n";
                	 }
					 %>
                	  vector<int> ratehuser = huser.getRating();
                	 vector<string> commenthuser = huser.getComment();
                	 for(int i = 0; i<sizeInfo; i++){
                		 	cout<<"Rate: " << ratehuser[i] << " Comment: " << commenthuser[i] << std::endl;
                	 }

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
