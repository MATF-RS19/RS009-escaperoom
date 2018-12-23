#include "headers/game.h"

namespace SceneMeasure {
    qint16 sceneWidth = 1280;
    qint16 sceneHeight = 720;
}

namespace Scaling {
    qreal playerScale = 0.35;
}

static qint16 endGame = 5;

Game::Game(QGraphicsView *parent) :
           _parent(parent)
{

    _player = new Player();
    addItem(_player);
    addItem(_player->getDummy());
    //Universal key
    _universalKey = new Key(0, QPixmap(":/resources/inventory/universal_key.png"));

    loadLevel();

}

Game::~Game(){

}

void Game::loadLevel(){
    QFile qf;
    //reading json file, depends on level
    QString levelJson = ":/resources/levels_json/level_" + QString::number(_player->getCurrentLevel()) + ".json";
    qf.setFileName(levelJson);
    qDebug() << levelJson;
    qf.open(QIODevice::ReadOnly | QIODevice::Text);
    QJsonDocument qjd = QJsonDocument::fromJson(qf.readAll());

    //background of scene
    setBackgroundBrush(QImage(qjd["background"].toString()));

    //Key for current level
    _levelKey = new Key(_player->getCurrentLevel(), QPixmap(":/resources/inventory/level_key.png"));

    //Log for the user
    _log = new QTextEdit();
    //frame size
    _log->setFixedSize(500, 50);
    //frame position
    _log->move(0, 660);
    //text size
    _log->setFontPointSize(15.0);
    //text backgroung color
    _log->setTextBackgroundColor("black");
    //text color
    _log->setTextColor("green");
    //invisible frame
    _log->setFrameStyle(10);
    addWidget(_log);

    _player->setPos(SceneMeasure::sceneWidth/2, SceneMeasure::sceneHeight/2);
    //setting player ahead of gift, because first we add player to the scene, then gift, so gift's z-value is lower than player's
    _player->setZValue(5);
    _player->setScale(Scaling::playerScale);
    //enabling keyboard inputs
    _player->setFlag(QGraphicsItem::ItemIsFocusable);
    //focusing item, so it can catch keyboard inputs
    _player->setFocus();

    //setting position for player's dummy object and adding (25,100), so that dummy will be by his legs
    _player->getDummy()->setPos(SceneMeasure::sceneWidth/2+25, SceneMeasure::sceneHeight/2+100);

    //adding object so we can trace player not to got over edges of room
    _player->setInvertedFloor(new InvertedFloor(QPixmap(":/resources/levels/invertedFloor.png")));
    addItem(_player->getInvertedFloor());

    QJsonObject giftJsonObject = qjd["gift"].toObject();
    if(giftJsonObject["on_scene"].toBool()){
        _gift = new Gift(QPixmap(giftJsonObject["pixmap"].toString()));
        _gift->setPos(giftJsonObject["x_pos"].toInt(), giftJsonObject["y_pos"].toInt());
        _gift->setFlag(QGraphicsItem::ItemIsFocusable);
        _gift->setLog(_log);
        _gift->setPlayer(_player);
        _gift->setUK(_universalKey);
        addItem(_gift);
    }

    QJsonObject doorJsonObject = qjd["door"].toObject();
    if(doorJsonObject["on_scene"].toBool()){
        _door = new Door(QPixmap(doorJsonObject["pixmap"].toString()));
        _door->setPos(doorJsonObject["x_pos"].toInt(), doorJsonObject["y_pos"].toInt());
        _door->setFlag(QGraphicsItem::ItemIsFocusable);
        _door->setLog(_log);
        _door->setPlayer(_player);
        _door->setUK(_universalKey);
        _door->setLK(_levelKey);
        addItem(_door);
    }

    QJsonObject chestJsonObject = qjd["chest"].toObject();
    if(chestJsonObject["on_scene"].toBool()){
        _chest = new Chest(QPixmap(chestJsonObject["pixmap"].toString()));
        _chest->setPos(chestJsonObject["x_pos"].toInt(), chestJsonObject["y_pos"].toInt());
        _chest->setFlag(QGraphicsItem::ItemIsFocusable);
        _chest->setLog(_log);
        _chest->setPlayer(_player);
        _chest->setLK(_levelKey);
         addItem(_chest);
    }

    QJsonObject inventoryJsonObject = qjd["inventory"].toObject();
    if(inventoryJsonObject["on_scene"].toBool()){
        _inventory = new Inventory(QPixmap(inventoryJsonObject["pixmap"].toString()));
        _inventory->setPos(inventoryJsonObject["x_pos"].toInt(), inventoryJsonObject["y_pos"].toInt());
        addItem(_inventory);
    }

    //setting scene, setting origin in top, left corner, size to 1280x720
    setSceneRect(0, 0, SceneMeasure::sceneWidth, SceneMeasure::sceneHeight);
    //setting fixed size of scene + a little adjusment to height
    _parent->setFixedSize(SceneMeasure::sceneWidth, SceneMeasure::sceneHeight+17);

}

void Game::mousePressEvent(QGraphicsSceneMouseEvent *event){
    //gift only exist on first level
    //if user click on gift, keyPressEvent function from gift class will be called
    //if player already have universal key, user won't be able to open gift again
    if(_player->getCurrentLevel()==1 && _gift->isUnderMouse() && !_gift->hasKey()){
        _gift->mousePressEvent(event);
        if(_gift->hasKey()){
            _universalKey->setPos(1150, 80);
            _universalKey->setZValue(5);
            this->addItem(_universalKey);
        }
    }
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
                if(item != _player && item != _player->getDummy() && item != _universalKey)
                    delete item;
            }
            _player->setCurrentLevel(_player->getCurrentLevel()+1);

            //here will be goodbay window
            if(_player->getCurrentLevel() >= endGame){
                qDebug() << "********************************************\r\n"
                            "*****        Congratulations           *****\r\n"
                            "********************************************";
                exit(0);
            }

            //loading next level
            loadLevel();
        }
    }
    //If user click on chest, chest hasn't been opened yet and user didn't solve the puzzle yet, keyPressEvent function from chest class will be called
    else if(_chest->isUnderMouse() && !_chest->isOpened() && !_levelKey->shouldGetKey()){
        _chest->mousePressEvent(event, this->_parent);
    }
    //If user click on chest, chest hasn't been opened yet and user did solve the puzzle yet, levelKey will be added to user's list and chest will open
    else if(_chest->isUnderMouse() && !_chest->isOpened() && _levelKey->shouldGetKey()){
        _chest->openChest(true);
        _player->keyList.append(_levelKey);
        qDebug() << "You got level key";
        _log->setText("You got level key");
        _levelKey->setPos(1150, 205);
        addItem(_levelKey);
        _chest->setPixmap(QPixmap(":/resources/chests/open.png"));
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
