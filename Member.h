#ifndef MEMBER_H_
#define MEMBER_H_

#include <iostream>
#include <vector>
#include <string>

#include "House.h"

using std::string;
using std::cout;
using std::vector;

class Member {
private:   
    string username;
    string password;
    string phoneNumber;
    double credit;
    House house;
    vector<string> comment;
    vector<int> rating;
    //vector<Member> contractDone;

public:
    Member() {};

    Member(string username, string password, string phoneNumber, double credit, House house, vector<string> comment, vector<int> rating);

    Member registration();

    int getAvg();

    string getPassword();

    friend class System;
};

#endif