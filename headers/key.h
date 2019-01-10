#ifndef KEY_H
#define KEY_H

#include <QGraphicsPixmapItem>

//Class that will be subclass of Colectable items, for now just object that have id

/**
 * @brief Short description
 *
 * Description
 */
class Key : public QGraphicsPixmapItem
{
public:

    /**
     * @brief       Short description
     * @param X     X description
     */
    Key(qint16 id, QPixmap bg);

    /**
     * @brief       Short description
     * @param X     X description
     */
    ~Key();

    /**
     * @brief       Short description
     * @param X     X description
     */
    bool shouldGetKey();

    /**
     * @brief       Short description
     * @param X     X description
     */
    void setKeyAvailability(bool k);

private:
    qint16 _id; //!<
    bool _getKey = false; //!<
};

#endif // KEY_H
