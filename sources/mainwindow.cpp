#include "headers/mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    _ui(new Ui::MainWindow)
{
    _ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete _ui;
}

void MainWindow::on_newGame_btn_clicked()
{
    _game.reset(new Game(_ui->display));
    _ui->display->setScene(_game->scene);
    this->hide();
}

void MainWindow::on_exit_btn_clicked()
{
    this->close();
}
