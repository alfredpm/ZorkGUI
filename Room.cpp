#include "Room.h"
#include "Command.h"


Room::Room(string description) {
	this->description = description;
}

string Room::exitString() {
    string returnString = "\nexits =";
    for (map<string, Room*>::iterator i = exits.begin(); i != exits.end(); i++) //For each pointer to a room i in exits
        // Loop through map
        returnString += "  " + i->first;	// access the "first" element of the pair (direction as a string)
    return returnString;
}

string Room::shortDescription() {
    return description;
}

string Room::longDescription() {
    return "You are in the " + description + ".\n " + displayItem() + exitString();
}

void Room::setExits(Room *north, Room *east, Room *south, Room *west) {
	if (north != NULL)
		exits["north"] = north;
	if (east != NULL)
		exits["east"] = east;
	if (south != NULL)
		exits["south"] = south;
	if (west != NULL)
		exits["west"] = west;
}

Room* Room::nextRoom(string direction) {
	map<string, Room*>::iterator next = exits.find(direction); //returns an iterator for the "pair"
	if (next == exits.end())
		return NULL; // if exits.end() was returned, there's no room in that direction.
	return next->second; // If there is a room, remove the "second" (Room*)
				// part of the "pair" (<string, Room*>) and return it.
}

void Room::setLocks(Combination *north, Combination *east, Combination *south, Combination *west){
    if (north != NULL)
        locks["north"] = north;
    if (east != NULL)
        locks["east"] = east;
    if (south != NULL)
        locks["south"] = south;
    if (west != NULL)
        locks["west"] = west;
}

bool Room::isLocked(string direction){
    map<string, Combination*>::iterator lock = locks.find(direction);
    if (lock == locks.end()){
        return false;
    }
    return lock->second->getFlag();
}

void Room::addItem(Item *inItem) {
    if (inItem!=0){
        itemsInRoom.push_back(inItem);
        //cout << "Just added " + inItem->getShortDescription()+ " to the room." << endl;
    } //Else could throw an exception.

}

string Room::displayItem() {
    string tempString = "items in room = ";
    int sizeItems = (itemsInRoom.size());
    if (itemsInRoom.size() < 1) {
        tempString = "no items in room";
        }
    else if (itemsInRoom.size() > 0) {
       int x = (0);
        for (int n = sizeItems; n > 0; n--) {
            tempString = tempString + itemsInRoom[x]->getShortDescription() + "  " ;
            x++;
            }
        }
    return tempString;
    }

int Room::numberOfItems() {
    return itemsInRoom.size();
}

int Room::isItemInRoom(string inString)
{
    int sizeItems = (itemsInRoom.size());
    if (itemsInRoom.size() < 1) {
        return false;
        }
    else if (itemsInRoom.size() > 0) {
        int x = 0;
        for (int n = sizeItems; n > 0; n--) {
            // compare inString with short description
            int tempFlag = inString.compare( itemsInRoom[x]->getShortDescription());
            if (tempFlag == 0) {
                //itemsInRoom.erase(itemsInRoom.begin()+x); //Remove the item when found
                return x;
            }
            x++;
            }
        }
    return -1;
}

Item* Room::takeItemFromRoom(string inString){
    int x = this->isItemInRoom(inString);
    if (x>-1){
        Item* retItem=itemsInRoom[x];
        if (retItem->tryMove()){
            itemsInRoom.erase(itemsInRoom.begin()+x);         //Item not destroyed, only the pointer, may lead to memory leak if the returned pointer is not assigned
            cout << "You  take " + inString + "."<< endl;
            return retItem;
        }
    }
    return 0;
}

Item* Room::getItem(int index){
    if (index>-1){
        if(index<(int)itemsInRoom.size()){
            return itemsInRoom[index];
        }
    }
    return 0;
}

//Entity management
int Room::numberOfEnemies(){
    return enemiesInRoom.size();
}

void Room::addEnemy(Enemy* inEnemy){
    enemiesInRoom.push_back(inEnemy);
}

int Room::isEnemyInRoom(string inString){
    int sizeEnemy = (enemiesInRoom.size());
    if(enemiesInRoom.size() < 1){
        return false;
    }
    else if(enemiesInRoom.size() > 0){
        int x = 0;
        for(int n = sizeEnemy;n > 0;n--){
            int tempFlag = inString.compare(enemiesInRoom[x]->getDescription());
            if(tempFlag == 0){
                return x;
            }
            x++;
        }
    }
    return -1;
}

Enemy* Room::getEnemy(int index){
    if(index>-1){
        if(index<(int)enemiesInRoom.size()){
            return enemiesInRoom[index];
        }
    }
    return 0;
}
