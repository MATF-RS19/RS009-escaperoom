#ifndef DOOR_H
#define DOOR_H

#include <QTextEdit>
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
    QTextEdit *getLog();
    void setLog(QTextEdit *l);
    bool isOpened();
    void openDoor(bool o);

private:
    QTextEdit *_log;
    bool _opened = false;
};

#endif // DOOR_H
