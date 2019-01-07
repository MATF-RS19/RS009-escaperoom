#include <headers/stopwatch.h>

Stopwatch::Stopwatch(QTime startingTime)
    :_startingTime(startingTime)
{
    this->setFont(QFont("Arial", 20, QFont::Bold));
    this->setStyleSheet("QLabel { background-color : darkRed; color : yellow; }");
    this->move(94, 100);
    this->setAlignment(Qt::AlignCenter);
    this->setFixedSize(100, 30);
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Stopwatch::showElapsedTime);
    timer->start(1000);

}

QString Stopwatch::showElapsedTime() {
    int diff = _startingTime.msecsTo(QTime::currentTime());
    QTime time = QTime(0,0,0).addMSecs(diff);
    QString text = time.toString("mm:ss");
    this->setText(text);
    return text;
};

QString Stopwatch::getTime(){
    return showElapsedTime();
}
