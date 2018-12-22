#ifndef DYNAMICPUZZLE1_H
#define DYNAMICPUZZLE1_H

#include "headers/puzzle.h"

//help for mousePressEvent function
enum ItemPosition{ island1, island2, boat };

namespace Coordinates {
    extern qint16 boatIsland1X;
    extern qint16 boatIsland1Y;
    extern qint16 boatIsland2X;
    extern qint16 boatIsland2Y;

    extern qint16 wolfIsland1X;
    extern qint16 wolfIsland1Y;
    extern qint16 wolfIsland2X;
    extern qint16 wolfIsland2Y;

    extern qint16 goatIsland1X;
    extern qint16 goatIsland1Y;
    extern qint16 goatIsland2X;
    extern qint16 goatIsland2Y;

    extern qint16 lettuceIsland1X;
    extern qint16 lettuceIsland1Y;
    extern qint16 lettuceIsland2X;
    extern qint16 lettuceIsland2Y;
}

class DynamicPuzzle1 : public Puzzle{

public:
    DynamicPuzzle1(QGraphicsView *parent, QGraphicsScene *scene, qint16 cl);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

private:
    QGraphicsPixmapItem *_boat;
    QGraphicsPixmapItem *_goat;
    QGraphicsPixmapItem *_wolf;
    QGraphicsPixmapItem *_lettuce;
    qint16 _numberOfItemsOnTheBoat = 1;
    qint8 _boatIsland = 1;
    ItemPosition _wolfPosition = island1;
    ItemPosition _goatPosition = island1;
    ItemPosition _lettucePosition = island1;
    void checkForEating(qint16 boatIslandNumber);
    void puzzleOver();
    void checkForWinning();
};

#endif // DYNAMICPUZZLE1_H
