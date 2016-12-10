#ifndef AUTOPILOT_H
#define AUTOPILOT_H
#include <QObject>
#include <ctime>
#include <QThread>
#include "Sleeper.h"

// Класс автопилота
class Autopilot : public QObject{
    Q_OBJECT
private:
    qreal startXAngle, startYAngle, startZAngle; // Начальные углы по осям
    qreal vX, vY, vZ; // Скорость изменения угла в секунду
    bool enabled; // Запущен ли процесс
    bool paused; // Приостановлен ли процесс
    qreal generateSpeed(); // Генерация угловых скоростей
    qreal currentSeconds; // Текущее время от начала работы
    void process(); // Основной рабочий процесс автопилота
public:
    // Конструктор
    Autopilot(qreal XAngle, qreal YAngle, qreal ZAngle);

    // Деструктор
    ~Autopilot();

public slots:
    // Слот запуска процесса
    void start();

    // Слот останова процесса
    void stop();

    // Слот паузы вкл/выкл
    void pauseOnOff();
signals:

    // Сигнал с новыми углами
    void newAngles(qreal XAngle, qreal YAngle, qreal ZAngle);

    // Сигнал завершения работы автопилота
    void finished();

    // Сигнал о вставании на паузу
    void pausedSignal();
};
#endif // AUTOPILOT_H
