#ifndef GIFT_H
#define GIFT_H

#include "ingameobjects.h"



/**
 * @brief Short description
 *
 * Description
 */
class Gift : public InGameObjects {

public:

    /**
     * @brief       Short description
     * @param X     X description
     */
    Gift(QPixmap picture);

    /**
     * @brief       Short description
     * @param X     X description
     */
    ~Gift();

    /**
     * @brief       Short description
     * @param X     X description
     */
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

    /**
     * @brief       Short description
     * @param X     X description
     */
    bool hasKey();

private:
    bool _gotKey = false; //!<
};

#endif // GIFT_H
