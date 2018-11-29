#ifndef INGAMEOBJECTS_H
#define INGAMEOBJECTS_H

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include <cmath>
#include <QDebug>
#include "headers/player.h"
#include "headers/key.h"

//Abstarct class for all clickable objects on the scene

class InGameObjects : public QGraphicsPixmapItem {
public:
    InGameObjects();
    virtual ~InGameObjects();
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event) = 0;
    virtual qreal distance() = 0;
    Player *player;
    Key *key;
};

#endif // INGAMEOBJECTS_H
