#ifndef ZORKFINAL_H
#define ZORKFINAL_H

#include <QMainWindow>
#include <string>
#include <vector>
#include "Command.h"
using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class ZorkFinal; }
QT_END_NAMESPACE

#ifndef ZORKUL_H
#include "ZorkUL.h"
#endif //ZORKUL_H

extern ZorkUL *game;

class ZorkFinal : public QMainWindow
{
    Q_OBJECT

public:
    ZorkFinal(QWidget *parent = nullptr);
    ~ZorkFinal();

private slots:
    //DO
    void on_pushButton_attack_clicked();
    void on_pushButton_use_clicked();

    string get_combo_itemToUse();
    string get_combo_itemToUseWith();
    string get_combo_target();

    //GO
    void on_pushButton_goNorth_clicked();
    void on_pushButton_goWest_clicked();
    void on_pushButton_goSouth_clicked();
    void on_pushButton_goEast_clicked();

    //STATUS
    void set_lcd_life(int currentLife);
    void set_lcd_score(int currentScore);
    void set_lcd_turn(int currentTurn);

    //LISTS
    //template function with vector item and vector enemy
    //void set_list(vector<T*>){

    //}

    //MAIN DISPLAY
    void set_textB_desc(string message);        //mimicks cout



private:
    Ui::ZorkFinal *ui;

};
#endif // ZORKFINAL_H
