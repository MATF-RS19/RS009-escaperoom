#ifndef CHEST_HPP
#define CHEST_HPP

#include "headers/ingameobjects.h"
#include <QGraphicsScene>
#include <QPushButton>
#include <QObject>
#include <QGraphicsView>
#include "headers/staticpuzzle.h"

class Chest : public InGameObjects {

public:
    Chest(QPixmap picture);
    ~Chest();
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event, QGraphicsView *);

};

#endif // CHEST_HPP
