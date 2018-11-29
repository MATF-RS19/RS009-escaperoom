#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <cmath>
#include <QDebug>
#include "headers/key.h"

class Player : public QGraphicsPixmapItem {

public:
    Player();
    ~Player();
    void keyPressEvent(QKeyEvent *key);
    QList<Key*> keyList;

protected:

private:
    qreal _step = 3.0;
    qreal _doubleStep = 2 * _step;
};

#endif // PLAYER_H
