#include "headers/help.h"

Help::Help(QPixmap pic)
{
    setPixmap(pic);
}

Help::~Help(){

}

void Help::mousePressEvent(QGraphicsSceneMouseEvent *){
}

//Returns a number that represents the step of tutorial we are on now
qint16 Help::currentStep(){
    return _step;
}

//Moving on to the next step of the tutorial
void Help::nextStep(){
    _step += 1;
}
