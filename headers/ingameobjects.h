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

/**
 * @brief Short description
 *
 * Description
 */
class InGameObjects : public QGraphicsPixmapItem {

public:

    /**
     * @brief       Short description
     * @param X     X description
     */
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event) = 0;

    /**
     * @brief       Short description
     * @param X     X description
     */
    Player *getPlayer();

    /**
     * @brief       Short description
     * @param X     X description
     */
    Key *getUK();

    /**
     * @brief       Short description
     * @param X     X description
     */
    Key *getLK();

    /**
     * @brief       Short description
     * @param X     X description
     */
    void setPlayer(Player *p);

    /**
     * @brief       Short description
     * @param X     X description
     */
    void setUK(Key *uk);

    /**
     * @brief       Short description
     * @param X     X description
     */
    void setLK(Key *lk);

    /**
     * @brief       Short description
     * @param X     X description
     */
    QLineEdit *getLog();

    /**
     * @brief       Short description
     * @param X     X description
     */
    void setLog(QLineEdit *l);

protected:

    /**
     * @brief       Short description
     * @param X     X description
     */
    explicit InGameObjects();

    /**
     * @brief       Short description
     * @param X     X description
     */
    ~InGameObjects();

    /**
     * @brief       Short description
     * @param X     X description
     */
    qreal distance();

private:
    Player *_player; //!<
    Key *_universalKey; //!<
    Key *_levelKey; //!<
    QLineEdit *_log; //!<
};

#endif // INGAMEOBJECTS_H
