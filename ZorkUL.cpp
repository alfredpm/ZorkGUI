#include <iostream>
#include <QtWidgets>

using namespace std;
#include "ZorkUL.h"
#include "zorkfinal.h"

//int main(int argc, char *argv[]) {
//	ZorkUL temp;
//    QApplication app(argc,argv);
//    ZorkFinal GUI_Handler;
//    GUI_Handler.show();
//	temp.play();
//    return app.exec();
//}

ZorkUL::ZorkUL() {
    createRooms();
    createCharacters();     //to include in create rooms?
}

void ZorkUL::createRooms()  {
    Room *a, *b, *c, *d, *e, *f, *g, *h, *i, *j;    //Added room W2

	a = new Room("a");
        a->addItem(new MoveableItem("x", 1, 11));
        a->addItem(new MoveableItem("y", 2, 22));
        a->addItem(new MoveableItem("knife",2,22,0,10));
	b = new Room("b");
        b->addItem(new MoveableItem("xx", 3, 33));
        b->addItem(new MoveableItem("yy", 4, 44));
	c = new Room("c");
	d = new Room("d");
	e = new Room("e");
	f = new Room("f");
	g = new Room("g");
	h = new Room("h");
	i = new Room("i");
    j = new Room("j");                  //Added room W2
        j->addItem(new FixedItem("Secret"));       //Added item W3

//             (N, E, S, W)
	a->setExits(f, b, d, c);
	b->setExits(NULL, NULL, NULL, a);
	c->setExits(NULL, a, NULL, NULL);
	d->setExits(a, e, NULL, i);
	e->setExits(NULL, NULL, NULL, d);
    f->setExits(j, g, a, h);
	g->setExits(NULL, NULL, NULL, f);
	h->setExits(NULL, f, NULL, NULL);
    i->setExits(NULL, d, NULL, NULL);
    j->setExits(NULL, NULL, f, NULL);

    //Necesseray stuff to create a locked door from room f to j, with a key in room a, it's bulky but it does the job
    MoveableItem* secretKey=new MoveableItem("SecretKey");
    a->addItem(secretKey);
    FixedItem* secretDoor=new FixedItem("SecretDoor");
    f->addItem(secretDoor);
    Combination* secretLock=new Combination(secretKey, secretDoor, true, true, false);  //1&2 are the key and the door, 3 : starts locked, 4 : can be unlocked and locked at will, 5 : nothing is lost in the process
    addCombination(secretLock);
    f->setLocks(secretLock, NULL, NULL, NULL);


    currentRoom = a;
}

void ZorkUL::createCharacters() {
    mainChar = new Character("You are the hero of this story.");
}

/**
 *  Main play routine.  Loops until end of play.
 */
void ZorkUL::play() {
	printWelcome();

	// Enter the main command loop.  Here we repeatedly read commands and
	// execute them until the ZorkUL game is over.
	bool finished = false;
	while (!finished) {
        cout << endl << currentRoom->longDescription() << endl;
		// Create pointer to command and give it a command.
		Command* command = parser.getCommand();
		// Pass dereferenced command and check for end of game.
		finished = processCommand(*command);
		// Free the memory allocated by "parser.getCommand()"
		//   with ("return new Command(...)")
		delete command;
	}
	cout << endl;
	cout << "end" << endl;
}

void ZorkUL::printWelcome() {
	cout << "start"<< endl;
	cout << "info for help"<< endl;
	cout << endl;
}

/**
 * Given a command, process (that is: execute) the command.
 * If this command ends the ZorkUL game, true is returned, otherwise false is
 * returned.
 */
bool ZorkUL::processCommand(Command command) {
	if (command.isUnknown()) {
		cout << "invalid input"<< endl;
		return false;
	}

	string commandWord = command.getCommandWord();
	if (commandWord.compare("info") == 0)
		printHelp();

	else if (commandWord.compare("map") == 0)
		{
        cout << "        [j]        " << endl;
        cout << "         |         " << endl;
        cout << "         |         " << endl;
        cout << "[h] --- [f] --- [g]" << endl;
		cout << "         |         " << endl;
        cout << "         |         " << endl;
		cout << "[c] --- [a] --- [b]" << endl;
		cout << "         |         " << endl;
		cout << "         |         " << endl;
		cout << "[i] --- [d] --- [e]" << endl;
		}

	else if (commandWord.compare("go") == 0)
		goRoom(command);

    else if (commandWord.compare("take") == 0)
        takeItem(command);

    else if (commandWord.compare("put") == 0)
        putItem(command);

    else if (commandWord.compare("use") == 0)
        useItem(command);

    else if (commandWord.compare("attack") == 0){
        attackEntity(command);

    }
    else if (commandWord.compare("quit") == 0) {
        if (command.hasSecondWord())
            cout << "overdefined input"<< endl;
        else
			return true; /**signal to quit*/
	}
	return false;
}
/** COMMANDS **/
void ZorkUL::printHelp() {
	cout << "valid inputs are; " << endl;
	parser.showCommands();

}

