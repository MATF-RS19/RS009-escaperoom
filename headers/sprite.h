#ifndef SPRITE_H
#define SPRITE_H
#include <QPixmap>

/**
 * @brief Short description
 *
 * Description
 */
class Sprite {
public:

    /**
     * @brief       Short description
     * @param X     X description
     */
    Sprite();

    /**
     * @brief       Short description
     * @param X     X description
     */
    ~Sprite();

    /**
     * @brief       Short description
     * @param X     X description
     */
    QPixmap nextSprite();

    /**
     * @brief       Short description
     * @param X     X description
     */
    QPixmap startingSprite();

    /**
     * @brief       Short description
     * @param X     X description
     */
    void addSprite(const QString spriteName);

private:
    QVector<QPixmap> _spritesheet; //!<
    int _current = 0; //!<
};

#endif // SPRITE_H
