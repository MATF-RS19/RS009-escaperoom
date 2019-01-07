#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <QWidget>
#include <QTimer>
#include <QLabel>
#include <QTime>
#include <QGraphicsEffect>

class Stopwatch : public QLabel {
    Q_OBJECT
public:
    Stopwatch(QTime startingTime);
    QString getTime();

private slots:
    QString showElapsedTime();

private:
    QTime _startingTime;
    QString time;
};

#endif // STOPWATCH_H
