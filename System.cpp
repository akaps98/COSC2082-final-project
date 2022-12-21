#include "System.h"

System::System(vector<Member> memberList = {}, vector<House> houseList = {}) {
    this->memberList = memberList;
    this->houseList = houseList;
}

bool System::loadData() {
    fstream checkFile;
    checkFile.open(FILENAME, std::ios::in);

    string checkSen;

    getline(checkFile, checkSen);

    if(checkSen == "") {
        memberList = {};
        houseList = {};
        return true;
    }

    fstream dataFile;
    dataFile.open(FILENAME, std::ios::in);

    if(!dataFile.is_open()) {
        cout << "Fail to open the file\n";
        return false;
    }

    while(!dataFile.eof()) {
        // member attributes
        string username, password, phoneNumber, stringcredit, stringMemberRating, stringMemberComment;
        double credit;
        vector<int> memberRating;
        vector<string> memberComment;

        // house attributes
        string location, description, stringHouseRating, stringHouseComment, stringOccupied, stringListed;
        vector<int> houseRating, requiredRating;
        vector<string> houseComment, startPoint, endPoint;
        bool occupied, listed;

        getline(dataFile, username, ',');
        if(username == "") {
            break;
        }
        getline(dataFile, password, ',');
        getline(dataFile, phoneNumber, ',');
        getline(dataFile, stringcredit, ',');

        credit = std::stod(stringcredit);

        getline(dataFile, stringMemberRating, ',');
    
        if(stringMemberRating == "") {
        } else {
            std::istringstream iss(stringMemberRating);
            string sen;
            while(getline(iss, sen, '/')) {
                memberRating.push_back(stoi(sen));
            }
        }
    
        getline(dataFile, stringMemberComment, '\n');

        if(stringMemberComment == "") {   
        } else {
            std::istringstream iss(stringMemberComment);
            string num;
            while(getline(iss, num, '/')) {
                memberComment.push_back(num);
            }
        }
        getline(dataFile, location, ',');
        getline(dataFile, description, ',');
        getline(dataFile, stringHouseRating, ',');

        if(stringHouseRating == "") {
        } else {
            std::istringstream iss(stringHouseRating);
            string sen;
            while(getline(iss, sen, '/')) {
                houseRating.push_back(stoi(sen));
            }
        }

        getline(dataFile, stringHouseComment, ',');

        if(stringHouseComment == "") {
        } else {
            std::istringstream iss(stringHouseComment);
            string sen;
            while(getline(iss, sen, '/')) {
                houseComment.push_back(sen);
            }
        }
        
        getline(dataFile, stringOccupied, ',');
        occupied = stoi(stringOccupied);
        getline(dataFile, stringListed, '\n');
        listed = stoi(stringListed);

        Member member(username, password, phoneNumber, credit, House(location, description, houseRating, houseComment, occupied, listed, startPoint, endPoint, requiredRating), memberRating, memberComment);
        memberList.push_back(member);
        houseList.push_back(member.getHouse());
    }

    dataFile.close();
    return true;
}


Member System::loginByMember(vector<Member> memberList, vector<House> houseList) {
    string inputUsername;

    House house;
    Member user;

    while(true) {
        cout << "Enter your username: ";
        
        do {
            getline(cin, inputUsername);
        } while (inputUsername == "");

        for(Member member : memberList) {
            if(inputUsername == member.getusername()) {
                house.setLocation(member.getHouse().getLocation()); 
                house.setDescription(member.getHouse().getDescription());
                house.setRating(member.getHouse().getRating()); 
                house.setComment(member.getHouse().getComment());
                house.setOccupied(member.getHouse().getOccupied()); 
                house.setListed(member.getHouse().getListed());

                user.setusername(member.getusername()); user.setPassword(member.getPassword()); 
                user.setphoneNumber(member.getphoneNumber()); 
                user.setcredit(member.getcredit()); 
                user.setHouse(house); 
                user.setRating(member.getRating()); 
                user.setComment(member.getComment()); 

                string inputPassword;

                while(true) {
                    cout << "Enter your password: ";
        
                    do {
                        getline(cin, inputPassword);
                    } while (inputPassword == "");

                    if(inputPassword == user.getPassword()) {
                        cout << "Successfully logged in!\n";
                        return user;
                        break;
                    } else {
                        cout << "Wrong password.\nPlease try again.\n";
                        cout << "---------------------------\n";
                    }
                }
                break;
            }
        }
        cout << "The username is not exists.\n"
             << "-------------------------\n";
    }
};


