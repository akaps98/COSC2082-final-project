#include "Member.h"

using std::string;
using std::cout;
using std::cin;

Member::Member(string username = "", string password = "", string phoneNumber = "", double credit = 500.0, House house = House(), vector<int> rating = {}, vector<string> comment = {}, string ownerName = "none", bool occupy = false)
{
    this->username = username,
    this->password = password,
    this->phoneNumber = phoneNumber;
    this->credit = credit;
    this->house = house;
    this->rating = rating;
    this->comment = comment;
    this->occupy = occupy;
    this->ownerName = ownerName;
    this->rq = Request();
    rq.name = phoneNumber;
}
void Member::checkOut(Member &owner)
{
    
        string stringRate, stringComment;
        vector<int> ratingList = owner.getHouse().getRating();
        vector<string> commentList = owner.getHouse().getComment();
        int rate;
        while (true)
        {
            cout << "Please rate the house (from -10 to 10): ";
            do
            {
                getline(cin, stringRate);
            } while (stringRate == "");

            ratingList.push_back(stoi(stringRate));
            owner.setHouseRating(ratingList);

            cout << "Please comment on the house: ";
            do
            {
                getline(cin, stringComment);
            } while (stringComment == "");

            commentList.push_back(stringComment);
            owner.setHouseComment(commentList);

            cout << "Thank you for rating and comment" << "\n";

            break;
        }

    
}

void Member::ratingOccupier(Member &occupier) {

        string stringRate, stringComment;
        vector<int> ratingList = occupier.getRating();
        vector<string>commentList = occupier.getComment();
        int rate;
        while (true)
        {
            cout << "Please rate the occupier (from -10 to 10): ";
            do
            {
                getline(cin, stringRate);
            } while (stringRate == "");

            ratingList.push_back(stoi(stringRate));
            occupier.setRating(ratingList);

            cout << "Please comment on the occupier: ";
            do
            {
                getline(cin, stringComment);
            } while (stringComment == "");

            commentList.push_back(stringComment);
            occupier.setComment(commentList);

            cout << "Thank you for rating and comment"
                 << "\n";

            break;
        }
}

void Member::acceptRequest(vector<Member> &test){ // HomeOwner perspective
    if(this->house.getOccupied()){
        cout<<"There is someone occupying the house already\n";
        return;
    }
    string stringOwnerName = this->username;
	string res("");
    string info("");
	for(Member m : test){
		if(this->phoneNumber == m.phoneNumber){
			res = m.rq.requests;
		}

	}
    for(Member m : test){
		if(res.find(m.getphoneNumber() )!= -1){
			info = info + "Average Credit is: " + std::to_string(m.getcredit()) 
            + "\n Average rating is: " + std::to_string(m.getAvg())
            + "\n Name is: " + m.getusername()
            + "\n Phone Number is: " + m.getphoneNumber() + "\n --------------------- \n";
		}

	}

    if(res == ""){
        cout<< "There is no request to your house recently!\n";
        return;
    }
	cout<<"Requests to your house are \n" + info;

	printf("Write in a phone number in that list to accept that request or write any to quit this:\n");
	string t("");
	cin>>t;
	if(res.find(t) != -1){
		for(Member &owner : test){
				if(this->phoneNumber == owner.phoneNumber){               
					owner.rq.requests = t;
				}
			}
            for(Member &occupier : test) {
                if(t == occupier.phoneNumber) {
                    occupier.setOccupy(true);
                    occupier.setOwnerName(this->username);
                    this->house.setOccupierName(occupier.getusername());
                    cout << occupier.username << ": " << occupier.ownerName << "\n"; 
                }
            }
		this->house.changeOccupied();
    
        printf("Successfully accept the request\n");
	}


}

void Member::changeHouseOccupied() {
    this->house.changeOccupied();
}


void Member::setHouseOccupier(string occupierName) {
    this->house.setOccupierName(occupierName);
}

void Member::setHouseRating(vector<int> ratingList) {
    this->house.setRating(ratingList);
}

void Member::setHouseComment(vector<string> commentList) {
    this->house.setComment(commentList);
}


