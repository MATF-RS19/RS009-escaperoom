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
        //checking if user have level key for the door and the door is not alredy opened
        if(player->keyList.contains(level_key) && (x() > Coordinates::openDoorX+1.0)){
            qDebug() << "Door unlocked and opened using level key";
            this->setPixmap(QPixmap(":/resources/doors/open_door_1.png"));
            this->setX(Coordinates::openDoorX);
            player->keyList.removeOne(level_key);
        }
        //checking if user have universal key and the door is not alredy opened
        else if(player->keyList.contains(universal_key) && (x() > Coordinates::openDoorX+1.0)){
            qDebug() << "Door unlocked and opened using universal key";
            this->setPixmap(QPixmap(":/resources/doors/open_door_1.png"));
            this->setX(Coordinates::openDoorX);
            player->keyList.removeOne(universal_key);
        }
        else if(x() > Coordinates::openDoorX-1.0 && x() < Coordinates::openDoorX+1.0){
            qDebug() << "Door already opened";
        }
        else{
            qDebug() << "Door locked, you need key";
        }
    }
}
