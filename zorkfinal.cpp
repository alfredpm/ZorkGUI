#include "zorkfinal.h"
#include "ui_zorkfinal.h"
#include <iostream>

ZorkFinal::ZorkFinal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ZorkFinal)
{
    ui->setupUi(this);
}

ZorkFinal::~ZorkFinal()
{
    delete ui;
}

//DO
void ZorkFinal::on_pushButton_attack_clicked()
{
    //gets target from comboBox_target
    string targetName=get_combo_target();
    //sends attack target
    Command *cmd=new Command("attack",targetName);

    delete cmd;
}

void ZorkFinal::on_pushButton_use_clicked()
{
    //gets item1 and item2 to use from comboBox_itemToUse and comboBox_itemToUseWith
    string item1Name=get_combo_itemToUse();
    string item2Name=get_combo_itemToUseWith();
    //sends use item1 item2
    Command *cmd=new Command("use",item1Name);
    cout << cmd << endl;
    delete cmd;
}

string ZorkFinal::get_combo_itemToUse(){
    //returns selected content from comboBox_itemToUse
    QString qs = ui->comboBox_itemToUse->currentText();
    return qs.toLocal8Bit().constData();
}
string ZorkFinal::get_combo_itemToUseWith(){
    //returns selected content from comboBox_itemToUseWith
    QString qs = ui->comboBox_itemToUseWith->currentText();
    return qs.toLocal8Bit().constData();
}
string ZorkFinal::get_combo_target(){
    QString qs = ui->comboBox_availableTarget->currentText();
    return qs.toLocal8Bit().constData();
}
//GO
void ZorkFinal::on_pushButton_goNorth_clicked()
{
    //sends go north
    Command *cmd=new Command("go","north");
    cout <<cmd->getCommandWord()<<cmd->getSecondWord() <<endl;
    delete cmd;
}

void ZorkFinal::on_pushButton_goWest_clicked()
{
    //sends go west
    Command *cmd=new Command("go","west");
    cout <<cmd->getCommandWord()<<cmd->getSecondWord() <<endl;
    delete cmd;
}

void ZorkFinal::on_pushButton_goSouth_clicked()
{
    //sends go south
    Command *cmd=new Command("go","south");
    cout <<cmd->getCommandWord()<<cmd->getSecondWord() <<endl;
    delete cmd;
}

void ZorkFinal::on_pushButton_goEast_clicked()
{
    //sends go east
    Command *cmd=new Command("go","east");
    cout <<cmd->getCommandWord()<<cmd->getSecondWord() <<endl;
    delete cmd;
}

//STATUS
void ZorkFinal::set_lcd_life(int currentlife){

}
void ZorkFinal::set_lcd_score(int currentScore){

}
void ZorkFinal::set_lcd_turn(int currentTurn){

}

//MAIN DISPLAY
void ZorkFinal::set_textB_desc(string message){

}
