#ifndef GAME_HPP
#define GAME_HPP

#include <QGraphicsView>
#include "headers/player.h"
#include "headers/gift.h"
#include <QMouseEvent>

class Game : public QGraphicsView {

public:
    Game(QGraphicsView *parent);
    ~Game();
    void mousePressEvent(QMouseEvent *event);
    void mouseDoubleClickEvent(QMouseEvent *event);
    QGraphicsScene *scene;

private:
    Player *player;
    Gift *gift;

    qint16 sceneWidth = 1280;
    qint16 sceneHeight = 720;
};

#endif // GAME_HPP
