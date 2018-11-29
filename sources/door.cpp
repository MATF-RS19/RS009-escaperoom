#include "headers/door.h"

namespace Coordinates {
    qint16 openDoorX = 305;
    qint16 openDoorY = 215;
}

Door::Door(QPixmap picture)
{
    setPixmap(picture);
}

Door::~Door(){

}

void Door::mousePressEvent(QGraphicsSceneMouseEvent *event){
    //checking mouse click and player distance from the door
    if(event->button() == Qt::LeftButton && this->distance() < 150.0){
        //checking if user have key for the door
        if(player->keyList.contains(key)){
            qDebug() << "Door unlocked and opened";
            this->setPixmap(QPixmap(":/resources/doors/open_door_1.png"));
            this->setX(Coordinates::openDoorX);
            player->keyList.removeOne(key);
        }
        else{
            qDebug() << "Door locked, you need key";
        }
    }
}

qreal Door::distance(){
    qreal deltaX = this->x() - player->x();
    qreal deltaY = this->y() - player->y();
    return (std::sqrt(deltaX*deltaX+deltaY*deltaY));
}
