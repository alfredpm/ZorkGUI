#include "zorkfinal.h"
#include "ZorkUL.h"

#include <QApplication>


Room *currentRoom;
ZorkUL game;        //Should not be there, but I don't have the time to find a clean solution

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ZorkFinal w;
    w.show();
    return a.exec();
}