void ZorkUL::goRoom(Command command) {
	if (!command.hasSecondWord()) {
		cout << "incomplete input"<< endl;
		return;
	}

	string direction = command.getSecondWord();

	// Try to leave current room.
	Room* nextRoom = currentRoom->nextRoom(direction);

	if (nextRoom == NULL)
		cout << "underdefined input"<< endl;
	else {
        if (currentRoom->isLocked(direction)){
            cout << "You can't access this room, the way is blocked." << endl;
        } else {
            currentRoom = nextRoom;
        }
	}
}
/*
string ZorkUL::go(string direction) {
	//Make the direction lowercase
	//transform(direction.begin(), direction.end(), direction.begin(),:: tolower);
	//Move to the next room
	Room* nextRoom = currentRoom->nextRoom(direction);
	if (nextRoom == NULL)
		return("direction null");
	else
	{
		currentRoom = nextRoom;
		return currentRoom->longDescription();
	}
}
*/
void ZorkUL::takeItem(Command command) {
    if (!command.hasSecondWord()) {
        cout << "incomplete input"<< endl;
        return;
    }
    else if (command.hasSecondWord()) {         //Unnecessary test?
        if ((currentRoom->isItemInRoom(command.getSecondWord())==-1)){
            cout << "This is not in the room." <<endl;
        } else {
            Item* rmItem=currentRoom->takeItemFromRoom(command.getSecondWord());
            mainChar->addItem(rmItem);
        }
    }
}

void ZorkUL::putItem(Command command){
    if (!command.hasSecondWord()) {
        cout << "incomplete input"<< endl;
        return;
    }
    else if (command.hasSecondWord()) {         //Unnecessary test?
        if ((mainChar->hasItem(command.getSecondWord()))==-1){
            cout << "You don't have that in your inventory." <<endl;
        } else {
            currentRoom->addItem(mainChar->dropItem(command.getSecondWord()));
        }
    }

}

void ZorkUL::useItem(Command command){          //Use item on everything in the room, not ideal but will do the trick
    if (!command.hasSecondWord()) {
        cout << "incomplete input"<< endl;
        return;
    }
    //Verify there is the item close by (inventory or room)
    else if (command.hasSecondWord()){
        Item* usedItem;
        if ((mainChar->hasItem(command.getSecondWord()))!=-1){
            usedItem=mainChar->getItem(mainChar->hasItem(command.getSecondWord()));
            //cout << usedItem->getShortDescription()+" is used."<<endl;
        } else if ((currentRoom->isItemInRoom(command.getSecondWord()))!=-1){
            usedItem=currentRoom->getItem(currentRoom->isItemInRoom(command.getSecondWord()));
            //cout << usedItem->getShortDescription()+" is used."<<endl;
        } else {
            cout << "There is no "+command.getSecondWord()+" near you." << endl;
            return;
        }
        //Check for combination with every item IN THE ROOM, not the inventory
        bool success=false;
        for (int n = currentRoom->numberOfItems()-1; n>=0; n--){
            Item* tempItem = currentRoom->getItem(n);
            for (int x = combinations.size()-1; x>=0; x--){
                Combination* tempComb=getCombination(x);
                if (tempComb==0){cout << "Error in getComb";}
                if (tempComb->usesBoth(usedItem,tempItem)){
                    success=true;
                    cout << (*usedItem)+(*tempItem) +"."<<endl;
                    currentRoom->addItem(tempComb->onCombine());        //Combines the two items, may unlock stuff, may create new item, etc.
                                                                        //addItem does nothing if no item is created
                }
            }
        }
        if (!success)
            cout << *usedItem <<" can't be used with anything."<<endl;
    }
}

void ZorkUL::attackEntity(Command command){
    if (!command.hasSecondWord()) {
        cout << "incomplete input, specify a target"<< endl;
        return;
    }
    else if (command.hasSecondWord()){
        if ((currentRoom->isEnemyInRoom(command.getSecondWord()))!=-1){
            //cout << "You attack "+command.getSecondWord()+" !" << endl;
            //currentRoom->getEnemy(currentRoom->isEnemyInRoom(command.getSecondWord()))->takeDamage(mainChar->damage);
            currentRoom->getEnemy(currentRoom->isEnemyInRoom(command.getSecondWord()))->takeDamage(mainChar->getDamage());
        } else {
            cout << "There is no "+command.getSecondWord()+" near you." << endl;
        }
    }

}

void ZorkUL::addCombination(Combination* combPtr){
    if (combPtr!=0){
        combinations.push_back(combPtr);
        //cout << "Just added " + inItem->getShortDescription()+ " to the room." << endl;
    } //Else could throw a custom exception.
}

Combination* ZorkUL::getCombination(int index){
    if (index>-1){
        int combSize=(int)combinations.size();
        if (index<combSize){
            return combinations[index];
        }
    }
    return 0;
}
