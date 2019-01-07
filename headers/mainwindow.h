#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QInputDialog>
#include "headers/game.h"

namespace Ui {
    class MainWindow;
}

/**
 * @brief Short description
 *
 * Description
 */
class MainWindow : public QMainWindow {
    Q_OBJECT

public:

    /**
     * @brief       Short description
     * @param X     X description
     */
    explicit MainWindow(QWidget *parent = nullptr);

    /**
     * @brief       Short description
     * @param X     X description
     */
    ~MainWindow();

    /**
     * @brief       Short description
     * @param X     X description
     */
    void initGUI();

    /**
     * @brief       Short description
     * @param X     X description
     */
    void newGame(QString name);

    /**
     * @brief       Short description
     * @param X     X description
     */
    void writeJson(QString name);

    /**
     * @brief       Short description
     * @param X     X description
     */
    void readJsonAndStartGame(QString name);

    /**
     * @brief       Short description
     * @param X     X description
     */
    void setAllInvisible();

private slots:

    /**
     * @brief       Short description
     * @param X     X description
     */
    void on_newGame_btn_clicked();

    /**
     * @brief       Short description
     * @param X     X description
     */
    void on_exit_btn_clicked();

    /**
     * @brief       Short description
     * @param X     X description
     */
    void on_newGameTE_textChanged();

    /**
     * @brief       Short description
     * @param X     X description
     */
    void on_loadGame_btn_clicked();

    /**
     * @brief       Short description
     * @param X     X description
     */
    void on_newGame_conf_btn_clicked();

    /**
     * @brief       Short description
     * @param X     X description
     */
    void on_loadGame_conf_btn_clicked();

    /**
     * @brief       Short description
     * @param X     X description
     */
    void on_loadGameTE_textChanged();

    /**
     * @brief       Short description
     * @param X     X description
     */
    void on_highscore_btn_clicked();

    /**
     * @brief       Short description
     * @param X     X description
     */
    void on_tutorial_btn_clicked();

private:
    Ui::MainWindow *_ui; //!<
    Game *_game; //!<
};

#endif // MAINWINDOW_H
