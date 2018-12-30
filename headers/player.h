#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <cmath>
#include <QDebug>
#include "headers/key.h"
#include "headers/invertedfloor.h"
class Player : public QGraphicsPixmapItem {

public:
    Player();
    ~Player();
    QList<Key*> keyList;
    void keyPressEvent(QKeyEvent *key);
    qint16 getCurrentLevel();
    InvertedFloor *getInvertedFloor();
    QGraphicsPixmapItem *getDummy();
    void setCurrentLevel(qint16 cl);
    void setInvertedFloor(InvertedFloor *iFloor);
    void setDummy(QGraphicsPixmapItem *dummy);
private:
    qreal _step = 3.0;
    qreal _doubleStep = 2 * _step;
    qint16 _currentLevel;
    InvertedFloor *_invertedfloor;
    QGraphicsPixmapItem* _dummy;

    QPixmap _ld = QPixmap(":/resources/outfits/ld.png");
    QPixmap _lu = QPixmap(":/resources/outfits/lu.png");
    QPixmap _rd = QPixmap(":/resources/outfits/rd.png");
    QPixmap _ru = QPixmap(":/resources/outfits/ru.png");

    bool checkCollision();
};

#endif // PLAYER_H
