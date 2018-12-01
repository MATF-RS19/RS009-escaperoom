#ifndef GAME_HPP
#define GAME_HPP

#include <QGraphicsScene>
#include <QGraphicsView>
#include "headers/player.h"
#include "headers/gift.h"
#include "headers/door.h"
#include "headers/chest.hpp"
#include <QDebug>

namespace SceneMeasure {
    extern qint16 sceneWidth;
    extern qint16 sceneHeight;
}

namespace Coordinates {
    extern qint16 giftX;
    extern qint16 giftY;
    extern qint16 closeDoorX;
    extern qint16 closeDoorY;
}

namespace Scaling {
    extern qreal giftScale;
    extern qreal playerScale;
}

class Game : public QGraphicsScene {

public:
    Game(QGraphicsView *parent);
    ~Game();
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);

private:
    QGraphicsView *_parent;
    Player *_player;
    Gift *_gift;
    Door *_door;
    Chest *_chest;
};

#endif // GAME_HPP
