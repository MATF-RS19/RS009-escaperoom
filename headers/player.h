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
    void keyPressEvent(QKeyEvent *key);
    QList<Key*> keyList;
    qint16 currentLevel;
    QString playerPixmapURL = ":/resources/outfits/deadpool.png";
    InvertedFloor *_invertedfloor;
    bool checkCollision();
    QGraphicsPixmapItem* _dummy;
protected:

private:
    qreal _step = 3.0;
    qreal _doubleStep = 2 * _step;
};

#endif // PLAYER_H
