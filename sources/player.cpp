#include "headers/player.h"

Player::Player() {
    setPixmap(QPixmap(":/resources/outfits/deadpool.png"));
}

Player::~Player(){

}

//pseudo collision, for now
void Player::keyPressEvent(QKeyEvent *event){
    switch (event->key()) {
     case Qt::Key_A:
        if(x() > 300){
            setPos(x()-_doubleStep,y()-_step);
            //qDebug() << x() << y();
        }
        break;
     case Qt::Key_D:
        if(x() < 1000){
            setPos(x()+_doubleStep,y()+_step);
            //qDebug() << x() << y();
        }
        break;
     case Qt::Key_W:
        if(y() > 150){
            setPos(x()+_doubleStep,y()-_step);
            //qDebug() << x() << y();
        }
        break;
     case Qt::Key_S:
        if(y() < 600){
            setPos(x()-_doubleStep,y()+_step);
            //qDebug() << x() << y();
        }
        break;
    }
}
