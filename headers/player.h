#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <cmath>
#include <QDebug>
#include "headers/sprite.h"
#include "headers/key.h"
#include "headers/invertedfloor.h"

class Player : public QGraphicsPixmapItem {

public:
    Player(QString name);
    ~Player();
    QList<Key*> keyList;
    void keyPressEvent(QKeyEvent *key);
    qint16 getCurrentLevel();
    InvertedFloor *getInvertedFloor();
    QGraphicsPixmapItem *getDummy();
    void setCurrentLevel(qint16 cl);
    void setInvertedFloor(InvertedFloor *iFloor);
    void setDummy(QGraphicsPixmapItem *dummy);
    QString getUsername();
    void initSpriteSheets();
    void setSprite(Sprite& sprite);
private:
    qreal _step = 3.0;
    qreal _doubleStep = 2 * _step;
    qint16 _currentLevel;
    InvertedFloor *_invertedfloor;
    QGraphicsPixmapItem* _dummy;
    QString _username;
    Sprite _wSpriteSheet;
    Sprite _aSpriteSheet;
    Sprite _sSpriteSheet;
    Sprite _dSpriteSheet;

    bool checkCollision();
};

#endif // PLAYER_H
