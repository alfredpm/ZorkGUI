#include "enemy.h"

Enemy::Enemy(const string descriptionIn, int damageIn, int healthIn){
    description = descriptionIn;
    damage = damageIn;
    health = healthIn;
}

Enemy::Enemy(string descriptionIn){
    description = descriptionIn;
}

string Enemy::getDescription(){
    return description;
}

int Enemy::getDamage(){
    return damage;
}

void Enemy::setDamage(int damageIn){
    damage=damageIn;
}

int Enemy::getHealth(){
    return health;
}

void Enemy::setHealth(int healthIn){
    health=healthIn;
}

int Enemy::attack(Character* target){
    return target->takeDamage(damage);
}

int Enemy::takeDamage(int damageIn){
    health-=damageIn;
    if (health<0){
        health=0;
    }
    if (health==0){
        cout << description + " is dead." << endl;
    }
    return health;
}
