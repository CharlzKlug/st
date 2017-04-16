#ifndef TRAFFICTIMER_H
#define TRAFFICTIMER_H

#include <QObject>
#include "Sleeper.h"

class TrafficTimer : public QObject{
    Q_OBJECT
public:

    // Конструктор
    TrafficTimer();

    // Деструктор
    ~TrafficTimer();
public slots:
    void launchCountdown(int);
signals:
    void timeUp();
};

#endif // TRAFFICTIMER_H
