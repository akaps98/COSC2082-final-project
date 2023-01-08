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
#include "Function.h"

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

    void showAllHouseByMember(Member member, vector<House> houseList); // by member

    void showAllInfo(vector<Member> memberList); // by admin

    Member listHouseAvailable(Member member, vector<House> houseList);

    void searchAllAvailableHouses(Member member, vector<House> houseList);

    void showMyInfo(Member member);

    void showMember();

    bool saveData(Member member);

    bool saveAllData(bool checkNewMember, vector<Member> memberList, Member member); // always be run when the program in terminated

    vector<Member> getMemberList();

    vector<House> getHouseList();

    void pushMemberList(Member member);

    void pushHouseList(House house);
};

#endif