void System::loginByAdmin() {
    Admin admin;
    string inputUsername;

    while(true){
        cout << "Enter admin username: ";
            
        do {
            getline(cin, inputUsername);
        } while (inputUsername == "");

        if(inputUsername == admin.getUsername()) {
            string inputPassword;
            while(true) {
                cout << "Enter admin password: ";

                do {
                    getline(cin, inputPassword);
                } while (inputPassword == "");

                if(inputPassword == admin.getPassword()) {
                    cout << "Successfully logged in!\n";
                    break;
                } else {
                    cout << "Wrong password.\nPlease try again.\n";
                    cout << "---------------------------\n";
                }
            }
            break;
        }
        cout << "Incorrect Username.\nPlease try again.\n"
             << "-------------------------\n";
    }
}


void System::showAllHouseByGuest(vector<House> houseList) {
    cout << "------------------------\n"
         << "All houses Information\n"
         << "-------------------\n";

    int idx = 1;

    for(House house : houseList) {
        cout << "House No." << idx;
        cout << "\nLocation: " << house.getLocation() << '\n';
        cout << "Description: " << house.getDescription() << '\n';
        cout << "-------------------------------\n";
        idx++;
    }
}


void System::showAllHouseByMember(vector<House> houseList) {
    cout << "------------------------\n"
         << "All houses Information\n"
         << "-------------------\n";

    int idx = 1;

    for(House house : houseList) {
        cout << "House No." << idx;
        cout << "\nLocation: " << house.getLocation() << '\n';
        cout << "Description: " << house.getDescription() << '\n';
        cout << "Reviews:\n";
        if(house.getRating().size() == 0) {
            cout << "This house doesn't have any review yet.\n";
        } else {
            for(int idx = 0; idx < house.getRating().size(); idx++) {
                cout << house.getRating()[idx] << " rating point: " << house.getComment()[idx] << '\n';
            }
        }

        cout << "Availability: ";

        if(house.getOccupied() == false) {
            if(house.getListed() == true) {
                cout << "Available to occupy. It's on sale now.";
            } else {
                cout << "Available to occupy, but not on sale currently.";
            }
        } else {
            cout << "Unavailable to occupy. Another customer is occupying now.";
        }
    cout << '\n';
    cout << "-------------------------------\n";
    idx++;
    }
}


void System::listHouseAvailable(vector<Member> memberList, vector<House> houseList) {
    Function func;

    cout << "------------------------\n"
         << "List / Unlist a House Avaliable \n"
         << "-------------------\n";


    string startPoint, endPoint;
    int requiredRating = 0;

    for(House house : houseList) {
        if(house.getListed() == false) {  // if not listed
            
            while(true) {
                cout << "Enter a start point in ddmmyyyy: \n";
                do {
                    getline(cin, startPoint);
                } while(startPoint == "");

                int check = 0;

                if((startPoint[0] == '0' || startPoint[0] == '1' || startPoint[0] == '2' || startPoint[0] == '3') && (startPoint[2] == '0' || startPoint[2] == '1')) {  // check the format of dd & mm
                    check = 1;

                    break;
                } else {
                    cout << "Please enter a valid start point!";
                }
            }

            while(true) {
                cout << "Enter a end point in ddmmyyyy: \n";
                do {
                    getline(cin, endPoint);
                } while(endPoint == "");

                int check = 0;

                if((endPoint[0] == '0' || endPoint[0] == '1' || endPoint[0] == '2' || endPoint[0] == '3') && (endPoint[2] == '0' || endPoint[2] == '1')) {  // check the format of dd & mm
                    check = 1;

                    break;
                } else {
                    cout << "Please enter a valid end point!";
                }
            }

            while(true) {
                cout << "Enter a required rating of the occupirer: \n";
                do {
                    // getline(cin, requiredRating);
                    cin >> requiredRating;
                } while(requiredRating == 0);

                int check = 0;

                if((-10 <= requiredRating) && (requiredRating <= 10)) {  // check the required rating
                    check = 1;
                    cin.ignore();

                    break;
                } else {
                    cout << "Please enter a valid required rating!";
                }
            }
            
            house.changeListed();
            cout << "Successfully Listed!\n"
                    << "------------------------\n";
            break;

        } else if(house.getListed() == true) {  // if listed
            string unlistChoice;
            cout << "Do you want to unlist your house? \n"
                << "Enter Y or N: ";
            do {
                getline(cin, unlistChoice);
            } while(unlistChoice == "");

            if(unlistChoice == "Y") {
                house.changeListed();
                cout << "Successfully Changed! \n";
                break;
            } else if(unlistChoice == "N") {
                cout << "Return to Member Menu! \n";
                break;
            } else {
                cout << "You've choosen wrong option! Please select again. \n"
                    << "------------------------\n";
            }
        }
    }
}


