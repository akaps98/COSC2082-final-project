#include "System.h"

#define FILENAME "data.dat"

System::System(vector<Member> memberList = {}, vector<House> houseList = {}) {
    this->memberList = memberList;
    this->houseList = houseList;
}

bool System::saveAllData(Member member) {
    std::ofstream dataFile(FILENAME, std::ios::app);
    if(!dataFile.is_open()) {
        cout << "Fail to open the file\n";
        return false;
    }
    dataFile << member.username << "," << member.password << "," << member.phoneNumber << "," << member.credit << ",(";
    if(member.comment.size() == 0) {
        dataFile << "There is any comment yet." << "),";
    } else {
        for(string comment : member.comment) {
            dataFile << comment << ",";
        }
        dataFile << "),";
    }
    dataFile << member.getAvg() << "\n";
    dataFile << member.house.location << "," << member.house.description << ",(";
    if(member.house.comment.size() == 0) {
        dataFile << "There is any comment yet." << "),";
    } else {
        for(string comment : member.house.comment) {
            dataFile << comment << ",";
        }
        dataFile << "),";
    }
    dataFile << member.house.getAvg() << "\n";
    return true;
}