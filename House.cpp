#include "House.h"

using std::string;
using std::cout;

House::House(string location = "", string description = "", vector<int> rating = {}, vector<string> comment = {}, bool occupied = false, bool listed = false)  {
    this->location = location,
    this->description = description,
    this->rating = rating;
    this->comment = comment;
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

void House::changeOccupied() {
    if(occupied == true) {
        occupied = false;
    } else {
        occupied = true;
    }
}

void House::changeListed() {
    if(listed == true) {
        listed = false;
    } else {
        listed = true;
    }
}

// getter

string House::getLocation() {
    return location;
}

string House::getDescription() {
    return description;
}

vector<int> House::getRating() {
    return rating;
}

vector<string> House::getComment() {
    return comment;
}

bool House::getOccupied() {
    return occupied;
};

bool House::getListed() {
    return listed;
};

// setter

void House::setLocation(string location) {
    this->location = location;
};

void House::setDescription(string description) {
    this->description = description;
};

void House::setRating(vector<int> rating) {
    this->rating = rating;
};

void House::setComment(vector<string> comment) {
    this->comment = comment;
};

void House::setOccupied(bool occupied) {
    this->occupied = occupied;
};

void House::setListed(bool listed) {
    this->listed = listed;
};