#include "item.h"

Item::Item (const string inDescription) {
    description = inDescription;
}

string Item::getShortDescription()
{
	return description;
}

string Item::getLongDescription()
{
    return " item(s), " + description + ".\n";  //longDescription attribute never defined
}

string Item::operator+(Item& combinedItem){
    return "Used "+description+" on "+ combinedItem.getShortDescription();
}
