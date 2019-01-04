#ifndef SPRITE_H
#define SPRITE_H
#include <QPixmap>

class Sprite {
public:
    Sprite();
    ~Sprite();
    QPixmap nextSprite();
    QPixmap startingSprite();
    void addSprite(const QString spriteName);

private:
    QVector<QPixmap> _spritesheet;
    int _current = 0;
};

#endif // SPRITE_H
