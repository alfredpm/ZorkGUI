#ifndef ZORKUL_H_
#define ZORKUL_H_

//#include "Command.h"
#include "Parser.h"
#include "Room.h"
//#include "item.h"
#include "moveableItem.h"
#include "fixedItem.h"
//#include "Character.h"
//#include "enemy.h"
//#include "combination.h"
#include <iostream>
#include <string>
using namespace std;

extern Room *currentRoom;          //global variable because we need one, and I can't find anything better to globalize

//class Character;
class ZorkUL {
private:
	Parser parser;
    //Room *currentRoom;
    Character *mainChar;    //We may need an array of Character instead, with mainchar being the first
    vector<Combination*> combinations;
	void createRooms();
    void createCharacters();
	void printWelcome();
    void createItems();
    void displayItems();


    void printHelp();
    void goRoom(Command command);
    void takeItem(Command command);
    void putItem(Command command);
    void useItem(Command command);
    void attackEntity(Command command);

    void addCombination(Combination* combPtr);
    Combination* getCombination(int index);

public:
	ZorkUL();
    void play();
    bool processCommand(Command command);
    //void attackEntity(Command command);
};

#endif /*ZORKUL_H_*/
