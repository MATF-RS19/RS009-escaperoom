#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <cmath>
#include <QDebug>

class Player : public QGraphicsPixmapItem {

public:
    Player();
    ~Player();
    void keyPressEvent(QKeyEvent *key);

private:
    qreal step = 3.0;
    qreal doubleStep = 2 * step;
};

#endif // PLAYER_H
