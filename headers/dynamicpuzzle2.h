#ifndef DYNAMICPUZZLE2_H
#define DYNAMICPUZZLE2_H

#include "headers/puzzle.h"

#define NUM_OF_ITERS (100)
#define NUM_OF_ROWS (4)
#define NUM_OF_COLS (4)
#define SCREEN_WIDTH (1280)
#define SCREEN_HEIGHT (720)
#define MOVE_VAL (151)
#define STARTING_X (337)
#define STARTING_Y (58)
#define EMPTY_TILE (15)

/**
 * @brief Short description
 *
 * Description
 */
class DynamicPuzzle2 : public Puzzle {

public:

    /**
     * @brief       Short description
     * @param X     X description
     */
    DynamicPuzzle2(QGraphicsView *parent, QGraphicsScene *scene, qint16 cl);

    /**
     * @brief       Short description
     * @param X     X description
     */
    void mousePressEvent(QGraphicsSceneMouseEvent *event);


private:

    /**
     * @brief       Short description
     * @param X     X description
     */
    void initializePuzzle();

    /**
     * @brief       Short description
     * @param X     X description
     */
    void checkResult();

    /**
     * @brief       Short description
     * @param X     X description
     */
    void swapTiles(int& position, int nextPosition);

    /**
     * @brief       Short description
     * @param X     X description
     */
    void puzzleOver();

    QVector<QPair<QGraphicsPixmapItem*, qint16>> _tiles; //!<
};
#endif // DYNAMICPUZZLE2_H
