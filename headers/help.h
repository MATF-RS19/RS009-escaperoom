#ifndef HELP_H
#define HELP_H

#include "ingameobjects.h"

class Help : public InGameObjects {

public:
    Help(QPixmap picture);
    ~Help();
    void mousePressEvent(QGraphicsSceneMouseEvent *);
    qint16 currentStep();
    void nextStep();

private:
    qint16 _step = 1;
};

#endif // HELP_H
