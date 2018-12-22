#include "headers/player.h"
#include "headers/game.h"

Player::Player() {
    setPixmap(QPixmap(":/resources/outfits/rd.png"));
    _currentLevel = 1;
    _dummy = new QGraphicsPixmapItem;
    _dummy->setPixmap(QPixmap(":/resources/outfits/dummy.png"));
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
            if(this->pixmap() != _lu){
                this->setPixmap(_lu);
            }
        }      
        break;
     case Qt::Key_D:
        _dummy->setPos(x()+_doubleStep+25,y()+_step+100);
        if(checkCollision()) {
            setPos(x()+_doubleStep,y()+_step);
            if(this->pixmap() != _rd){
                this->setPixmap(_rd);
            }
        }        
        break;
     case Qt::Key_W: 
        _dummy->setPos(x()+_doubleStep+25,y()-_step+100);
        if(checkCollision()) {
            setPos(x()+_doubleStep,y()-_step);
            if(this->pixmap() != _ru){
                this->setPixmap(_ru);
            }
        }
        break;
     case Qt::Key_S:
        _dummy->setPos(x()-_doubleStep+25,y()+_step+100);
        if(checkCollision()) {
            setPos(x()-_doubleStep,y()+_step);
            if(this->pixmap() != _ld){
                this->setPixmap(_ld);
            }
        }
        break;
    }
}
// We're checking if there's one more collision besides collision with the player.
bool Player::checkCollision() {
    return this->_dummy->collidingItems().size() > 1 ? false : true;
}


qint16 Player::getCurrentLevel(){
    return _currentLevel;
}

InvertedFloor *Player::getInvertedFloor(){
    return _invertedfloor;
}

QGraphicsPixmapItem *Player::getDummy(){
    return _dummy;
}

void Player::setCurrentLevel(qint16 cl){
    _currentLevel = cl;
}

void Player::setInvertedFloor(InvertedFloor *iFloor){
    _invertedfloor = std::move(iFloor);
}

void Player::setDummy(QGraphicsPixmapItem *dummy){
    _dummy = std::move(dummy);
}
