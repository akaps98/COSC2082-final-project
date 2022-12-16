#ifndef SYSTEM_H_
#define SYSTEM_H_

#define FILENAME "data.dat"

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <cstring>

#include "Member.h"
#include "House.h"

using std::string;
using std::cout;
using std::cin;
using std::vector;
using std::fstream;

class System {
private:
    vector<Member> memberList;
    vector<House> houseList;

public:
    System() {};

    System(vector<Member> memberList, vector<House> houseList);

    bool loadData(); // calling data from db (always be run when the program is started)

    Member loginByMember(vector<Member> memberList, vector<House> houseList);

    void loginByAdmin();

    void showHouseByGuest(vector<House> houseList);

    void showHouseByMember();

    void showMyInfo(Member member);

    void showMember();

    bool saveAllDataByNewMember(Member member); // only for new member (registration)

    bool saveAllDataByExistMember(Member member); // to update information (after owner/buyer checkout)

    bool saveAllDataByHouse(House house); // to update information (after owner/buyer checkout)

    vector<Member> getMemberList();

    vector<House> getHouseList();

    // friend class Main;
};

#endif