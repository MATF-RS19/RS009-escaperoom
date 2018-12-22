#include "headers/door.h"

namespace Coordinates {
    qint16 openDoorX = 265;
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
        //checking if user have level key and the door isn't alredy opened
        if(getPlayer()->keyList.contains(getLK()) && (x() > Coordinates::openDoorX+1.0)){
            qDebug() << "Door unlocked and opened using level key";
            this->setPixmap(QPixmap(":/resources/doors/open_door.png"));
            this->setX(Coordinates::openDoorX);
            getPlayer()->keyList.removeOne(getLK());
            delete getLK();
        }
        //checking if user have universal key and the door isn't alredy opened
        else if(getPlayer()->keyList.contains(getUK()) && (x() > Coordinates::openDoorX+1.0)){
            qDebug() << "Door unlocked and opened using universal key";
            this->setPixmap(QPixmap(":/resources/doors/open_door.png"));
            this->setX(Coordinates::openDoorX);
            getPlayer()->keyList.removeOne(getUK());
            delete getUK();
        }
        else if(x() > Coordinates::openDoorX-1.0 && x() < Coordinates::openDoorX+1.0){
            qDebug() << "Door already opened";
        }
        else{
            qDebug() << "Door locked, you need key";
        }
    }
}
