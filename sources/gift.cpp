#include "headers/gift.h"

Gift::Gift(QPixmap pic)
{
    setPixmap(pic);
}

Gift::~Gift() {

}

void Gift::mousePressEvent(QGraphicsSceneMouseEvent *event){
    //checking mouse click and player distance from gift
    if(event->button() == Qt::LeftButton && this->distance() < 100.0 ){
        qDebug() << "You got key";
        player->keyList.push_back(key);
    }
    player->setFocus();
}

qreal Gift::distance(){
    qreal deltaX = this->x() - player->x();
    qreal deltaY = this->y() - player->y();
    return (std::sqrt(deltaX*deltaX+deltaY*deltaY));
}
