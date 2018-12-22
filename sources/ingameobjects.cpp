#include "headers/ingameobjects.h"

InGameObjects::InGameObjects(){

}

InGameObjects::~InGameObjects(){

}

qreal InGameObjects::distance(){
    qreal deltaX = this->x() - _player->x();
    qreal deltaY = this->y() - _player->y();
    return (std::sqrt(deltaX*deltaX+deltaY*deltaY));
}

Player* InGameObjects::getPlayer(){
    return _player;
}

Key* InGameObjects::getUK(){
    return _universalKey;
}

Key* InGameObjects::getLK(){
    return _levelKey;
}

void InGameObjects::setPlayer(Player *p){
    _player = std::move(p);
}

void InGameObjects::setUK(Key *uk){
    _universalKey = std::move(uk);
}

void InGameObjects::setLK(Key *lk){
    _levelKey = std::move(lk);
}

QTextEdit *InGameObjects::getLog(){
    return _log;
}

void InGameObjects::setLog(QTextEdit *l){
    _log = l;
}
