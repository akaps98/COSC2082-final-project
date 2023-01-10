#include "Member.h"

using std::string;
using std::cout;
using std::cin;

Member::Member (string username = "", string password = "", string phoneNumber = "", double credit = 500.0, House house = House(), vector<int> rating = {}, vector<string> comment = {}) {
    this->username = username,
    this->password = password,
    this->phoneNumber = phoneNumber;
    this->credit = credit;
    this->house = house;
    this->rating = rating;
    this->comment = comment;
    this->rq = Request();
    rq.name = phoneNumber;
}

Member Member::registration(vector<Member> memberList) {
    Function func;

    string inputUsername;

    while(true) {
        cout << "Enter your username: ";
        
        do {
            getline(cin, inputUsername);
        } while (inputUsername == "");

        int check = 0;

        for(Member member : memberList) {
            if(func.toLower(inputUsername) == func.toLower(member.getusername())) {
                cout << "This username is duplicated!\n";
                cout << "Please input other username.\n";
                cout << "-------------------------\n";
                check = 1;
                break;
            }
        }

        if(check == 0) {
            break;
        }
    }

    cout << "Enter your password: ";

    string inputPassword;

    do {
        getline(cin, inputPassword);
    } while (inputPassword == "");

    string inputphonenumber;

    while(true) {
        cout << "Enter your phone number: ";
        
        do {
            getline(cin, inputphonenumber);
        } while (inputphonenumber == "");

        int check = 0;

        for(Member member : memberList) {
            if(func.toLower(inputphonenumber) == func.toLower(member.getphoneNumber())) {
                cout << "This phone number is duplicated!\n";
                cout << "Please input other phone number.\n";
                cout << "-------------------------\n";
                check = 1;
                break;
            }
        }

        if(check == 0) {
            break;
        }
    }

    string inputLocation;

    while(true) {
        cout << "-------------------------\n";
        cout << "Enter the location of your house(Ha Noi, Hue, Sai Gon): ";
        
        do {
            getline(cin, inputLocation);
        } while (inputLocation == "");

        int check = 0;

        if(func.toLower(inputLocation) == func.toLower("Ha Noi") || func.toLower(inputLocation) == func.toLower("HaNoi") || func.toLower(inputLocation) == func.toLower("Hue") || func.toLower(inputLocation) == func.toLower("Sai Gon") || func.toLower(inputLocation) == func.toLower("Saigon")) {
            if(func.toLower(inputLocation) == func.toLower("Ha Noi") || func.toLower(inputLocation) == func.toLower("HaNoi")) {
                inputLocation = "Ha Noi";
            } else if (func.toLower(inputLocation) == func.toLower("Hue")) {
                inputLocation = "Hue";
            } else if (func.toLower(inputLocation) == func.toLower("Sai Gon") || func.toLower(inputLocation) == func.toLower("Saigon")) {
                inputLocation = "Sai Gon";
            }
        } else {
            cout << "Wrong location!\n";
            cout << "You can only type among Ha Noi, Hue or Sai Gon.\n";
            check = 1;
        }

        if(check == 0) {
            break;
        }
    }

    cout << "Explain your house: ";
    string inputDesc;
    do {
        getline(cin, inputDesc);
    } while (inputDesc == "");

    Member newMember(inputUsername, inputPassword, inputphonenumber, 500, House(inputLocation, inputDesc, {}, {}, false, false));

    cout << "Registration has been done succuessfully!\n\n";

    return newMember;
}

int Member::getAvg() {
    if(rating.size() == 0) {
        return 0;
    }
    
    int totalRate;
    for(int rate : rating) {
        totalRate += rate;
    }
    return totalRate / this->rating.size();
}

// getter

string Member::getPassword() {
    return password;
}

string Member::getusername() {
    return username;
}

string Member::getphoneNumber() {
    return phoneNumber;
}

double Member::getcredit() {
    return credit;
}

House Member::getHouse() {
    return this->house;
}

vector<int> Member::getRating() {
    return rating;
}

vector<string> Member::getComment() {
    return comment;
}

// setter
 
void Member::setusername(string username) {
    this->username = username;
};

void Member::setPassword(string password) {
    this->password = password;
};

void Member::setphoneNumber(string phoneNumber) {
    this->phoneNumber = phoneNumber;
};

void Member::setcredit(double credit) {
    this->credit = credit;
};

void Member::setHouse(House house) {
    this->house = house;
};

void Member::setRating(vector<int> rating) {
    this->rating = rating;
};

void Member::setComment(vector<string> comment) {
    this->comment = comment;
};
