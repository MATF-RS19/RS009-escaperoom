#include "headers/ingameobjects.h"

InGameObjects::InGameObjects(){

}

InGameObjects::~InGameObjects(){

}

qreal InGameObjects::distance(){
    qreal deltaX = this->x() - player->x();
    qreal deltaY = this->y() - player->y();
    return (std::sqrt(deltaX*deltaX+deltaY*deltaY));
}
