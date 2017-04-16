#ifndef WIDGET_H
#define WIDGET_H


#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QPushButton>
#include <QStateMachine>
#include <QFinalState>
#include "lightwidget.h"
#include <QTimer>
#include "trafficTimer.h"
#include <QSignalMapper>
#include <QTime>

class Widget : public QWidget
{
    Q_OBJECT
private:
    QLabel * timeLabel;
    LightWidget* m_red;
    LightWidget* m_yellow;
    LightWidget* m_green;
    //QState* createLightState(LightWidget*, int, QState*);
    QTime* myTime;
    QStateMachine* machine;
    QState* sred;
    QState* sredyellow;
    QState* sgreen;
    QState* sgreenyellow;
    QSignalMapper* signalMapper;
    int longPeriod;
    int shortPeriod;
public:
    Widget(QWidget *parent = 0);
    ~Widget();
public slots:
    void increaseDayTime();
signals:
    void secondTick();
    void launchTraffikTimer();
};

#endif // WIDGET_H
