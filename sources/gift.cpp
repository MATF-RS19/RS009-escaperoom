#include "headers/gift.h"

Gift::Gift() {
    setPixmap(QPixmap(":/resources/chests/box.png"));
}

Gift::~Gift() {

}

void Gift::mousePressEvent(QMouseEvent *event){
    if(event->button() == Qt::LeftButton && this->distance() < 100.0 ){
        qDebug() << "click!";
    }
    player->setFocus();
}

qreal Gift::distance(){
    qreal deltaX = this->x() - player->x();
    qreal deltaY = this->y() - player->y();
    return (std::sqrt(deltaX*deltaX+deltaY*deltaY));
}
