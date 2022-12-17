#include "Admin.h"

using std::string;
using std::cout;

Admin::Admin (string username = "", string password = "") : username(this->username), password(this->password){};

string Admin::getUsername() {
    return username;
};

string Admin::getPassword() {
    return password;
};