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
        string location, description, stringHouseRating, stringHouseComment, stringOccupied, stringListed, startPoint, endPoint, stringRequiredRating, stringRequiredCredit;
        int requiredRating;
        double requiredCredit;
        vector<int> houseRating;
        vector<string> houseComment;
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
            string rate;
            while(getline(iss, rate, '/')) {
                memberRating.push_back(stoi(rate));
            }
        }
    
        getline(dataFile, stringMemberComment, '\n');

        if(stringMemberComment == "") {   
        } else {
            std::istringstream iss(stringMemberComment);
            string comment;
            while(getline(iss, comment, '/')) {
                memberComment.push_back(comment);
            }
        }
        getline(dataFile, location, ',');
        getline(dataFile, description, ',');
        getline(dataFile, stringHouseRating, ',');

        if(stringHouseRating == "") {
        } else {
            std::istringstream iss(stringHouseRating);
            string rate;
            while(getline(iss, rate, '/')) {
                houseRating.push_back(stoi(rate));
            }
        }

        getline(dataFile, stringHouseComment, ',');

        if(stringHouseComment == "") {
        } else {
            std::istringstream iss(stringHouseComment);
            string comment;
            while(getline(iss, comment, '/')) {
                houseComment.push_back(comment);
            }
        }
        
        getline(dataFile, stringOccupied, ',');
        occupied = stoi(stringOccupied);
        getline(dataFile, stringListed, ',');
        listed = stoi(stringListed);

        if(listed == 0) {
            string nextLine;
            getline(dataFile, nextLine, '\n');
            Member member(username, password, phoneNumber, credit, House(location, description, houseRating, houseComment, occupied, listed), memberRating, memberComment);
            memberList.push_back(member);
            houseList.push_back(member.getHouse());
        } else {
            getline(dataFile, startPoint, ',');
            getline(dataFile, endPoint, ',');
            getline(dataFile, stringRequiredRating, ',');
            requiredRating = stoi(stringRequiredRating);
            getline(dataFile, stringRequiredCredit, '\n');
            requiredCredit = stod(stringRequiredCredit);

            Member member(username, password, phoneNumber, credit, House(location, description, houseRating, houseComment, occupied, listed, startPoint, endPoint, requiredRating, requiredCredit), memberRating, memberComment);
            memberList.push_back(member);
            houseList.push_back(member.getHouse());
        }
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
        int counter = 0;
        for(Member member : memberList) {
            if(inputUsername == member.getusername()) {
                house.setLocation(member.getHouse().getLocation()); 
                house.setDescription(member.getHouse().getDescription());
                house.setRating(member.getHouse().getRating()); 
                house.setComment(member.getHouse().getComment());
                house.setOccupied(member.getHouse().getOccupied()); 
                house.setListed(member.getHouse().getListed());
                if(member.getHouse().getListed() == 1) {
                    string memberStartPoint = member.getHouse().getStartPoint();
                    string memberEndPoint = member.getHouse().getEndPoint();
                    double memberRequiredCredit = member.getHouse().getRequiredCredit();
                    int memberRequiredRating = member.getHouse().getRequiredRating();

                    house.setStartPoint(memberStartPoint);
                    house.setEndPoint(memberEndPoint);
                    house.setRequiredCredit(memberRequiredCredit);
                    house.setRequiredRating(memberRequiredRating);
                }

                user.setusername(member.getusername()); 
                user.setPassword(member.getPassword()); 
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
            counter++;
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


void System::showAllHouseByMember(Member member, vector<House> houseList) {
    cout << "------------------------\n"
         << "All houses Information\n"
         << "-------------------\n";

    int idx = 1;

    for(House house : houseList) {
        cout << "House No." << idx;
        if((member.getHouse().getLocation() == house.getLocation()) && (member.getHouse().getDescription() == house.getDescription())) {
                cout << "\n#####This is your own house!######";
        }
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


Member System::listHouseAvailable(Member member, vector<House> houseList) {
    Function func;
    cout << "------------------------\n";

    if(member.getHouse().getOccupied() == 1) { // if member's house is on list, he/she cannot list their house on sale.
        cout << "Your house is currently occupied!\n"
             << "You cannot list your house on sale until occupation is over!\n";
        return member;
    }

    cout << "List / Unlist a House Avaliable \n"
         << "------------------------\n";

    string startPoint;
    string endPoint;
    int requiredRating;
    double requiredCredit;

    for(House house : houseList) {
        string memLocation = member.getHouse().getLocation();
        string memDescription = member.getHouse().getDescription();
        vector<int> memRating = member.getHouse().getRating();
        vector<string> memComment = member.getHouse().getComment();
        bool memOccupied = member.getHouse().getOccupied();

        if(member.getHouse().getListed() == false) {  // if not listed
            string listChoice;
            cout << "Do you want to list your house? \n"
                << "Enter Y or N: ";
            do {
                getline(cin, listChoice);
            } while(listChoice == "");

            if(func.toUpper(listChoice) == "Y") {
                while(true) {
                    cout << "Enter a start point in yyyymmdd: \n";
                    do {
                        getline(cin, startPoint);
                    } while(startPoint == "");

                    int check = 0;

                    if((startPoint.size() == 8) && (startPoint[4] == '0' || startPoint[4] == '1')  &&  (startPoint[6] == '0' || startPoint[6] == '1' || startPoint[6] == '2' || startPoint[6] == '3')) {  // check the format of dd & mm
                        check = 1;
                        break;
                    } else {
                        cout << "Please enter a valid start point!\n";
                    }
                }

                while(true) {
                    cout << "Enter a end point in ddmmyyyy: \n";
                    do {
                        getline(cin, endPoint);
                    } while(endPoint == "");

                    int check = 0;

                    if((endPoint.size() == 8) && (stoi(startPoint) < stoi(endPoint)) && (endPoint[4] == '0' || endPoint[4] == '1')  &&  (endPoint[6] == '0' || endPoint[6] == '1' || endPoint[6] == '2' || endPoint[6] == '3')) {  // check the format of dd & mm
                        check = 1;
                        break;
                    } else {
                        cout << "Please enter a valid end point!\n";
                    }
                }
                //Need to be fixed about the required credit
                while(true) {
                    cout << "Enter a required credit during the period: \n";
                    // To prevent cheating of occupier required credit should not be 0
                    do {
                        cin >> requiredCredit;
                    } while(requiredCredit == 0);

                    int check = 0;

                    if(0 < requiredCredit) {  // check the required credit is over 0
                        check = 1;
                        break;
                    } else {
                        cout << "Please enter a valid required credit!\n";
                    }
                }
                // Need to be fixed about the required rating
                while(true) {
                    cout << "Enter a required rating of the occupier: \n";
                    //        //Wrong because rating can be 0 if there is no required rating specified
//                    do {
                        cin >> requiredRating;
//                    } while(requiredRating == 0);

                    int check = 0;
                    // Required Rating here is the average rating of the occupier which always lie from -10 to 10.
                    if((-10 <= requiredRating) && (requiredRating <= 10)) {  // check the required rating
                        check = 1;
                        break;
                    } else {
                        cout << "Please enter a valid required rating!\n";
                    }
                }

                member.setHouse(House(memLocation, memDescription, memRating, memComment, memOccupied, 1, startPoint, endPoint, requiredCredit, requiredRating));
                
                cout << "Successfully Listed!\n"
                     << "------------------------\n";

                break;

            } else if(func.toUpper(listChoice) == "N") {
                cout << "Return to Member Menu! \n";
                break;
            } else {
                cout << "You've choosen wrong option! Please select again. \n"
                    << "------------------------\n";
            }

        } else if(member.getHouse().getListed() == true) {  // if listed
            string unlistChoice;
            cout << "Do you want to unlist your house? \n"
                << "Enter Y or N: ";
            do {
                getline(cin, unlistChoice);
            } while(unlistChoice == "");

            if(func.toUpper(unlistChoice) == "Y") {
                startPoint == "";
                endPoint == "";
                requiredCredit == 0;
                requiredRating == 0;
                
                member.setHouse(House(memLocation, memDescription, memRating, memComment, memOccupied, 0));
                
                cout << "Successfully Changed! \n";

                break;
            } else if(func.toUpper(unlistChoice) == "N") {
                cout << "Return to Member Menu! \n";
                break;
            } else {
                cout << "You've choosen wrong option! Please select again. \n"
                     << "------------------------\n";
            }
        }
    }
    return member;
}

// Date and Time is glitchy maybe we should remove it
void System::searchAllAvailableHouses(Member member, vector<House> houseList) {
    cout << "------------------------\n"
         << "Search All Available houses \n"
         << "------------------------\n";
         
    string selectedStartPoint;

    while(true) {
        cout << "Enter the start point that you want(YYYYMMDD): ";
        do {
            getline(cin, selectedStartPoint);
        } while(selectedStartPoint == "");

        if(selectedStartPoint.size() != 8) {
            cout << "Please input valid format!\n";
        } else {
            break;
        }
    }

    string selectedEndPoint;

    while(true) {
        cout << "Enter the end point that you want(YYYYMMDD): ";
        do {
            getline(cin, selectedEndPoint);
        } while(selectedEndPoint == "");

        if((selectedEndPoint.size() != 8) || (stoi(selectedStartPoint) >= stoi(selectedEndPoint))) {
            cout << "Please input valid format!\n";
        } else {
            break;
        }
    }
         
    cout << "This is a cities can be selected: \n"
         << "1. Ha Noi\n"
         << "2. Hue\n"
         << "3. Sai Gon\n"
         << "Enter your choice: ";

    string cityChoice;
    string cityName;

    do {
        getline(cin, cityChoice);
    } while(cityChoice == "");


    if(cityChoice == "1") {
        cityName = "Ha Noi";
        int houseIdx = 1;
        cout << "-------------------------------\n"
             << "Available house list in " << cityName << "\n"
             << "-------------------------------\n";
        for(House house : houseList) {
            if((house.getLocation() == "Ha Noi") && (house.getOccupied() == false) && (house.getListed() == true) && (house.getRequiredRating() <= member.getAvg()) && (house.getRequiredCredit() <= member.getcredit()) && (stoi(selectedStartPoint) <= stoi(house.getStartPoint())) && (stoi(house.getEndPoint()) <= stoi(selectedEndPoint))) {
                cout << "House No." << houseIdx;
                if((member.getHouse().getLocation() == house.getLocation()) && (member.getHouse().getDescription() == house.getDescription())) {
                    cout << "\n#####This is your own house!######";
                }
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
                cout << "Residence requirement:\n";
                cout << "Start date => " << house.getStartPoint();
                cout << "\nEnd date => " << house.getEndPoint();
                cout << "\nTotal required credit points => " << house.getRequiredCredit();
                cout << "\nRequired minimum rating => " << house.getRequiredRating();
                cout << '\n';
                cout << "-------------------------------\n";

                houseIdx++;
            }
        }
        if(houseIdx == 1) {
            cout << "There is no suitable house in " << cityName << " for you.\n";
        }
    } else if(cityChoice == "2") {
        cityName = "Hue";
        int houseIdx = 1;
        cout << "-------------------------------\n"
             << "Available house list in " << cityName << "\n"
             << "-------------------------------\n";
        for(House house : houseList) {
            if((house.getLocation() == "Hue") && (house.getOccupied() == false) && (house.getListed() == true) && (house.getRequiredRating() <= member.getAvg()) && (house.getRequiredCredit() <= member.getcredit()) && (stoi(selectedStartPoint) <= stoi(house.getStartPoint())) && (stoi(house.getEndPoint()) <= stoi(selectedEndPoint))) {
            cout << "House No." << houseIdx;
            if((member.getHouse().getLocation() == house.getLocation()) && (member.getHouse().getDescription() == house.getDescription())) {
                cout << "\n#####This is your own house!######";
            }
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
            cout << "Residence requirement:\n";
            cout << "Start date => " << house.getStartPoint();
            cout << "\nEnd date => " << house.getEndPoint();
            cout << "\nTotal required credit points => " << house.getRequiredCredit();
            cout << "\nRequired minimum rating => " << house.getRequiredRating();
            cout << '\n';
            cout << "-------------------------------\n";

            houseIdx++;
            }
        }
        if(houseIdx == 1) {
            cout << "There is no suitable house in " << cityName << " for you.\n";
        }
    } else if(cityChoice == "3") {
        cityName = "Sai Gon";
        int houseIdx = 1;
        cout << "-------------------------------\n"
             << "Available house list in " << cityName << "\n"
             << "-------------------------------\n";
        for(House house : houseList) {
            if((house.getLocation() == "Sai Gon") && (house.getOccupied() == false) && (house.getListed() == true) && (house.getRequiredRating() <= member.getAvg()) && (house.getRequiredCredit() <= member.getcredit()) && (stoi(selectedStartPoint) <= stoi(house.getStartPoint())) && (stoi(house.getEndPoint()) <= stoi(selectedEndPoint))) {
            cout << "House No." << houseIdx;
            if((member.getHouse().getLocation() == house.getLocation()) && (member.getHouse().getDescription() == house.getDescription())) {
                cout << "\n#####This is your own house!######";
            }
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
            cout << "Residence requirement:\n";
            cout << "Start date => " << house.getStartPoint();
            cout << "\nEnd date => " << house.getEndPoint();
            cout << "\nTotal required credit points => " << house.getRequiredCredit();
            cout << "\nRequired minimum rating => " << house.getRequiredRating();
            cout << '\n';
            cout << "-------------------------------\n";

            houseIdx++;
            }
        }
        if(houseIdx == 1) {
            cout << "There is no suitable house in " << cityName << " for you.\n";
        }
    } else {
        cout << "You've choosen wrong option!\n"
            << "------------------------\n";
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
             << "\nTotal credit: " << member.getcredit()
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
         << "\nTotal credit: " << member.getcredit()
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


bool System::saveData(Member member) {
    fstream dataFile;
    dataFile.open(FILENAME, std::ios::app);

    if(!dataFile.is_open()) {
        cout << "Fail to open the file\n";
        return false;
    }

    dataFile << member.getusername() << "," << member.getPassword() << "," << member.getphoneNumber() << "," << member.getcredit() << ",";

    if(member.getRating().size() == 0) {
        dataFile << ",";
    } else {
        int idx = 1;
        for(int rate : member.getRating()) {
            if(idx == member.getRating().size()) {
                dataFile << rate << ",";
                break;
            }
            dataFile << rate << "/";
            idx++;
        }
    }

    if(member.getComment().size() == 0) {
        dataFile << "\n";
    } else {
        int idx = 1;
        for(string comment : member.getComment()) {
            if(idx == member.getComment().size()) {
                dataFile << comment << "\n";
                break;
            }
            dataFile << comment << "/";
            idx++;
        }
    }

    dataFile << member.getHouse().getLocation() << "," << member.getHouse().getDescription() << ",";

    if(member.getHouse().getRating().size() == 0) {
        dataFile << ",";
    } else {
        int idx = 1;
        for(int rate : member.getHouse().getRating()) {
            if(idx == member.getHouse().getRating().size()) {
                dataFile << rate << ",";
                break;
            }
            dataFile << rate << "/";
            idx++;
        }
    }

    if(member.getHouse().getComment().size() == 0) {
        dataFile << ",";
    } else {
        int idx = 1;
        for(string comment : member.getHouse().getComment()) {
            if(idx == member.getHouse().getComment().size()) {
                dataFile << comment << ",";
                break;
            }
            dataFile << comment << "/";
            idx++;
        }
    }

    dataFile << member.getHouse().getOccupied() << "," << member.getHouse().getListed() << ",";

    if(member.getHouse().getListed() == false) {
        dataFile << "\n";
    } else {
        dataFile << member.getHouse().getStartPoint() << "," << member.getHouse().getEndPoint() << "," << member.getHouse().getRequiredCredit() << "," << member.getHouse().getRequiredRating() << "\n";
    }
    dataFile.close();

    return true;
}


bool System::saveAllData(bool checkNewMember, vector<Member> memberList, Member member) {
    if(checkNewMember == true) { // if the user is new member(after registration),
        saveData(member);
    } else { // if the user is existed member,
        fstream dataFile;
        dataFile.open(FILENAME, std::ios::out);

        if(!dataFile.is_open()) {
            cout << "Fail to open the file\n";
            return false;
        }

        for(Member existMember : memberList) {
            if(member.getusername() == existMember.getusername()) {
                if(member.getHouse().getListed() == 1) {
                    string memLocation = member.getHouse().getLocation();
                    string memDescription = member.getHouse().getDescription();
                    vector<int> memRating = member.getHouse().getRating();
                    vector<string> memComment = member.getHouse().getComment();
                    bool memOccupied = member.getHouse().getOccupied();

                    string memStartPoint = member.getHouse().getStartPoint();
                    string memEndPoint = member.getHouse().getEndPoint();
                    double memRequiredCredit = member.getHouse().getRequiredCredit();
                    int memRequiredRating = member.getHouse().getRequiredRating(); 

                    existMember.setHouse(House(memLocation, memDescription, memRating, memComment, memOccupied, 1, memStartPoint, memEndPoint, memRequiredCredit, memRequiredRating));
                } else {
                    string memLocation = member.getHouse().getLocation();
                    string memDescription = member.getHouse().getDescription();
                    vector<int> memRating = member.getHouse().getRating();
                    vector<string> memComment = member.getHouse().getComment();
                    bool memOccupied = member.getHouse().getOccupied();

                    existMember.setHouse(House(memLocation, memDescription, memRating, memComment, memOccupied, 0));
                }
            }
            saveData(existMember);
        }
    }
    return true;
}

vector<Member> System::getMemberList() {
    return memberList;
};

vector<House> System::getHouseList() {
    return houseList;
};

void System::pushMemberList(Member member) {
    memberList.push_back(member);
};

void System::pushHouseList(House house) {
    houseList.push_back(house);
};
