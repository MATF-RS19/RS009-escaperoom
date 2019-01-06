#ifndef CHEST_HPP
#define CHEST_HPP

#include <QGraphicsView>
#include "headers/ingameobjects.h"
#include "headers/puzzle.h"
#include "headers/staticpuzzle.h"
#include "headers/dynamicpuzzle1.h"
#include "headers/dynamicpuzzle2.h"
/**
 * @brief Static collidable object.
 *
 * This is an ingame object which contains key for the level's door.
 * It is static, meaning that it doesn't change it's position during game.
 */
class Chest : public InGameObjects {

public:
    Chest(QPixmap picture);
    ~Chest();
    //function from super class, not implemented here, but we have function with same name and different arguments
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);
    //we needed to add main view as argument, so we can swap scenes from puzzle and game
    void mousePressEvent(QGraphicsSceneMouseEvent *event, QGraphicsView *);
    bool isOpened();
    void openChest(bool o);

private:
    bool _opened = false; //!< Checks if the player has solved the puzzle
};

#endif // CHEST_HPP
