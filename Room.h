#ifndef ROOM_H_
#define ROOM_H_

#include <map>
#include <string>
#include <vector>
#include "item.h"
#include "enemy.h"
#include "combination.h"
using namespace std;
using std::vector;

//class Enemy;        //Forward declaration, I can't pinpoint why I need these, it breaks a circular dependency
class Room {

private:
	string description;
	map<string, Room*> exits;
    map<string, Combination*> locks;
    string exitString();
    vector <Item*> itemsInRoom;
    vector <Enemy*> enemiesInRoom;

public:
    Room(string description);
    string shortDescription();
    string longDescription();
    //Movement management
    void setExits(Room *north, Room *east, Room *south, Room *west);
    Room* nextRoom(string direction);
    void setLocks(Combination* north, Combination* east, Combination* south, Combination* west);
    bool isLocked(string direction);
    //Inventory management
    int numberOfItems();
    void addItem(Item *inItem);
    string displayItem();
    int isItemInRoom(string inString);
    Item* takeItemFromRoom(string inString);
    Item* getItem(int index);
    //Entity management
    int numberOfEnemies();
    void addEnemy(Enemy* inEnemy);
    int isEnemyInRoom(string inString);
    Enemy* getEnemy(int index);
};

#endif /*ROOM_H_*/
