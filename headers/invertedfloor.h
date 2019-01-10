#ifndef INVERTEDFLOOR_H
#define INVERTEDFLOOR_H

#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QDebug>

/**
 * @brief Short description
 *
 * Description
 */
class InvertedFloor : public QGraphicsPixmapItem {
public:

    /**
     * @brief       Short description
     * @param X     X description
     */
    InvertedFloor(QPixmap bg);

    /**
     * @brief       Short description
     * @param X     X description
     */
    ~InvertedFloor();
};

#endif // FLOOR_H

