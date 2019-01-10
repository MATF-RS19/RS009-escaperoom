#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <QWidget>
#include <QTimer>
#include <QLabel>
#include <QTime>
#include <QGraphicsEffect>


#define STOPWATCH_PIXMAP_X (3)
#define STOPWATCH_PIXMAP_Y (3)
#define STOPWATCH_X (94)
#define STOPWATCH_Y (100)
#define STOPWATCH_WIDTH (100)
#define STOPWATCH_HEIGHT (30)

/**
 * @brief Short description
 *
 * Description
 */
class Stopwatch : public QLabel {
    Q_OBJECT
public:

    /**
     * @brief       Short description
     * @param X     X description
     */
    Stopwatch(QTime startingTime);

    /**
     * @brief       Short description
     * @param X     X description
     */
    QString getTime();

private slots:

    /**
     * @brief       Short description
     * @param X     X description
     */
    QString showElapsedTime();

private:
    QTime _startingTime; //!<
    QString time; //!<
};

#endif // STOPWATCH_H
