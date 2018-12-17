#ifndef STATICPUZZLE_H
#define STATICPUZZLE_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QGraphicsRectItem>
#include <QTextEdit>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include "headers/player.h"
#include "headers/key.h"

class StaticPuzzle : public QGraphicsScene {
public:
    StaticPuzzle(QGraphicsView *parent, QGraphicsScene *scene, qint16 cl);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    Player *player;
    Key *level_key;
    qint16 cLevel;
    void loadPuzzle();

private:
    QGraphicsView *_parent;
    QGraphicsRectItem *_closeBtn;
    QGraphicsRectItem *_accBtn;
    QGraphicsScene *_scene;
    QVector<QTextEdit*> _answers;
    qint32 _ansNum;
    QVector<QString*> _rightAnswers;
    QVector<QString*> _answerPositionsX;
    QVector<QString*> _answerPositionsY;
};

#endif // PUZZLE_1_H
