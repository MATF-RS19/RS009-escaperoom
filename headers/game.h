#ifndef GAME_HPP
#define GAME_HPP

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QJsonObject>
#include <QJsonDocument>
#include "headers/player.h"
#include "headers/gift.h"
#include "headers/door.h"
#include "headers/chest.hpp"
#include "headers/key.h"
#include "headers/invertedfloor.h"
#include "headers/inventory.h"
#include "headers/stopwatch.h"
#include "headers/help.h"
#include <QDebug>
#include <QLineEdit>
#include <QLabel>
#include <QSound>
#include <QSoundEffect>
#include <QPointer>
namespace SceneMeasure {
    extern qint16 sceneWidth;
    extern qint16 sceneHeight;
}

class Game : public QGraphicsScene {

public:
    Game(QGraphicsView *parent);
    Game(QGraphicsView *parent, QString name);
    Game(QGraphicsView *parent, QString name, qint16 cl, bool uk, QString ctime);
    ~Game();
    void start(QString name);
    void quit();
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
    Player *getPlayer();
    void addToHighscore();
    void itIsTutorial();
    bool isTutorial();
    void addLog();
    void addScore();
    void addStopwatch();

private:
    QGraphicsView *_parent;
    Player *_player;
    Gift *_gift;
    Door *_door;
    Chest *_chest;
    Key *_universalKey;
    Key *_levelKey;
    Inventory *_inventory;
    QLineEdit *_log;
    QSound *_door_knock_sound = new QSound(QString(":/resources/sounds/knock_on_the_door.wav"));
    QSound *_door_opening_sound = new QSound(QString(":/resources/sounds/door_opening.wav"));
    QSound *_key_sound = new QSound(QString(":/resources/sounds/keys.wav"));
    QSoundEffect *_background_music = new QSoundEffect();
    QLabel *_score;
    QString _scoreText;
    QTime _startingTime;
    Stopwatch *_stopwatch;
    QPixmap _openChestPic;
    QPixmap _openDoorPic;
    qint32 _openDoorXCoord;
    QGraphicsPixmapItem *_saveBtn;
    QGraphicsPixmapItem *_quitBtn;
    bool _tutorial = false;
    Help *_help;
    QString _timeText = "00:00";

    void loadLevel();
};

#endif // GAME_HPP
