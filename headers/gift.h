#ifndef GIFT_H
#define GIFT_H

#include "ingameobjects.h"

class Gift : public InGameObjects {

public:
    Gift(QPixmap picture);
    ~Gift();
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

private:
    bool _gotKey = false;
};

#endif // GIFT_H
