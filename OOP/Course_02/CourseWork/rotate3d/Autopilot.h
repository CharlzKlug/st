#ifndef AUTOPILOT_H
#define AUTOPILOT_H
#include <QObject>
#include <ctime>
#include <QThread>
#include "Sleeper.h"

class Autopilot : public QObject{
    Q_OBJECT
private:
    qreal startXAngle, startYAngle, startZAngle; // Начальные углы по осям
    qreal vX, vY, vZ; // Скорость изменения угла в секунду
    bool enabled; // Запущен ли процесс
    qreal generateSpeed();
    qreal currentSeconds; // Текущее время от начала работы
    void process();
public:
    Autopilot(qreal XAngle, qreal YAngle, qreal ZAngle);
    ~Autopilot();
    void setStartAngles(qreal XAngle, qreal YAngle, qreal ZAngle);
    bool isEnabledP();
public slots:
    void start();
    void stop();
signals:
    void newAngles(qreal XAngle, qreal YAngle, qreal ZAngle);
    void finished();
};
#endif // AUTOPILOT_H
