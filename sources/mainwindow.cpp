#include "headers/mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    _ui(new Ui::MainWindow)
{
    _ui->setupUi(this);
}

MainWindow::~MainWindow(){
    delete _ui;
}

void MainWindow::on_newGame_btn_clicked() {

    //making new game
    _game.reset(new Game(_ui->display));
    //setting scene
    _ui->display->setScene(&(*_game));
    //setting game scene to be main scene
    _ui->display->raise();
    //setting focus on game scene
    _ui->display->setFocus();
}

void MainWindow::on_exit_btn_clicked(){
    this->close();
}
