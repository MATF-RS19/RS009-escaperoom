#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <QWidget>
#include <QTimer>
#include <QLabel>
#include <QTime>

class Stopwatch : public QLabel {
    Q_OBJECT
public:
    Stopwatch(QTime startingTime);
    void showElapsedTime();
private:
    QTime _startingTime;
};

#endif // STOPWATCH_H
