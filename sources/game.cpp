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
    parent->setBackgroundBrush(QImage(":/resources/levels/firstlevel_0_4.png"));

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

    Key *key = new Key(0);

    _gift = new Gift(QPixmap(":/resources/chests/box.png"));
    _gift->setPos(Coordinates::giftX, Coordinates::giftY);
    _gift->setScale(Scaling::giftScale);
    _gift->setFlag(QGraphicsItem::ItemIsFocusable);
    _gift->player = _player;
    _gift->key = key;
    addItem(_gift);

    _door = new Door(QPixmap(":/resources/doors/close_door_1.png"));
    _door->setPos(Coordinates::closeDoorX, Coordinates::closeDoorY);
    _door->setFlag(QGraphicsItem::ItemIsFocusable);
    _door->player = _player;
    _door->key = key;
    addItem(_door);

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
    if(_door->isUnderMouse())
        _door->mousePressEvent(event);
}

//if user press double click somewhere on the scene, player will stay in focus
void Game::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event){
    if(event->KeyPress)
        _player->setFocus();
}
