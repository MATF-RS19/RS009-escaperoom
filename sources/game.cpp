#include "headers/game.h"

namespace SceneMeasure {
    qint16 sceneWidth = 1280;
    qint16 sceneHeight = 720;
}

namespace Scaling {
    qreal playerScale = 0.03;
}

static qint16 endGame = 4;

Game::Game(QGraphicsView *parent) :
           _parent(parent)
{

    _player = new Player();
    addItem(_player);
    addItem(_player->_dummy);
    //Universal key
    universal_key = new Key(0);

    loadLevel();

}

Game::~Game(){

}

void Game::loadLevel(){
    QFile qf;
    //reading json file, depends on level
    QString levelJson = ":/resources/levels_json/level_" + QString::number(_player->currentLevel) + ".json";
    qf.setFileName(levelJson);
    qDebug() << levelJson;
    qf.open(QIODevice::ReadOnly | QIODevice::Text);
    QJsonDocument qjd = QJsonDocument::fromJson(qf.readAll());

    //background of scene
    setBackgroundBrush(QImage(qjd["background"].toString()));

    //Key for current level
    Key *level_key = new Key(_player->currentLevel);

    _player->setPos(SceneMeasure::sceneWidth/2, SceneMeasure::sceneHeight/2);
    //setting player ahead of gift, because first we add player to the scene, then gift, so gift's z-value is lower than player's
    _player->setZValue(5);
    _player->setScale(Scaling::playerScale);
    //enabling keyboard inputs
    _player->setFlag(QGraphicsItem::ItemIsFocusable);
    //focusing item, so it can catch keyboard inputs
    _player->setFocus();

    //setting position for player's dummy object and adding (25,100), so that dummy will be by his legs
    _player->_dummy->setPos(SceneMeasure::sceneWidth/2+25, SceneMeasure::sceneHeight/2+100);

    //adding object so we can trace player not to got over edges of room
    _player->_invertedfloor = new InvertedFloor();
    addItem(_player->_invertedfloor);

    QJsonObject giftJsonObject = qjd["gift"].toObject();
    if(giftJsonObject["on_scene"].toBool()){
        _gift = new Gift(QPixmap(giftJsonObject["pixmap"].toString()));
        _gift->setPos(giftJsonObject["x_pos"].toInt(), giftJsonObject["y_pos"].toInt());
        _gift->setFlag(QGraphicsItem::ItemIsFocusable);
        _gift->player = _player;
        _gift->universal_key = universal_key;
        addItem(_gift);
    }

    QJsonObject doorJsonObject = qjd["door"].toObject();
    if(doorJsonObject["on_scene"].toBool()){
        _door = new Door(QPixmap(doorJsonObject["pixmap"].toString()));
        _door->setPos(doorJsonObject["x_pos"].toInt(), doorJsonObject["y_pos"].toInt());
        _door->setFlag(QGraphicsItem::ItemIsFocusable);
        _door->player = _player;
        _door->universal_key = universal_key;
        _door->level_key = level_key;
        addItem(_door);
    }

    QJsonObject chestJsonObject = qjd["chest"].toObject();
    if(chestJsonObject["on_scene"].toBool()){
        _chest = new Chest(QPixmap(chestJsonObject["pixmap"].toString()));
        _chest->setPos(chestJsonObject["x_pos"].toInt(), chestJsonObject["y_pos"].toInt());
        _chest->setFlag(QGraphicsItem::ItemIsFocusable);
        _chest->player = _player;
        _chest->level_key = level_key;
         addItem(_chest);
    }
    //setting scene, setting origin in top, left corner, size to 1280x720
    setSceneRect(0, 0, SceneMeasure::sceneWidth, SceneMeasure::sceneHeight);
    //setting fixed size of scene + a little adjusment to height
    _parent->setFixedSize(SceneMeasure::sceneWidth, SceneMeasure::sceneHeight+15);

}

void Game::mousePressEvent(QGraphicsSceneMouseEvent *event){
    //gift only exist on first level
    //if user click on gift, keyPressEvent function from gift class will be called
    if(_player->currentLevel==1 && _gift->isUnderMouse())
        _gift->mousePressEvent(event);
    //If user click on door, keyPressEvent function from door class will be called
    else if(_door->isUnderMouse()){
        //if door hasn't been opened yet, mousePressEvent from door will be called
        if(_door->pixmap() == QPixmap(":/resources/doors/close_door.png")){
            _door->mousePressEvent(event);
        }
        //if door is already open, clicking on the door will get you to next level
        else{
            //deleting every graphics item from the scene, except the player, because he won't be changed
            for(QGraphicsItem *item: this->items()){
                if(item != _player && item != _player->_dummy)
                    delete item;
            }
            _player->currentLevel++;

            //here will be goodbay window
            if(_player->currentLevel >= endGame){
                qDebug() << "Congratulations";
                exit(0);
            }

            //loading next level
            loadLevel();
        }
    }
    //If user click on chest, keyPressEvent function from chest class will be called
    else if(_chest->isUnderMouse()){
        _chest->mousePressEvent(event, this->_parent);
    }
    else{
        //qDebug() << "Click!";
    }
}

//if user press double click somewhere on the scene, player will stay in focus
void Game::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event){
    if(event->KeyPress)
        _player->setFocus();
}
