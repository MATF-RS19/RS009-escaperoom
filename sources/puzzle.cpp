#include "headers/puzzle.h"

Puzzle::Puzzle(QGraphicsView *parent, QGraphicsScene *scene, qint16 cl) :
    cLevel(cl), _parent(parent), _scene(scene)
{

    loadPuzzle();

    //adding close button item to the scene
    _closeBtn = new QGraphicsRectItem(1100, 0, 100, 100);
    _closeBtn->setBrush(QImage(":/resources/buttons/close_btn.png"));
    _closeBtn->setFlag(QGraphicsItem::ItemIsFocusable);
    this->addItem(_closeBtn);

    //adding accept button
    _accBtn = new QGraphicsRectItem(0, 0, 100, 100);
    _accBtn->setBrush(QImage(":/resources/buttons/accept_btn.png"));
    _accBtn->setFlag(QGraphicsItem::ItemIsFocusable);
    this->addItem(_accBtn);

}

/*
IDEA for this puzzle, TODO
When user put right answer in some of boxes, set background color of that box to green
*/

void Puzzle::loadPuzzle(){
    QFile qf;
    //reading json file, depends on level
    QString levelPuzzleJson = ":/resources/puzzles_json/puzzle_" + QString::number(cLevel) + ".json";
    qf.setFileName(levelPuzzleJson);
    qDebug() << levelPuzzleJson;
    qf.open(QIODevice::ReadOnly | QIODevice::Text);
    QJsonDocument qjd = QJsonDocument::fromJson(qf.readAll());

    //setting background picture
    setBackgroundBrush(QImage(qjd["background"].toString()));
    setSceneRect(0, 0, 1280, 720);

    //getting array with answers
    QJsonArray answersJsonObject = qjd["answers"].toArray();
    QJsonArray answerPositionX = qjd["aPositionX"].toArray();
    QJsonArray answerPositionY = qjd["aPositionY"].toArray();
    //number of answers
    _ansNum = answersJsonObject.size();
    //setting two vectors to right size
    _answers.resize(_ansNum);
    _rightAnswers.resize(_ansNum);

    for(int i = 0; i < _ansNum; i++){
        //making _ansNum TextEdit fields
        _answers[i] = new QTextEdit();
        _answers[i]->move(answerPositionX.at(i).toString().toInt(), answerPositionY.at(i).toString().toInt());
        _answers[i]->setFixedSize(QSize(200, 90));
        _answers[i]->setPlaceholderText("Answer");
        this->addWidget(_answers[i]);
        //putting right answers in our vector
        _rightAnswers[i] = new QString(answersJsonObject.at(i).toString());
    }

}

void Puzzle::mousePressEvent(QGraphicsSceneMouseEvent *){
    if(_closeBtn->isUnderMouse()){
        //delete current scene
        this->deleteLater();
        //raise old scene
        _parent->setScene(_scene);
    }
    if(_accBtn->isUnderMouse()){
        //if answers in EditText fields are correct, user will get level key
        bool correct = true;
        for(int i = 0; i < _ansNum; i++){
            if(_answers.at(i)->toPlainText().toLower() != _rightAnswers.at(i)){
                correct = false;
                break;
            }
        }
        if(correct == true){
            player->keyList.append(this->level_key);
            qDebug() << "You got level key";
            //delete current scene
            this->deleteLater();
            //raise old scene
            _parent->setScene(_scene);
        }
        //otherwise, his/her answer will be deleted, and message will occurre
        else{
            for(int i = 0; i < _ansNum; i++){
                //only incorrect answers will be deleted
                if(_answers[i]->toPlainText() != _rightAnswers[i]){
                    _answers[i]->setText("");
                    _answers[i]->setPlaceholderText("Wrong answer, try again");
                }
            }
        }
    }
}
