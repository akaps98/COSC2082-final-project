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
//class Request{
//	public:
//	string name; // This member phone number is the name
//	vector<string> requests;
//};
class Member {
private:   
    string username;
    string password;
    string phoneNumber;
    double credit;
    House house;
    vector<string> comment;
    vector<int> rating;

public:
    Member() {};

    Member(string username, string password, string phoneNumber, double credit, House house, vector<int> rating, vector<string> comment);

    Member registration(vector<Member> memeberList);

    int getAvg();
    Request rq;

    // getter
    void endTrial(vector<Member> &test); // Occupier will be notified and will be ask to give house rating, comments (Di will do it); empty the owner request and change the occupy value
//    //RIght here the homeowner will be asked to rate the occupier and comment him (Di will do it).
    void acceptRequest(vector<Member> &test); // Both view and accept
    string getusername();

    string getphoneNumber();

    double getcredit();

    string getPassword();

    House getHouse();

    vector<int> getRating();

    vector<string> getComment();

    // setter

    void setusername(string username);

    void setPassword(string password);

    void setphoneNumber(string phoneNumber);

    void setcredit(double credit);

    void setHouse(House house);

    void setRating(vector<int> rating);

    void setComment(vector<string> comment);
};

#endif
