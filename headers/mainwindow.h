#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QInputDialog>
#include "headers/game.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void newGame(QString name);
    void writeJson(QString name);
    void readJsonAndStartGame(QString name);

private slots:
    void on_newGame_btn_clicked();
    void on_exit_btn_clicked();

    void on_newGameTE_textChanged();

    void on_loadGame_btn_clicked();

    void on_newGame_conf_btn_clicked();

    void on_loadGame_conf_btn_clicked();

    void on_loadGameTE_textChanged();

    void on_highscore_btn_clicked();

private:
    Ui::MainWindow *_ui;
    QScopedPointer<Game> _game;
};

#endif // MAINWINDOW_H
