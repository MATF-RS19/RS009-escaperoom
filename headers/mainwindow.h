#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "headers/game.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_newGame_btn_clicked();
    void on_exit_btn_clicked();

private:
    Ui::MainWindow *_ui;
    QScopedPointer<Game> _game;
};

#endif // MAINWINDOW_H
