#include "Member.h"

using std::string;
using std::cout;
using std::cin;

Member::Member (string username = "", string password = "", string phoneNumber = "", double credit = 500.0, House house = House(), vector<string> comment = {}, vector<int> rating = {}) {
    this->username = username,
    this->password = password,
    this->phoneNumber = phoneNumber;
    this->credit = credit;
    this->house = house;
    this->comment = comment;
    this->rating = rating;
}

Member Member::registration() {
    cout << "Enter your username: ";
    string inputUsername;
    do {
        getline(cin, inputUsername);
    } while (inputUsername == "");

    cout << "Enter your password: ";
    string inputPassword;
    do {
        getline(cin, inputPassword);
    } while (inputPassword == "");

    cout << "Enter your phone number: ";
    string inputphonenumber;
    do {
        getline(cin, inputphonenumber);
    } while (inputphonenumber == "");

    cout << "-------------------------\n";
    cout << "Enter the location of your house: ";
    string inputLocation;
    do {
        getline(cin, inputLocation);
    } while (inputLocation == "");

    cout << "Explain your house: ";
    string inputDesc;
    do {
        getline(cin, inputDesc);
    } while (inputDesc == "");

    Member newMember(inputUsername, inputPassword, inputphonenumber, 500, House(inputLocation, inputDesc, {}, {}, false, false)); 

    cout << "Registration has been done succuessfully!\n"
         << "------------------------\n";

    return newMember;
}

int Member::getAvg() {
    int totalRate;
    for(int rate : rating) {
        totalRate += rate;
    }
    return totalRate / this->rating.size();
}

string Member::getPassword() {
    return password;
}