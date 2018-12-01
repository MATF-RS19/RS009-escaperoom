#include "headers/puzzle_1.h"

Puzzle_1::Puzzle_1(QGraphicsView *parent, QGraphicsScene *scene) :
    _parent(parent), _scene(scene)
{
    //setting background picture
    setBackgroundBrush(QImage(":/resources/levels/puzzle_1.png"));
    setSceneRect(0, 0, 1280, 720);

    //adding close button item to the scene
    _close_btn = new QGraphicsRectItem(0, 0, 50, 50);
    _close_btn->setBrush(QImage(":/resources/buttons/close_btn.png"));
    _close_btn->setFlag(QGraphicsItem::ItemIsFocusable);
    this->addItem(_close_btn);

    //adding accept button
    _acc_btn = new QGraphicsRectItem(0, 50, 50, 50);
    _acc_btn->setBrush(QImage(":/resources/buttons/enter_btn.png"));
    _acc_btn->setFlag(QGraphicsItem::ItemIsFocusable);
    this->addItem(_acc_btn);

    _answer = new QTextEdit();
    _answer->setPlaceholderText("Easy one for start \r\n Answer here");
    _answer->move(0, 400);
    this->addWidget(_answer);
}

void Puzzle_1::mousePressEvent(QGraphicsSceneMouseEvent *){
    if(_close_btn->isUnderMouse()){
        //delete current scene
        this->deleteLater();
        //raise old scene
        _parent->setScene(_scene);
    }
    if(_acc_btn->isUnderMouse()){
        //if text in EditText is correct, user will get level key
        if(this->_answer->toPlainText() == "2019"){
            player->keyList.append(this->level_key);
            qDebug() << "You got level key";
            //delete current scene
            this->deleteLater();
            //raise old scene
            _parent->setScene(_scene);
        }
        //otherwise, his/her answer will be deleted, and message will occurre
        else{
            _answer->setText("");
            _answer->setPlaceholderText("Wrong answer, try again");
        }
    }
}
