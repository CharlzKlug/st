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
    bool enabled; // Запущен ли процесс
    bool paused; // Приостановлен ли процесс
    void process(); // Основной рабочий процесс автопилота
public:
    // Конструктор
    Autopilot();

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
    // Сигнал о новом тике
    void tick();

    // Сигнал завершения работы автопилота
    void finished();

    // Сигнал о вставании на паузу
    void pausedSignal();
};
#endif // AUTOPILOT_H
