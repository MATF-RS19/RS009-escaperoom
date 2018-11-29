#ifndef DOOR_H
#define DOOR_H

#include "ingameobjects.h"

namespace Coordinates {
    extern qint16 openDoorX;
    extern qint16 openDoorY;
}

class Door : public InGameObjects
{
public:
    Door(QPixmap picture);
    ~Door();
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    qreal distance();
};

#endif // DOOR_H
