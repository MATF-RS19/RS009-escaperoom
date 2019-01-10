#ifndef PUZZLE_H
#define PUZZLE_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsSceneMouseEvent>
#include <QLayout>
#include <QDebug>
#include <QLineEdit>
#include <QSound>
#include "headers/player.h"
#include "headers/key.h"

/**
 * @brief Short description
 *
 * Description
 */
class Puzzle : public QGraphicsScene {


public:

    /**
     * @brief       Short description
     * @param X     X description
     */
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event) = 0;

    /**
     * @brief       Short description
     * @param X     X description
     */
    qint16 getCl();

    /**
     * @brief       Short description
     * @param X     X description
     */
    QGraphicsView *getView();

    /**
     * @brief       Short description
     * @param X     X description
     */
    QGraphicsScene *getScene();

    /**
     * @brief       Short description
     * @param X     X description
     */
    void setPlayer(Player *p);

    /**
     * @brief       Short description
     * @param X     X description
     */
    void setLevelKey(Key *lk);

    /**
     * @brief       Short description
     * @param X     X description
     */
    Player *getPlayer();

    /**
     * @brief       Short description
     * @param X     X description
     */
    Key *getLK();

    /**
     * @brief       Short description
     * @param X     X description
     */
    QLineEdit *getLog();

    /**
     * @brief       Short description
     * @param X     X description
     */
    void setLog(QLineEdit *l);

    QSound *_fail_sound = new QSound(QString(":/resources/sounds/fail_Windows.wav")); //!<

protected:

    /**
     * @brief       Short description
     * @param X     X description
     */
    explicit Puzzle(QGraphicsView *parent, QGraphicsScene *scene, qint16 cl);
    QGraphicsPixmapItem *_closeBtn; //!<

private:
    QGraphicsView *_parent; //!<
    QGraphicsScene *_scene; //!<
    qint16 cLevel; //!<
    Player *_player; //!<
    Key *_levelKey; //!<
    QLineEdit *_log; //!<
};

#endif // PUZZLE_H