Member Member::registration(vector<Member> memberList)
{
    Function func;

    string inputUsername;

    while(true) {
        cout << "Enter your username: ";
        
        do {
            getline(cin, inputUsername);
        } while (inputUsername == "");

        int check = 0;

        for(Member member : memberList) {
            if(func.toLower(inputUsername) == func.toLower(member.getusername())) {
                cout << "This username is duplicated!\n";
                cout << "Please input other username.\n";
                cout << "-------------------------\n";
                check = 1;
                break;
            }
        }

        if(check == 0) {
            break;
        }
    }

    cout << "Enter your password: ";

    string inputPassword;

    do {
        getline(cin, inputPassword);
    } while (inputPassword == "");

    string inputphonenumber;

    while(true) {
        cout << "Enter your phone number: ";
        
        do {
            getline(cin, inputphonenumber);
        } while (inputphonenumber == "");

        int check = 0;

        for(Member member : memberList) {
            if(func.toLower(inputphonenumber) == func.toLower(member.getphoneNumber())) {
                cout << "This phone number is duplicated!\n";
                cout << "Please input other phone number.\n";
                cout << "-------------------------\n";
                check = 1;
                break;
            }
        }

        if(check == 0) {
            break;
        }
    }

    string inputLocation;

    while(true) {
        cout << "-------------------------\n";
        cout << "Enter the location of your house(Ha Noi, Hue, Sai Gon): ";
        
        do {
            getline(cin, inputLocation);
        } while (inputLocation == "");

        int check = 0;

        if(func.toLower(inputLocation) == func.toLower("Ha Noi") || func.toLower(inputLocation) == func.toLower("HaNoi") || func.toLower(inputLocation) == func.toLower("Hue") || func.toLower(inputLocation) == func.toLower("Sai Gon") || func.toLower(inputLocation) == func.toLower("Saigon")) {
            if(func.toLower(inputLocation) == func.toLower("Ha Noi") || func.toLower(inputLocation) == func.toLower("HaNoi")) {
                inputLocation = "Ha Noi";
            } else if (func.toLower(inputLocation) == func.toLower("Hue")) {
                inputLocation = "Hue";
            } else if (func.toLower(inputLocation) == func.toLower("Sai Gon") || func.toLower(inputLocation) == func.toLower("Saigon")) {
                inputLocation = "Sai Gon";
            }
        } else {
            cout << "Wrong location!\n";
            cout << "You can only type among Ha Noi, Hue or Sai Gon.\n";
            check = 1;
        }

        if(check == 0) {
            break;
        }
    }

    cout << "Explain your house: ";
    string inputDesc;
    do {
        getline(cin, inputDesc);
    } while (inputDesc == "");

    Member newMember(inputUsername, inputPassword, inputphonenumber, 500, House(inputLocation, inputDesc, {}, {}, false, false, "none"));

    cout << "Registration has been done succuessfully!\n\n";

    return newMember;
}

int Member::getAvg() {
    if(rating.size() == 0) {
        return 0;
    }
    
    int totalRate = 0;
    for(int rate : rating) {

        totalRate += rate;
    }
    return totalRate / this->rating.size();
}

// getter

string Member::getPassword() {
    return password;
}

string Member::getusername() {
    return username;
}

string Member::getphoneNumber() {
    return phoneNumber;
}

double Member::getcredit() {
    return credit;
}

House Member::getHouse() {
    return this->house;
}

vector<int> Member::getRating() {
    return rating;
}

vector<string> Member::getComment() {
    return comment;
}

bool Member::getOccupy()
{
    return occupy;
}

Member Member::getHouseOwner()
{
    return *houseOwner;
}

string Member::getOwnerName()
{
    return ownerName;
}

// setter
 
void Member::setusername(string username) {
    this->username = username;
};

void Member::setPassword(string password) {
    this->password = password;
};

void Member::setphoneNumber(string phoneNumber) {
    this->phoneNumber = phoneNumber;
};

void Member::setcredit(double credit) {
    this->credit = credit;
};

void Member::setHouse(House house) {
    this->house = house;
};

void Member::setRating(vector<int> rating) {
    this->rating = rating;
};

void Member::setComment(vector<string> comment) {
    this->comment = comment;
};

void Member::setOccupy(bool occupy)
{
    this->occupy = occupy;
}

void Member::setHouseOwner(Member &houseOwner)
{
    this->houseOwner = &houseOwner;
}

void Member::setOwnerName(string ownerName)
{
    this->ownerName = ownerName;
};