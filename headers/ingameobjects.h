#ifndef INGAMEOBJECTS_H
#define INGAMEOBJECTS_H

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include <cmath>
#include <QDebug>
#include <QObject>
#include <QLineEdit>
#include "headers/player.h"
#include "headers/key.h"

//Abstarct class for all clickable objects on the scene

class InGameObjects : public QGraphicsPixmapItem {

public:
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event) = 0;
    Player *getPlayer();
    Key *getUK();
    Key *getLK();
    void setPlayer(Player *p);
    void setUK(Key *uk);
    void setLK(Key *lk);
    QLineEdit *getLog();
    void setLog(QLineEdit *l);

protected:
    explicit InGameObjects();
    ~InGameObjects();
    qreal distance();

private:
    Player *_player;
    Key *_universalKey;
    Key *_levelKey;
    QLineEdit *_log;
};

#endif // INGAMEOBJECTS_H