void System::searchAllAvailableHouses(vector<Member> memberList, vector<House> houseList) {
    cout << "------------------------\n"
         << "Search All Available houses \n"
         << "-------------------\n"
         << "This is a cities can be selected: \n"
         << "1. Ha Noi\n"
         << "2. Hue\n"
         << "3. Sai Gon\n"
         << "Enter your choice: ";

    string cityChoice;
    int idx = 1;
    do {
        getline(cin, cityChoice);
    } while(cityChoice == "");

    for(Member member : memberList) {
        if(cityChoice == "1") {
            for(House house : houseList) {
                if((house.getLocation() == "Ha Noi") && (house.getOccupied() == false) && (house.getListed() == true) && (house.getRequiredRating() <= member.getRating())) {
                    cout << "-------------------------------\n";
                    cout << "House No." << idx;
                    cout << "\nLocation: " << house.getLocation() << '\n';
                    cout << "Description: " << house.getDescription() << '\n';
                    cout << "Reviews:\n";
                    if(house.getRating().size() == 0) {
                        cout << "This house doesn't have any review yet.\n";
                    } else {
                        for(int idx = 0; idx < house.getRating().size(); idx++) {
                            cout << house.getRating()[idx] << " rating point: " << house.getComment()[idx] << '\n';
                        }
                    }
                    // cout << "Start Point: " << house.getStartPoint() << '\n';
                    // cout << "End Point: " << house.getStartPoint() << '\n';
                    cout << '\n';
                    cout << "-------------------------------\n";
                }
                idx++;
            }
        } else if(cityChoice == "2") {
            for(House house : houseList) {
                if((house.getLocation() == "Hue") && (house.getOccupied() == false) && (house.getListed() == true) && (house.getRequiredRating() <= member.getRating())) {
                    cout << "-------------------------------\n";
                    cout << "House No." << idx;
                    cout << "\nLocation: " << house.getLocation() << '\n';
                    cout << "Description: " << house.getDescription() << '\n';
                    cout << "Reviews:\n";
                    if(house.getRating().size() == 0) {
                        cout << "This house doesn't have any review yet.\n";
                    } else {
                        for(int idx = 0; idx < house.getRating().size(); idx++) {
                            cout << house.getRating()[idx] << " rating point: " << house.getComment()[idx] << '\n';
                        }
                    }
                    // cout << "Start Point: " << house.getStartPoint() << '\n';
                    // cout << "End Point: " << house.getStartPoint() << '\n';
                    cout << '\n';
                    cout << "-------------------------------\n";
                }
                idx++;
            }
        } else if(cityChoice == "3") {
            for(House house : houseList) {
                if((house.getLocation() == "Sai Gon") && (house.getOccupied() == false) && (house.getListed() == true) && (house.getRequiredRating() <= member.getRating())) {
                    cout << "-------------------------------\n";
                    cout << "House No." << idx;
                    cout << "\nLocation: " << house.getLocation() << '\n';
                    cout << "Description: " << house.getDescription() << '\n';
                    cout << "Reviews:\n";
                    if(house.getRating().size() == 0) {
                        cout << "This house doesn't have any review yet.\n";
                    } else {
                        for(int idx = 0; idx < house.getRating().size(); idx++) {
                            cout << house.getRating()[idx] << " rating point: " << house.getComment()[idx] << '\n';
                        }
                    }
                    // cout << "Start Point: " << house.getStartPoint() << '\n';
                    // cout << "End Point: " << house.getStartPoint() << '\n';
                    cout << '\n';
                    cout << "-------------------------------\n";
                }
                idx++;
            }
        } else {
            cout << "You've choosen wrong option!\n"
                << "------------------------\n";
        }
    }
}


