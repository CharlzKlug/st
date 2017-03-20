#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    this->setGeometry(100, 100, 50, 200);
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
//    m_red->setOn(true);
//    m_yellow->setOn(true);
//    m_green->setOn(true);
    QStateMachine* machine = new QStateMachine;
    QState* sred = new QState(machine);
    QState* sredyellow = new QState(machine);
    QState* sgreen = new QState(machine);
    QState* sgreenyellow = new QState(machine);
    QPushButton* button = new QPushButton;
    vbox->addWidget(button);
    sred->addTransition(button, SIGNAL(clicked()), sredyellow);
    sredyellow->addTransition(button, SIGNAL(clicked()), sgreen);
    sgreen->addTransition(button, SIGNAL(clicked()), sgreenyellow);
    sgreenyellow->addTransition(button, SIGNAL(clicked()), sred);
    QObject::connect(sred, SIGNAL(entered()), m_red, SLOT(turnOn()));
    QObject::connect(sred, SIGNAL(entered()), m_yellow, SLOT(turnOff()));
    QObject::connect(sred, SIGNAL(entered()), m_green, SLOT(turnOff()));

    QObject::connect(sredyellow, SIGNAL(entered()), m_yellow, SLOT(turnOn()));

    QObject::connect(sgreen, SIGNAL(entered()), m_green, SLOT(turnOn()));
    QObject::connect(sgreen, SIGNAL(entered()), m_red, SLOT(turnOff()));
    QObject::connect(sgreen, SIGNAL(entered()), m_yellow, SLOT(turnOff()));

    QObject::connect(sgreenyellow, SIGNAL(entered()), m_yellow, SLOT(turnOn()));


    //QObject::connect(st3, SIGNAL(exited()), m_green, SLOT(turnOff()));

    machine->setInitialState(sred);
    machine->start();
}

Widget::~Widget()
{

}

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
