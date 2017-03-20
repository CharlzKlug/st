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
class Widget : public QWidget
{
    Q_OBJECT
private:
    QLabel * timeLabel;
    LightWidget* m_red;
    LightWidget* m_yellow;
    LightWidget* m_green;
    QState* createLightState(LightWidget*, int, QState*);
public:
    Widget(QWidget *parent = 0);
    ~Widget();
};

#endif // WIDGET_H
