#include "Autopilot.h"

Autopilot::Autopilot(qreal XAngle,
                     qreal YAngle,
                     qreal ZAngle){
    // Конструктор автопилота
    std::srand(std::time(0) * 29);
    startXAngle = XAngle;
    startYAngle = YAngle;
    startZAngle = ZAngle;
    vX = generateSpeed();
    vY = generateSpeed();
    vZ = generateSpeed();
    currentSeconds = 0;
    enabled = false;
    paused = false;
}

Autopilot::~Autopilot(){
    // Деструктор автопилота
}

qreal Autopilot::generateSpeed(){
    // Генерация новой скорости
    return std::rand() * 3.14 / RAND_MAX-1.57;
}

void Autopilot::start(){
    // Запуск автопилота
    enabled = true;
    process();
}

void Autopilot::stop(){
    // Останов автопилота
    enabled = false;
}

void Autopilot::pauseOnOff(){
    // Пауза автопилота вкл/выкл
    if (paused) paused = false;
    else {
        paused = true;
        emit pausedSignal();
    }
}

void Autopilot::process(){
    // Основной процесс автопилота
    while (enabled){
        if (!paused){
            Sleeper::msleep(100);
            currentSeconds += 0.1;
            emit newAngles(vX*currentSeconds + startXAngle,
                           vY*currentSeconds + startYAngle,
                           vZ*currentSeconds + startZAngle);}
        else Sleeper::msleep(100);
    }
    emit finished();
}
