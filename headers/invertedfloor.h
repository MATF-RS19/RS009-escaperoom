#ifndef INVERTEDFLOOR_H
#define INVERTEDFLOOR_H

#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QDebug>

class InvertedFloor : public QGraphicsPixmapItem {
public:
    InvertedFloor(QPixmap bg);
    ~InvertedFloor();
};

#endif // FLOOR_H

