#ifndef PUZZLE_1_H
#define PUZZLE_1_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QGraphicsRectItem>
#include <QTextEdit>
#include "headers/player.h"
#include "headers/key.h"

class Puzzle_1 : public QGraphicsScene {
public:
    Puzzle_1(QGraphicsView *parent, QGraphicsScene *scene);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    Player *player;
    Key *level_key;

private:
    QGraphicsView *_parent;
    QGraphicsRectItem *_close_btn;
    QGraphicsRectItem *_acc_btn;
    QGraphicsScene *_scene;
    QTextEdit *_answer;
};

#endif // PUZZLE_1_H
