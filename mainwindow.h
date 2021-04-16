#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QMainWindow>
#include <QApplication>

QT_BEGIN_NAMESPACE
namespace Ui{class MainWindow;}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
private:
    Ui::MainWindow *ui;
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


};

#endif // MAINWINDOW_H
