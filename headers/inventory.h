#ifndef INVENTORY_H
#define INVENTORY_H

#include "headers/ingameobjects.h"
#include <QGraphicsScene>
#include <QPushButton>
#include <QObject>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>

/**
 * @brief Short description
 *
 * Description
 */
class Inventory : public QGraphicsPixmapItem {

public:

    /**
     * @brief       Short description
     * @param X     X description
     */
    Inventory(QPixmap picture);


    /**
     * @brief       Short description
     * @param X     X description
     */
    ~Inventory();

    /**
     * @brief       Short description
     * @param X     X description
     */
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

};

#endif // INVENTORY_H
