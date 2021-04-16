#include "mainwindow.h"
#include "CommandWords.h"
#include "Room.h"
#include <QPushButton>
#include <QPixmap>
#include <QMainWindow>
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setFixedSize(1000,1000);

}

MainWindow::~MainWindow()
{
    delete ui;
}
