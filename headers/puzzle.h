#ifndef PUZZLE_H
#define PUZZLE_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QLineEdit>
#include <QSound>
#include "headers/player.h"
#include "headers/key.h"

class Puzzle : public QGraphicsScene {


public:
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event) = 0;
    qint16 getCl();
    QGraphicsView *getView();
    QGraphicsScene *getScene();
    void setPlayer(Player *p);
    void setLevelKey(Key *lk);
    Player *getPlayer();
    Key *getLK();
    QLineEdit *getLog();
    void setLog(QLineEdit *l);
    QSound *_fail_sound = new QSound(QString(":/resources/sounds/fail_Windows.wav"));

protected:
    explicit Puzzle(QGraphicsView *parent, QGraphicsScene *scene, qint16 cl);
    QGraphicsPixmapItem *_closeBtn;

private:
    QGraphicsView *_parent;
    QGraphicsScene *_scene;
    qint16 cLevel;
    Player *_player;
    Key *_levelKey;
    QLineEdit *_log;
};

#endif // PUZZLE_H
