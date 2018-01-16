#include "Autopilot.h"

Autopilot::Autopilot(){
    enabled = false;
    paused = false;
}

Autopilot::~Autopilot(){
    // Деструктор автопилота
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
            Sleeper::msleep(1);
            emit tick();}
        else Sleeper::msleep(100);
    }
    emit finished();
}
