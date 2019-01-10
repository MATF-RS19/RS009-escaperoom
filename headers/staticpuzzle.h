#ifndef STATICPUZZLE_H
#define STATICPUZZLE_H

#include <QGraphicsRectItem>
#include <QTextEdit>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include "headers/puzzle.h"
#include <QSound>

/**
 * @brief Short description
 *
 * Description
 */
class StaticPuzzle : public Puzzle {
public:

    /**
     * @brief       Short description
     * @param X     X description
     */
    StaticPuzzle(QGraphicsView *parent, QGraphicsScene *scene, qint16 cl);

    /**
     * @brief       Short description
     * @param X     X description
     */
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

private:
    QGraphicsPixmapItem *_accBtn; //!<
    QVector<QTextEdit*> _answers; //!<
    qint32 _ansNum; //!<
    QVector<QString*> _rightAnswers; //!<
    QVector<QString*> _answerPositionsX; //!<
    QVector<QString*> _answerPositionsY; //!<
    /**
     * @brief       Short description
     * @param X     X description
     */
    void loadPuzzle();
};

#endif // PUZZLE_1_H
