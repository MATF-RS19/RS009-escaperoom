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
        //if player already have universal key, user won't be able to open gift again
        if(!player->keyList.contains(universal_key)){
            qDebug() << "You got universal key";
            player->keyList.push_back(universal_key);
        }
    }
    player->setFocus();
}
