#ifndef MITEM_H_
#define MITEM_H_
#include "item.h"
//#include "Character.h"
//#include "enemy.h"

#include <map>
#include <string>
#include <iostream>
using namespace std;


//class Enemy;
class Character;
class MoveableItem : public Item {
private:
    int weight;
	float value;
    bool weaponCheck;
    int weaponDamage;

public:
    MoveableItem(const string inDescription, int inWeight, float inValue, bool isWeapon=0, int inWeaponDamage=0);
    MoveableItem(string description);
    int getWeight();
    void setWeight(int weight);
	float getValue();
	void setValue(float value);
	int getWeaponCheck();
	void setWeaponCheck(int weaponCheck);
    bool tryMove();

    //friend class Character;
};

#endif /*MITEM_H_*/
