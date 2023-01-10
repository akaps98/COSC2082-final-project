#ifndef MEMBER_H_
#define MEMBER_H_

#define FILENAME "data.dat"

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "House.h"
#include "Function.h"

using std::string;
using std::cout;
using std::vector;
using std::fstream;

class Member {
private:   
    string username;
    string password;
    string phoneNumber;
    double credit;
    House house;
    vector<string> comment;
    vector<int> rating;
    bool occupy;

public:
    Member() {};

    Member(string username, string password, string phoneNumber, double credit, House house, vector<int> rating, vector<string> comment, bool occupy);

    Member registration(vector<Member> memeberList);

    int getAvg();

    // getter

    string getusername();

    string getphoneNumber();

    double getcredit();

    string getPassword();

    House getHouse();

    vector<int> getRating();

    vector<string> getComment();

    bool getOccupy();

    // setter

    void setusername(string username);

    void setPassword(string password);

    void setphoneNumber(string phoneNumber);

    void setcredit(double credit);

    void setHouse(House house);

    void setRating(vector<int> rating);

    void setComment(vector<string> comment);

    void setOccupy(bool occupy);
};

#endif