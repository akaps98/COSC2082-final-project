#ifndef HOUSE_H_
#define HOUSE_H_

#include <iostream>
#include <vector>

using std::string;
using std::cout;
using std::vector;

class House {
private:
    string location;
    string description;
    vector<int> rating;
    vector<string> comment;
    bool occupied = false; // to check the condition (true : occupied / false : not occupied)
    bool listed = false; // to check it is on sale or not (true : it is on sale / false: not sale)
    // vector<Request> requestList;

public:
    House() {};

    House(string location, string description, vector<int> rating, vector<string> comment, bool occupied, bool listed);

    int getAvg();

    friend class System;

    void changeOccupied();

    void changeListed();

    // getter

    string getLocation();

    string getDescription();

    vector<int> getRating();

    vector<string> getComment();

    bool getOccupied();

    bool getListed();
    
    // setter

    void setLocation(string location);

    void setDescription(string description);

    void setRating(vector<int> rating);

    void setComment(vector<string> comment);

    void setOccupied(bool occupied);

    void setListed(bool listed);
};

#endif