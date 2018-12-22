#ifndef GAME_HPP
#define GAME_HPP

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QJsonObject>
#include <QJsonDocument>
#include "headers/player.h"
#include "headers/gift.h"
#include "headers/door.h"
#include "headers/chest.hpp"
#include "headers/key.h"
#include "headers/invertedfloor.h"
#include "headers/inventory.h"
#include <QDebug>
#include <QTextEdit>

namespace SceneMeasure {
    extern qint16 sceneWidth;
    extern qint16 sceneHeight;
}

//TODO: scale player in gimp and delete this
namespace Scaling {
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
    Key *_universalKey;
    Key *_levelKey;
    Inventory *_inventory;
    QTextEdit *_log;
    void loadLevel();
};

#endif // GAME_HPP
