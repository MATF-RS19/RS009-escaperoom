#ifndef KEY_H
#define KEY_H

#include <QGraphicsPixmapItem>

//Class that will be subclass of Colectable items, for now just object that have id

class Key : public QGraphicsPixmapItem
{
public:
    Key(qint16 id, QPixmap bg);
    ~Key();
    bool shouldGetKey();
    void setKeyAvailability(bool k);

private:
    qint16 _id;
    bool _getKey = false;
};

#endif // KEY_H
