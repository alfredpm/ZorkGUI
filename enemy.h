#ifndef ENEMY_H
#define ENEMY_H

#include <string>
#include <iostream>
#include "Character.h"
using namespace std;


class Enemy
    /*  COULD BE A SUPERCLASS OF CHARACTER ?
            They share a lot of functions and attributes.
            Change the name to "entity", add a field to dictate "team"
                OR
        COULD INHERIT FROM A SUPERCLASS SHARED WITH CHARACTER ?
            Same reasoning.
    */
{
private :
    string description;
    int damage;
    int health;
public:
    Enemy(const string descriptionIn, int damageIn, int healthIn);
    Enemy(string descriptionIn);

    string getDescription();

    int getDamage();
    void setDamage(int damageIn);
    int getHealth();
    void setHealth(int healthIn);
    int attack(Character* target);
    int takeDamage(int damageReceived);
};

#endif // ENEMY_H
