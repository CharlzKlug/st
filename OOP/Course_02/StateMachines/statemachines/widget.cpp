#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    this->setGeometry(100, 100, 50, 200);
    longPeriod = 1;
    shortPeriod = 1;
    QVBoxLayout* vbox = new QVBoxLayout(this);
    m_red = new LightWidget(Qt::red);
    vbox->addWidget(m_red);
    m_yellow = new LightWidget(Qt::yellow);
    vbox->addWidget(m_yellow);
    m_green = new LightWidget(Qt::green);
    vbox->addWidget(m_green);
    QPalette pal = palette();
    pal.setColor(QPalette::Background, Qt::black);
    setPalette(pal);
    setAutoFillBackground(true);
    machine = new QStateMachine;
    sred = new QState(machine);
    sredyellow = new QState(machine);
    sgreen = new QState(machine);
    sgreenyellow = new QState(machine);
    myTime = new QTime(0, 0, 0);

    timeLabel = new QLabel(myTime->toString("hh:mm:ss"));
    timeLabel->setStyleSheet("QLabel { background-color : gray; color : blue; }");

    vbox->addWidget(timeLabel);
    speedometer = new Speedometer();
    //QThread* speedometerThread = new QThread;
    //speedometer->moveToThread(speedometerThread);
    vbox->addWidget(speedometer);

    TrafficTimer* trafficTimer = new TrafficTimer();
    QThread* TTThread = new QThread;
    trafficTimer->moveToThread(TTThread);
    sred->addTransition(trafficTimer, SIGNAL(timeUp()), sredyellow);
    sred->addTransition(trafficTimer, SIGNAL(timeUp()), sredyellow);
    sredyellow->addTransition(trafficTimer, SIGNAL(timeUp()), sgreen);
    sgreen->addTransition(trafficTimer, SIGNAL(timeUp()), sgreenyellow);
    sgreenyellow->addTransition(trafficTimer, SIGNAL(timeUp()), sred);


    TrafficTimer* dayTimer = new TrafficTimer();
    QThread* dayThread = new QThread;
    dayTimer->moveToThread(dayThread);
    QSignalMapper* dayMapper = new QSignalMapper(this);
    dayMapper->setMapping(this, 1);
    QObject::connect(this, SIGNAL(secondTick()), dayMapper, SLOT(map()));
    QObject::connect(dayMapper, SIGNAL(mapped(const int &)), dayTimer,
                     SLOT(launchCountdown(const int &)));
    QObject::connect(dayTimer, SIGNAL(timeUp()), this, SLOT(increaseDayTime()));


    signalMapper = new QSignalMapper(this);
    signalMapper->setMapping(sred, longPeriod);
    signalMapper->setMapping(sredyellow, shortPeriod);
    signalMapper->setMapping(sgreen, longPeriod);
    signalMapper->setMapping(sgreenyellow, shortPeriod);
    signalMapper->setMapping(this, 1);

    QObject::connect(sred, SIGNAL(entered()), m_red, SLOT(turnOn()));
    QObject::connect(sred, SIGNAL(entered()), m_yellow, SLOT(turnOff()));
    QObject::connect(sred, SIGNAL(entered()), m_green, SLOT(turnOff()));
    QObject::connect(sred, SIGNAL(entered()), signalMapper, SLOT(map()));
    QObject::connect(sred, SIGNAL(entered()), speedometer, SLOT(stopCar()));

    QObject::connect(sredyellow, SIGNAL(entered()), m_yellow, SLOT(turnOn()));
    QObject::connect(sredyellow, SIGNAL(entered()), signalMapper, SLOT(map()));

    QObject::connect(sgreen, SIGNAL(entered()), m_green, SLOT(turnOn()));
    QObject::connect(sgreen, SIGNAL(entered()), m_red, SLOT(turnOff()));
    QObject::connect(sgreen, SIGNAL(entered()), m_yellow, SLOT(turnOff()));
    QObject::connect(sgreen, SIGNAL(entered()), signalMapper, SLOT(map()));
    QObject::connect(sgreen, SIGNAL(entered()), speedometer, SLOT(startCar()));

    QObject::connect(sgreenyellow, SIGNAL(entered()), m_yellow, SLOT(turnOn()));
    QObject::connect(sgreenyellow, SIGNAL(entered()), speedometer, SLOT(startCar()));
    QObject::connect(this, SIGNAL(launchTraffikTimer()), signalMapper, SLOT(map()));
    QObject::connect(signalMapper, SIGNAL(mapped(const int &)), trafficTimer,
                     SLOT(launchCountdown(const int &)));

    QObject::connect(dayTimer, SIGNAL(timeUp()), speedometer, SLOT(changeSpeed()));
    machine->setInitialState(sred);
    TTThread->start();
    dayThread->start();
    machine->start();
    emit secondTick();
}

Widget::~Widget()
{

}

/*
QState* Widget::createLightState(LightWidget * light, int duration, QState* parent=0)
{
    QState *lightState = new QState(parent);
    QTimer *timer = new QTimer(lightState);
    timer->setInterval(duration);
    timer->setSingleShot(true);
    QState *timing = new QState(lightState);
    QObject::connect(timing, SIGNAL(entered()), light, SLOT(turnOn()));
    QObject::connect(timing, SIGNAL(entered()), timer, SLOT(start()));
    QObject::connect(timing, SIGNAL(exited()), light, SLOT(turnOff()));
    QFinalState *done = new QFinalState(lightState);
    timing->addTransition(timer, SIGNAL(timeout()), done);
    lightState->setInitialState(timing);
    return lightState;
}
*/
void Widget::increaseDayTime()
{
    *myTime = myTime->addSecs(1);
    timeLabel->setText(myTime->toString("hh:mm:ss"));
    if (myTime->hour() == 6 && myTime->minute() == 0 && myTime->second() == 1)
    {
        QObject::connect(sgreenyellow, SIGNAL(entered()), signalMapper, SLOT(map()));
        shortPeriod = 2000;
        longPeriod = 5000;
        signalMapper->removeMappings(sred);
        signalMapper->removeMappings(sredyellow);
        signalMapper->removeMappings(sgreen);
        signalMapper->removeMappings(sgreenyellow);
        signalMapper->setMapping(sred, longPeriod);
        signalMapper->setMapping(sredyellow, shortPeriod);
        signalMapper->setMapping(sgreen, longPeriod);
        signalMapper->setMapping(sgreenyellow, shortPeriod);
        //signalMapper->setMapping(this, 1);

        emit launchTraffikTimer();
    }
    if (myTime->hour() == 0 && myTime->minute() == 0 && myTime->second() == 1)
    {
        QObject::disconnect(sgreenyellow, SIGNAL(entered()),
                            signalMapper, SLOT(map()));
        shortPeriod = 1;
        longPeriod = 1;
        signalMapper->removeMappings(sred);
        signalMapper->removeMappings(sredyellow);
        signalMapper->removeMappings(sgreen);
        signalMapper->removeMappings(sgreenyellow);
        signalMapper->setMapping(sred, longPeriod);
        signalMapper->setMapping(sredyellow, shortPeriod);
        signalMapper->setMapping(sgreen, longPeriod);
        signalMapper->setMapping(sgreenyellow, shortPeriod);
        //signalMapper->setMapping(this, 1);

    }
    emit secondTick();
}
