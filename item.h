#ifndef ITEM_H_
#define ITEM_H_

#include <map>
#include <string>
#include <iostream>
using namespace std;

class Item {
protected:                          //Accessible to subclasses, no use for now, may be usefull later
	string description;
	string longDescription;

public:
    Item (string description);
    virtual ~Item() {};             //Necessary in order to call subclasses destructor
	string getShortDescription();
    string getLongDescription();
    virtual bool tryMove() = 0;     //pure virtual makes class abstract
    string operator+(Item& combinedItem);

    friend ostream& operator<<(ostream& os, const Item& it);

};

inline ostream& operator<<(ostream& os, const Item& it){
    os << it.description;
    return os;
}

#endif /*ITEM_H_*/
