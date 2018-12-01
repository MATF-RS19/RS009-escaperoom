#include "headers/game.h"

namespace SceneMeasure {
    qint16 sceneWidth = 1280;
    qint16 sceneHeight = 720;
}

namespace Coordinates {
    qint16 giftX = 575;
    qint16 giftY = 255;
    qint16 closeDoorX = 355;
    qint16 closeDoorY = 215;
}

namespace Scaling {
    qreal giftScale = 0.04;
    qreal playerScale = 0.03;
}

Game::Game(QGraphicsView *parent) :
           _parent(parent)
{
    //background of scene
    setBackgroundBrush(QImage(":/resources/levels/firstlevel_0_4.png"));

    _player = new Player();
    _player->setPos(SceneMeasure::sceneWidth/2, SceneMeasure::sceneHeight/2);
    //setting player ahead of gift, because first we add player to the scene, then gift, so gift's z-value is lower than player's
    _player->setZValue(5);
    _player->setScale(Scaling::playerScale);
    //enabling keyboard inputs
    _player->setFlag(QGraphicsItem::ItemIsFocusable);
    //focusing item, so it can catch keyboard inputs
    _player->setFocus();
    addItem(_player);

    //Universal key
    Key *key = new Key(0);
    //Key for level1
    Key *key_1 = new Key(1);

    _gift = new Gift(QPixmap(":/resources/chests/box.png"));
    _gift->setPos(Coordinates::giftX, Coordinates::giftY);
    _gift->setScale(Scaling::giftScale);
    _gift->setFlag(QGraphicsItem::ItemIsFocusable);
    _gift->player = _player;
    _gift->universal_key = key;
    addItem(_gift);

    _door = new Door(QPixmap(":/resources/doors/close_door_1.png"));
    _door->setPos(Coordinates::closeDoorX, Coordinates::closeDoorY);
    _door->setFlag(QGraphicsItem::ItemIsFocusable);
    _door->player = _player;
    _door->universal_key = key;
    _door->level_key = key_1;
    addItem(_door);

    //this item, just for now
    _chest = new Chest(QPixmap(":/resources/chests/chest_1.png"));
    _chest->setPos(606, 563);
    _chest->setFlag(QGraphicsItem::ItemIsFocusable);
    _chest->setScale(0.2);
    _chest->player = _player;
    _chest->level_key = key_1;
    addItem(_chest);

    //setting scene, setting origin in top, left corner, size to 1280x720
    setSceneRect(0, 0, SceneMeasure::sceneWidth, SceneMeasure::sceneHeight);
    //setting fixed size of scene + a little adjusment to height
    parent->setFixedSize(SceneMeasure::sceneWidth, SceneMeasure::sceneHeight+15);
}

Game::~Game(){

}

void Game::mousePressEvent(QGraphicsSceneMouseEvent *event){
    //if user click on gift, keyPressEvent function from gift class will be called
    if(_gift->isUnderMouse())
        _gift->mousePressEvent(event);
    //If user click on door, keyPressEvent function from door class will be called
    if(_door->isUnderMouse()){
        //if door hasn't been opened yet, mousePressEvent from door will be called
        if(_door->pixmap() == QPixmap(":/resources/doors/close_door_1.png")){
            _door->mousePressEvent(event);
        }
        //if door is already open, clicking on the door will get you to (TODO) next level
        else{
            this->deleteLater();
        }
    }
    //If user click on chest, keyPressEvent function from chest class will be called
    if(_chest->isUnderMouse()){
        _chest->mousePressEvent(event, this->_parent);
    }
}

//if user press double click somewhere on the scene, player will stay in focus
void Game::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event){
    if(event->KeyPress)
        _player->setFocus();
}
