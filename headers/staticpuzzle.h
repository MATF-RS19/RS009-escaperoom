#ifndef STATICPUZZLE_H
#define STATICPUZZLE_H

#include <QGraphicsRectItem>
#include <QTextEdit>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include "headers/puzzle.h"

class StaticPuzzle : public Puzzle {
public:
    StaticPuzzle(QGraphicsView *parent, QGraphicsScene *scene, qint16 cl);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

private:
    QGraphicsRectItem *_accBtn;
    QVector<QTextEdit*> _answers;
    qint32 _ansNum;
    QVector<QString*> _rightAnswers;
    QVector<QString*> _answerPositionsX;
    QVector<QString*> _answerPositionsY;
    void loadPuzzle();
};

#endif // PUZZLE_1_H
