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

        Member member(username, password, phoneNumber, credit, House(location, description, houseRating, houseComment, occupied, listed), memberRating, memberComment);
        memberList.push_back(member);
        houseList.push_back(member.getHouse());
    }

    dataFile.close();
    return true;
}

Member System::loginByMember(vector<Member> memberList, vector<House> houseList) {
    Function func;
    string inputUsername;

    House house;
    Member user;

    while(true) {
        cout << "Enter your username: ";
        
        do {
            getline(cin, inputUsername);
        } while (inputUsername == "");

        int check = 0;
        int idx = 0;

        for(Member member : memberList) {
            cout << inputUsername;
            if(inputUsername == member.getusername()) {
                house.setLocation(member.getHouse().getLocation()); house.setDescription(member.getHouse().getDescription());
                house.setRating(member.getHouse().getRating()); house.setComment(member.getHouse().getComment());
                house.setOccupied(member.getHouse().getOccupied()); house.setListed(member.getHouse().getListed());

                user.setusername(member.getusername()); user.setPassword(member.getPassword()); user.setphoneNumber(member.getphoneNumber()); 
                user.setcredit(member.getcredit()); user.setHouse(house); user.setRating(member.getRating()); user.setComment(member.getComment()); 

                check = 1;
                break;
            }
            idx++;
        }

        if(check = 1) {
            break;
        } else {
            cout << "The username is not exists.\n";
            cout << "---------------------------\n";
        }
    }

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
            cout << "Wrong password.\nPlease try agin.\n";
            cout << "---------------------------\n";
        }
    }

};

void System::showHouseByGuest(vector<House> houseList) {
    cout << "-------------------\n"
         << "House Information\n"
         << "-------------------\n";
    for(House house : houseList) {
        cout << "Location: " << house.getLocation() << '\n';
        cout << "Description: " << house.getDescription() << '\n';
        cout << "-------------------------------\n";
    }
}

void System::showMyInfo(Member member) {
    cout << "-------------------\n"
         << "Your account information\n"
         << "-------------------\n";
    cout << "Username: " << member.getusername()
         << "\nPassword: " << member.getPassword()
         << "\nPhone number: " << member.getphoneNumber()
         << "\n-------------------\n";
    if(member.getRating().size() == 0) {
        cout << "You don't have any review yet.\n";
    } else {
        cout << "All reviews about you\n-------------------\n";
        for(int idx = 0; idx < member.getRating().size(); idx++) {
            cout << member.getRating()[idx] << " score: " << member.getComment()[idx] << '\n';
        }
    }
    cout << "-------------------\n"
         << "Your house information\n"
         << "-------------------\n";
    cout << "Location: " << member.getHouse().getLocation()
         << "\nDescrption: " << member.getHouse().getDescription()
         << "\n-------------------\n";
    if(member.getHouse().getRating().size() == 0) {
        cout << "Your house don't have any review yet.\n-------------------\n";
    } else {
        cout << "All reviews about your house\n-------------------\n";
        for(int idx = 0; idx < member.getHouse().getRating().size(); idx++) {
            cout << member.getHouse().getRating()[idx] << " score: " << member.getHouse().getComment()[idx] << '\n';
        }
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
    dataFile << ",,0,0\n"; // No value on rating and comment when registration (either bool value for occupied and listed)

    dataFile.close();
    return true;
}

vector<Member> System::getMemberList() {
    return memberList;
};

vector<House> System::getHouseList() {
    return houseList;
};