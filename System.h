#ifndef SYSTEM_H_
#define SYSTEM_H_

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "Member.h"
#include "House.h"

using std::string;
using std::cout;
using std::cin;
using std::vector;

class System {
private:
    vector<Member> memberList;
    vector<House> houseList;
public:
    System() {};

    System(vector<Member> memberList, vector<House> houseList);

    void memberFeatures();

    void loginByMember();

    void loginByAdmin();

    void showHouseByGuest();

    void showHouseByMember();

    void showMember();

    bool saveAllData(Member member);

    friend class Main;
};

#endif