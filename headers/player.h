#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <cmath>
#include <QDebug>
#include "headers/sprite.h"
#include "headers/key.h"
#include "headers/invertedfloor.h"

/**
 * @brief Short description
 *
 * Description
 */
class Player : public QGraphicsPixmapItem {

public:

    /**
     * @brief       Short description
     * @param X     X description
     */
    Player(QString name);

    /**
     * @brief       Short description
     * @param X     X description
     */
    ~Player();

    /**
     * @brief       Short description
     * @param X     X description
     */
    QList<Key*> keyList;

    /**
     * @brief       Short description
     * @param X     X description
     */
    void keyPressEvent(QKeyEvent *key);

    /**
     * @brief       Short description
     * @param X     X description
     */
    qint16 getCurrentLevel();

    /**
     * @brief       Short description
     * @param X     X description
     */
    InvertedFloor *getInvertedFloor();

    /**
     * @brief       Short description
     * @param X     X description
     */
    QGraphicsPixmapItem *getDummy();

    /**
     * @brief       Short description
     * @param X     X description
     */
    void setCurrentLevel(qint16 cl);

    /**
     * @brief       Short description
     * @param X     X description
     */
    void setInvertedFloor(InvertedFloor *iFloor);

    /**
     * @brief       Short description
     * @param X     X description
     */
    void setDummy(QGraphicsPixmapItem *dummy);

    /**
     * @brief       Short description
     * @param X     X description
     */
    QString getUsername();

    /**
     * @brief       Short description
     * @param X     X description
     */
    void initSpriteSheets();

    /**
     * @brief       Short description
     * @param X     X description
     */
    void setSprite(Sprite& sprite);
private:
    qreal _step = 3.0; //!<
    qreal _doubleStep = 2 * _step; //!<
    qint16 _currentLevel; //!<
    InvertedFloor *_invertedfloor; //!<
    QGraphicsPixmapItem* _dummy; //!<
    QString _username; //!<
    Sprite _wSpriteSheet; //!<
    Sprite _aSpriteSheet; //!<
    Sprite _sSpriteSheet; //!<
    Sprite _dSpriteSheet; //!<

    bool checkCollision();
};

#endif // PLAYER_H
