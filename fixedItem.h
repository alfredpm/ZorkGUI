#ifndef FITEM_H_
#define FITEM_H_

#include <map>
#include <string>
#include <iostream>
#include "item.h"
using namespace std;

class FixedItem : public Item{
private:

public:
    FixedItem(string description);
    bool tryMove();
};

#endif /*FITEM_H_*/
