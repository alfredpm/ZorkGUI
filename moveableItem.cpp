#include "moveableItem.h"


MoveableItem::MoveableItem (const string inDescription, int inWeight, float inValue, bool isWeapon, int inWeaponDamage)
    :Item(inDescription)
{
    //Setters are useful if we want to had restrictions to the possible values of an attribute
    setWeight(inWeight);
	value = inValue;
    setWeaponCheck(isWeapon);       //We could make a "Weapon" subclass of "MovableItem"
    weaponDamage=inWeaponDamage;
    //cout << "Created item"+this->getShortDescription();
}

MoveableItem::MoveableItem(string inDescription)
    :Item(inDescription)
{

}

void MoveableItem::setWeight(int inWeight)
{
    if (inWeight > 9999 || inWeight < 0)
       cout << "weight invalid, must be 0<weight<9999" ;
    else
       weight = inWeight;
}

void MoveableItem::setValue(float inValue)
{
    if (inValue > 9999 || inValue < 0)
       cout << "value invalid, must be 0<value<9999" ;
    else
	   value = inValue;
}

void MoveableItem::setWeaponCheck(int isWeapon)
{
    if(isWeapon > 0 || isWeapon < 0)
        weaponCheck=true;
    else
        weaponCheck=false;
}

bool MoveableItem::tryMove(){
    return true;
}
