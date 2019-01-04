#include "headers/game.h"

namespace SceneMeasure {
    qint16 sceneWidth = 1280;
    qint16 sceneHeight = 720;
}

static qint16 endGame = 6;

Game::Game(QGraphicsView *parent, QString name) :
           _parent(parent)
{

    _player = new Player(name);
    addItem(_player);
    addItem(_player->getDummy());
    qDebug() << _player->getUsername();
    //Universal key
    _universalKey = new Key(0, QPixmap(":/resources/inventory/universal_key.png"));
    loadLevel();
}

Game::Game(QGraphicsView *parent, QString name, qint16 cl, bool uk) :
            _parent(parent)
{
    _player = new Player(name);
    addItem(_player);
    addItem(_player->getDummy());
    //Universal key
    _universalKey = new Key(0, QPixmap(":/resources/inventory/universal_key.png"));
    _player->setCurrentLevel(cl);
    if(uk){
        _player->keyList.push_back(_universalKey);
        _universalKey->setPos(1150, 80);
        _universalKey->setZValue(5);
        this->addItem(_universalKey);
    }
    loadLevel();
}

Game::~Game(){

}

void Game::loadLevel(){
    //setting background music
    _background_music->setSource(QUrl("qrc:/resources/sounds/background.wav"));
    _background_music->setLoopCount(QSoundEffect::Infinite);
    _background_music->setVolume(0.4);
    _background_music->play();

    QFile qf;
    //reading json file, depends on level
    QString levelJson = ":/resources/levels_json/level_" + QString::number(_player->getCurrentLevel()) + ".json";
    qf.setFileName(levelJson);
    qDebug() << levelJson;
    qf.open(QIODevice::ReadOnly | QIODevice::Text);
    QJsonDocument qjd = QJsonDocument::fromJson(qf.readAll());
    qf.close();

    //background of scene
    setBackgroundBrush(QImage(qjd["background"].toString()));

    //Key for current level
    _levelKey = new Key(_player->getCurrentLevel(), QPixmap(":/resources/inventory/level_key.png"));

    //Log for the user
    _log = new QTextEdit();
    //frame size
    _log->setFixedSize(500, 50);
    //frame position
    _log->move(5, 655);
    //text size
    _log->setFontPointSize(15.0);
    //text backgroung color
    _log->setTextBackgroundColor("darkRed");
    //text color
    _log->setTextColor("yellow");
    //invisible frame
    _log->setFrameStyle(10);
    addWidget(_log);

    //_log->setText(_player->getUsername());

    _score = new QLabel();
    _score->setFont(QFont("Arial", 17, QFont::Normal));
    _score->setStyleSheet("QLabel { background-color : darkRed; color : yellow; }");
    _score->move(5, 5);
    _score->setAlignment(Qt::AlignCenter);
    _score->setFixedSize(100, 30);
    _score->setText(QString::number((_player->getCurrentLevel()-1)*10));
    addWidget(_score);
    _scoreText = _score->text();
    qDebug() << _score->text();

    _stopwatch = new Stopwatch(_startingTime);
    addWidget(_stopwatch);

    _player->setPos(SceneMeasure::sceneWidth/2, SceneMeasure::sceneHeight/2);
    //setting player ahead of gift, because first we add player to the scene, then gift, so gift's z-value is lower than player's
    _player->setZValue(5);
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
    _parent->setFrameStyle(0);
}

void Game::mousePressEvent(QGraphicsSceneMouseEvent *event){
    //gift only exist on first level
    //if user clicks on gift, keyPressEvent function from gift class will be called
    //if player already has universal key, user won't be able to open the gift again
    if(_player->getCurrentLevel()==1 && _gift->isUnderMouse() && !_gift->hasKey()){
        _gift->mousePressEvent(event);
        if(_gift->hasKey()){
            _key_sound->setLoops(1);
            _key_sound->play();
            _universalKey->setPos(1150, 80);
            _universalKey->setZValue(5);
            this->addItem(_universalKey);
        }
    }
    //If user clicks on door, keyPressEvent function from door class will be called
    else if(_door->isUnderMouse()){
        //if door hasn't been opened yet, mousePressEvent from door will be called
        if(_door->pixmap() == QPixmap(":/resources/doors/close_door.png")){
            _door->mousePressEvent(event);

            //sound of door opening or knocking, as a reminder that a key is required in order to open the door
            if(_door->isOpened()){
                _door_opening_sound->setLoops(1);
                _door_opening_sound->play();
            }else{
                _door_knock_sound->setLoops(1);
                _door_knock_sound->play();
            }
        }
        //if door has already been opened, clicking on the door will get you to next level
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
                //because score is added on levelLoad
                _scoreText = QString::number(_scoreText.toInt()+10);
                //after finishing game, username and score are added to highscore file
                addToHighscore();
                //TODO: when finished, redirect to start window
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
    //If user click on chest, chest hasn't been opened yet and the user solved the puzzle, levelKey will be added to user's list and chest will open
    else if(_chest->isUnderMouse() && !_chest->isOpened() && _levelKey->shouldGetKey()){
        _chest->openChest(true);
        _player->keyList.append(_levelKey);
        _key_sound->setLoops(1);
        _key_sound->play();
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

Player *Game::getPlayer() {
    return _player;
}

//adding score from current user to highscore file
void Game::addToHighscore() {
    QFile qf("../RS009-escaperoom/resources/highscores.txt");
    if(qf.open(QIODevice::Append)){
        QTextStream out(&qf);
        //BUG _score->text() return ""
        out << '\n' << _player->getUsername() << " " << _scoreText;
    }

    qf.close();
}
