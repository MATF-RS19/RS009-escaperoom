#ifndef DOOR_H
#define DOOR_H

#include <QLineEdit>
#include "ingameobjects.h"

namespace Coordinates {
    extern qint16 openDoorX;
    extern qint16 openDoorY;
}

class Door : public InGameObjects {

public:
    Door(QPixmap picture);
    ~Door();
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event, QPixmap pic, qint32 xCoord);
    QLineEdit *getLog();
    void setLog(QLineEdit *l);
    bool isOpened();
    void openDoor(bool o);

private:
    QLineEdit *_log;
    bool _opened = false;
};

#endif // DOOR_H