void System::showAllInfo(vector<Member> memberList) {
    cout << "------------------------\n"
         << "All Members & Houses Information\n"
         << "-------------------\n";

    int idx = 1;

    for(Member member : memberList) {
        cout << "User No." << idx << " -> " << member.getusername() << "'s user information\n************************\n";
        cout << "Username: " << member.getusername()
             << "\nPassword: " << member.getPassword()
             << "\nPhone number: " << member.getphoneNumber()
             << "\n-------------------\n"
             << "All reviews about " << member.getusername() << ":\n";

        if(member.getRating().size() == 0) {
        cout << member.getusername() << " doesn't have any review yet.\n";
        } else {
            for(int idx = 0; idx < member.getRating().size(); idx++) {
                cout << member.getRating()[idx] << " rating point: " << member.getComment()[idx] << '\n';
            }
        }
        cout << member.getusername() << "'s house information\n************************\n";

        cout << "Location: " << member.getHouse().getLocation()
             << "\nDescrption: " << member.getHouse().getDescription()
             << "\n-------------------\n"
             << "All reviews about " << member.getusername() << "'s house:\n";

        if(member.getHouse().getRating().size() == 0) {
            cout << member.getusername() << "'s house doesn't have any review yet.\n";
        } else {
            for(int idx = 0; idx < member.getHouse().getRating().size(); idx++) {
                cout << member.getHouse().getRating()[idx] << " rating point: " << member.getHouse().getComment()[idx] << '\n';
            }
        }

        cout << "Availability: ";

        if(member.getHouse().getOccupied() == false) {
            if(member.getHouse().getListed() == true) {
                cout << "Available to occupy. It's on sale now.";
            } else {
                cout << "Available to occupy, but not on sale currently.";
            }
        } else {
            cout << "Unavailable to occupy. Another customer is occupying now.";
        }
        cout << "\n------------------------\n";
        idx++;
    }
};


void System::showMyInfo(Member member) {
    cout << "------------------------\n"
         << "Your account information\n"
         << "-------------------\n";

    cout << "Username: " << member.getusername()
         << "\nPassword: " << member.getPassword()
         << "\nPhone number: " << member.getphoneNumber()
         << "\n-------------------\n"
         << "All reviews about you:\n";

    if(member.getRating().size() == 0) {
        cout << "You don't have any review yet.\n";
    } else {
        for(int idx = 0; idx < member.getRating().size(); idx++) {
            cout << member.getRating()[idx] << " rating point: " << member.getComment()[idx] << '\n';
        }
    }

    cout << "------------------------\n"
         << "Your house information\n"
         << "-------------------\n";
    cout << "Location: " << member.getHouse().getLocation()
         << "\nDescrption: " << member.getHouse().getDescription()
         << "\n-------------------\n"
         << "All reviews about your house:\n";

    if(member.getHouse().getRating().size() == 0) {
        cout << "Your house doesn't have any review yet.\n";
    } else {
        for(int idx = 0; idx < member.getHouse().getRating().size(); idx++) {
            cout << member.getHouse().getRating()[idx] << " rating point: " << member.getHouse().getComment()[idx] << '\n';
        }
    }
    
    cout << "Availability: ";

    if(member.getHouse().getOccupied() == false) {
        if(member.getHouse().getListed() == true) {
            cout << "Available to occupy. It's on sale now.\n";
        } else {
            cout << "Available to occupy, but not on sale currently.\n";
        }
    } else {
        cout << "Unavailable to occupy. Another customer is occupying now.\n";
    }
};


bool System::saveAllDataByNewMember(Member member) {
    fstream dataFile;
    dataFile.open(FILENAME, std::ios::app);

    if(!dataFile.is_open()) {
        cout << "Fail to open the file\n";
        return false;
    }

    dataFile << member.getusername() << "," << member.getPassword() << "," << member.getphoneNumber() << "," << member.getcredit() << ",";
    dataFile << ",\n"; // No value on rating and comment when registration

    dataFile << member.getHouse().getLocation() << "," << member.getHouse().getDescription() << ",";
    dataFile << ",,0,0"; // No value on rating and comment when registration (either bool value for occupied and listed)
    dataFile << ",,,0"; // No value on start & end point and required rating when registration
    // dataFile << member.getHouse().getStartPoint() << "," << member.getHouse().getEndPoint() << "," << member.getHouse().getRequiredRating() << "\n";

    dataFile.close();
    return true;
}

vector<Member> System::getMemberList() {
    return memberList;
};

vector<House> System::getHouseList() {
    return houseList;
};