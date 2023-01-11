#ifndef MEMBER_H_
#define MEMBER_H_

#define FILENAME "data.dat"

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "House.h"
#include "Function.h"
#include "Request.h"

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
    Member *houseOwner = nullptr;
    string ownerName;

public:
    Member() {};

    Member(string username, string password, string phoneNumber, double credit, House house, vector<int> rating, vector<string> comment, string ownerName, bool occupy);

    Member registration(vector<Member> memeberList);

    int getAvg();
    Request rq;

    // getter
    void checkOut(Member &owner); // Occupier will be notified and will be ask to give house rating, comments (Di will do it); empty the owner request and change the occupy value
//    //RIght here the homeowner will be asked to rate the occupier and comment him (Di will do it).
    void acceptRequest(vector<Member> &test); // Both view and accept

    void ratingOccupier(Member &occupier);

    void changeHouseOccupied();

    string getusername();

    string getphoneNumber();

    double getcredit();

    string getPassword();

    House getHouse();

    vector<int> getRating();

    vector<string> getComment();

    bool getOccupy();

    Member getHouseOwner();

    string getOwnerName();

    // setter

    void setusername(string username);

    void setPassword(string password);

    void setphoneNumber(string phoneNumber);

    void setcredit(double credit);

    void setHouse(House house);

    void setRating(vector<int> rating);

    void setComment(vector<string> comment);

    void setOccupy(bool occupy);

    void setHouseOwner(Member &houseOwner);

    void setOwnerName(string ownerName);
    
    void setHouseOccupier(string occupierName);

    void setHouseRating(vector<int> ratingList);

    void setHouseComment(vector<string> commentList);

};

#endif
