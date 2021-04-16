#include "fixedItem.h"

FixedItem::FixedItem(string inDescription)
    :Item(inDescription)
{

}

bool FixedItem::tryMove(){
    cout << "You can't do that." << endl;
    return false;
}
