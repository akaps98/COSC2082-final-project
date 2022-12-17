#ifndef FUNCTION_H_
#define FUNCTION_H_

#include <iostream>
#include <algorithm>

using std::string;

class Function {
public:
    Function() {};

    Function(string inputName);

    string toUpper(string word);

    string toLower(string word);
};

#endif