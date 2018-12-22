#ifndef INVENTORY_H
#define INVENTORY_H

#include "headers/ingameobjects.h"
#include <QGraphicsScene>
#include <QPushButton>
#include <QObject>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>

class Inventory : public QGraphicsPixmapItem {

public:
    Inventory(QPixmap picture);
    ~Inventory();
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

};

#endif // INVENTORY_H
