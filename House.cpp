#include "House.h"

using std::string;
using std::cout;

House::House(string location = "", string description = "", vector<string> comment = {}, vector<int> rating = {}, bool occupied = false, bool listed = false)  {
    this->location = location,
    this->description = description,
    this->comment = comment;
    this->rating = rating;
    this->occupied = occupied;
    this->listed = listed;
}

int House::getAvg() {
    int totalRate;
    for(int rate : rating) {
        totalRate += rate;
    }
    return totalRate / this->rating.size();
}