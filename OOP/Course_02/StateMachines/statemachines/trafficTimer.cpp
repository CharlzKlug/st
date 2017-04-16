#include "trafficTimer.h"

// Конструктор
TrafficTimer::TrafficTimer(){

}

// Деструктор
TrafficTimer::~TrafficTimer(){}

void TrafficTimer::launchCountdown(int sleepTime){
    Sleeper::msleep(sleepTime);
    emit timeUp();
}
