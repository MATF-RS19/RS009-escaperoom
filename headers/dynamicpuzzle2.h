#ifndef DYNAMICPUZZLE2_H
#define DYNAMICPUZZLE2_H

#define NUM_OF_ITERS (140)

#include "headers/puzzle.h"

class DynamicPuzzle2 : public Puzzle {

public:
    DynamicPuzzle2(QGraphicsView *parent, QGraphicsScene *scene, qint16 cl);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    QVector<QPair<QGraphicsPixmapItem*, qint16>> _tiles;

private:
    void initializePuzzle();
    void checkResult();
    void swapTiles(int& position, int nextPosition);
    void puzzleOver();
};
#endif // DYNAMICPUZZLE2_H
