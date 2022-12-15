#ifndef ADMIN_H_
#define ADMIN_H_

#include <iostream>

using std::string;
using std::cout;

class Admin {
private:
    string username = "group7";
    string password = "tony1234";

public:
    Admin(string username, string password);
};

#endif