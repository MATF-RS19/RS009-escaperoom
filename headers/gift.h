#ifndef GIFT_H
#define GIFT_H

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include "headers/player.h"
#include <cmath>
#include <QKeyEvent>

class Gift : public QGraphicsPixmapItem {

public:
    Gift();
    ~Gift();
    void mousePressEvent(QMouseEvent *event);
    qreal distance();
    Player *player;
};

#endif // GIFT_H
