#include "headers/player.h"

Player::Player() {
    setPixmap(QPixmap(":/resources/outfits/deadpool.png"));
}

Player::~Player(){

}

void Player::keyPressEvent(QKeyEvent *event){
    switch (event->key()) {
     case Qt::Key_A:
        if(x() > 300){
            setPos(x()-doubleStep,y()-step);
            //qDebug() << x() << y();
        }
        break;
     case Qt::Key_D:
        if(x() < 1000){
            setPos(x()+doubleStep,y()+step);
            //qDebug() << x() << y();
        }
        break;
     case Qt::Key_W:
        if(y() > 150){
            setPos(x()+doubleStep,y()-step);
            //qDebug() << x() << y();
        }
        break;
     case Qt::Key_S:
        if(y() < 600){
            setPos(x()-doubleStep,y()+step);
            //qDebug() << x() << y();
        }
        break;
    }
}
