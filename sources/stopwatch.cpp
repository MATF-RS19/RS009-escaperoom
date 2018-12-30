#include <headers/stopwatch.h>

Stopwatch::Stopwatch(QTime startingTime)
    :_startingTime(startingTime)
{
    this->setFont(QFont("Arial", 17, QFont::Normal));
    this->setStyleSheet("QLabel { background-color : darkRed; color : yellow; }");
    this->move(150, 5);
    this->setAlignment(Qt::AlignCenter);
    this->setFixedSize(100, 30);
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Stopwatch::showElapsedTime);
    timer->start(1000);

}

void Stopwatch::showElapsedTime() {
    int diff = _startingTime.msecsTo(QTime::currentTime());
    QTime time = QTime(0,0,0).addMSecs(diff);
    QString text = time.toString("mm:ss");
    if ((time.second() % 2) == 0)
        text[2] = ' ';
    this->setText(text);
};
