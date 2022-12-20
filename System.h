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
#include "Admin.h"

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

    void showAllHouseByGuest(vector<House> houseList); // by guest

    void showAllHouseByMember(vector<House> houseList); // by member

    void showAllInfo(vector<Member> memberList); // by admin

    void listHouseAvailable(vector<Member> memberList, vector<House> houseList);

    void searchAllAvailableHouses(vector<Member> memberList, vector<House> houseList);

    void showMyInfo(Member member);

    void showMember();

    bool saveAllDataByNewMember(Member member); // only for new member (registration) & always be run when the program in terminated

    bool saveAllDataByExistMember(Member member); // to update information (after owner/buyer checkout) & always be run when the program in terminated

    bool saveAllDataByHouse(House house); // to update information (after owner/buyer checkout) & always be run when the program in terminated

    vector<Member> getMemberList();

    vector<House> getHouseList();

    // friend class Main;
};

#endif