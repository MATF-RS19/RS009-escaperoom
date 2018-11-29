#ifndef KEY_H
#define KEY_H

#include <QGraphicsItem>

//Class that will be subclass of Colectable items, for now just object that have id

class Key
{
public:
    Key(qint16 id);
    ~Key();

private:
    qint16 _id;
};

#endif // KEY_H
