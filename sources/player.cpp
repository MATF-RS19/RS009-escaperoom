#include "headers/player.h"
#include "headers/game.h"

Player::Player() {
    setPixmap(QPixmap(playerPixmapURL));
    currentLevel = 1;
    _dummy = new QGraphicsPixmapItem;
    _dummy->setPixmap(QPixmap(":/resources/outfits/dummy_visable.png"));
    _dummy->setPos(0,0);
}

Player::~Player(){

}

//pseudo collision, for now
void Player::keyPressEvent(QKeyEvent *event){
    switch (event->key()) {
     case Qt::Key_A:
        _dummy->setPos(x()-_doubleStep+25,y()-_step+100);
        if(checkCollision()) {
            setPos(x()-_doubleStep, y() - _step);
        }      
        break;
     case Qt::Key_D:
        _dummy->setPos(x()+_doubleStep+25,y()+_step+100);
        if(checkCollision()) {
            setPos(x()+_doubleStep,y()+_step);
        }        
        break;
     case Qt::Key_W: 
        _dummy->setPos(x()+_doubleStep+25,y()-_step+100);
        if(checkCollision()) {
            setPos(x()+_doubleStep,y()-_step);
        }
        break;
     case Qt::Key_S:
        _dummy->setPos(x()-_doubleStep+25,y()+_step+100);
        if(checkCollision()) {
            setPos(x()-_doubleStep,y()+_step);
        }
        break;
    }
}
// We're checking if there's one more collision besides collision with the player.
bool Player::checkCollision() {

    qDebug() << _dummy->x();
    qDebug() << _dummy->collidingItems().size();
    return this->_dummy->collidingItems().size() > 1 ? false : true;
}


