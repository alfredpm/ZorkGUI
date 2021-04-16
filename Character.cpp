#include "Character.h"
#include "Room.h"

extern Room* currentRoom;

Character::Character(string description) {
	this->description = description;
}

Character::~Character(){
    //On destruction drop all items in the room     //everything drops in currentRoom, the room of mainChar, in a finished game each Character would be associated to its own currentRoom
    for (int n = itemsInCharacter.size(); n>0; n--){
        currentRoom->addItem(itemsInCharacter[n]);
        itemsInCharacter.erase(itemsInCharacter.begin()+n);
    }
}

string Character::shortDescription()       //Inline ?
{
    return this->description;
}

string Character::longDescription()
{
    string ret = this->description;
    ret += "\n Item list:\n";
    for (vector<Item*>::iterator i = itemsInCharacter.begin(); i != itemsInCharacter.end(); i++)
        ret += "\t"+(*i)->getShortDescription() + "\n";
    return ret;
}

//Inventory Management

void Character::addItem(Item *inItem) {
    if (inItem!=0){
        itemsInCharacter.push_back(inItem);
        //cout << "You got " + inItem->getShortDescription() + "." <<endl;
    }//Else could throw an exception.
}

Item* Character::getItem(int index){
    if (index>-1){
        if (index<(int)itemsInCharacter.size()){
            return itemsInCharacter[index];
        }
    }
    return 0;
}

int Character::hasItem(string inString){
    int sizeItems = itemsInCharacter.size();
    if (sizeItems > 0) {
        int x = 0;
        for (int n = sizeItems; n > 0; n--) {
            // compare inString with short description
            int tempFlag = inString.compare( itemsInCharacter[x]->getShortDescription());
            if (tempFlag == 0) {
                return x;
            }
            x++;
        }
    }
    return -1;;
}
Item* Character::dropItem(string inString){
    int x = this->hasItem(inString);
    if (x>-1){
        Item* retItem=itemsInCharacter[x];                  //Copy the pointer
        if (retItem->tryMove()){
            itemsInCharacter.erase(itemsInCharacter.begin()+x); //Remove the old pointer //Item not destroyed, only the pointer, may lead to memory leak if the returned pointer is not assigned
            cout << "You drop " + inString + "." << endl;
            return retItem;                                     //Return the copy
        }
    }
    return 0;
}

//Health Management
void Character::setHealth(int healthIn){
    health=healthIn;
}

void Character::setDamage(int damageIn){
    damage=damageIn;
}

int Character::getDamage(){
    return damage;
}

int Character::takeDamage(int damageIn){    //Substracts incoming damage from health, returns remaining life
    health-=damageIn;
    if (health<0){
        health=0;
    }
    if (health==0){
        cout << shortDescription() + " is dead." << endl;
    }
    return health;
}
