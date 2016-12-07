#include "Autopilot.h"

Autopilot::Autopilot(qreal XAngle, qreal YAngle, qreal ZAngle){
    std::srand(std::time(0) * 29);
    startXAngle = XAngle;
    startYAngle = YAngle;
    startZAngle = ZAngle;
    vX = generateSpeed();
    vY = generateSpeed();
    vZ = generateSpeed();
    currentSeconds = 0;
    enabled = false;
}

Autopilot::~Autopilot(){}

qreal Autopilot::generateSpeed(){

    return std::rand() * 3.14 / RAND_MAX-1.57;
}

void Autopilot::start(){
    enabled = true;
    process();
}

void Autopilot::stop(){
    enabled = false;
}

void Autopilot::process(){
    while (enabled){
        Sleeper::msleep(100);
        //QThread::msleep(100);
        currentSeconds += 0.1;
        emit newAngles(vX*currentSeconds + startXAngle,
                       vY*currentSeconds + startYAngle,
                       vZ*currentSeconds + startZAngle);
    }
    emit finished();
}

bool Autopilot::isEnabledP(){
    return enabled;
}

void Autopilot::setStartAngles(qreal XAngle, qreal YAngle, qreal ZAngle){
    startXAngle = XAngle;
    startYAngle = YAngle;
    startZAngle = ZAngle;
}
