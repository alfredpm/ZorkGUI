#ifndef CHARACTER_H_
#define CHARACTER_H_
#include "item.h"
#include "moveableItem.h"
//#include "ZorkUL.h"   //would be necessary for friendship, causes circular dependencies

#include <string>
using namespace std;
#include <vector>
using std::vector;

class Character {
private:
	string description;

    vector < Item* > itemsInCharacter;
    int health;
    int damage;
public:

    //Inventory Management
    void addItem(Item *inItem);
    Item* getItem(int index);
    int hasItem(string inString);
    Item* dropItem(string inString);
    //Health Management
    void setHealth(int healthIn);
    void setDamage(int damageIn);
    int getDamage();
    int takeDamage(int damageIn);


public:
	Character(string description);
    ~Character();
    string shortDescription();      //Inline ?
	string longDescription();

    //friend void ZorkUL::attackEntity(Command command);   //Last attempt at friendship
                                                           // Friendship with any function just generates a ton of circular dependencies, it's hell, I have spent too much time on this already.
};

#endif /*CHARACTER_H_*/
