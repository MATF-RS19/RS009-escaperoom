#include "headers/puzzle.h"

Puzzle::Puzzle(QGraphicsView *parent, QGraphicsScene *scene, qint16 cl) :
    _parent(parent), _scene(scene), cLevel(cl)
{

}

qint16 Puzzle::getCl(){
    return cLevel;
}

QGraphicsView *Puzzle::getView(){
    return _parent;
}

QGraphicsScene *Puzzle::getScene(){
    return _scene;
}

void Puzzle::setPlayer(Player *p){
    _player = std::move(p);
}

void Puzzle::setLevelKey(Key *lk){
    _levelKey = std::move(lk);
}

Player *Puzzle::getPlayer(){
    return _player;
}

Key *Puzzle::getLK(){
    return _levelKey;
}

QTextEdit *Puzzle::getLog(){
    return _log;
}

void Puzzle::setLog(QTextEdit *l){
    _log = l;
}