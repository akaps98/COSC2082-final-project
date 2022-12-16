#include "Function.h"

string Function::toUpper(string word) {
    transform(word.begin(), word.end(), word.begin(), toupper);
    return word;
};

string Function::toLower(string word) {
    transform(word.begin(), word.end(), word.begin(), tolower);
    return word;
};