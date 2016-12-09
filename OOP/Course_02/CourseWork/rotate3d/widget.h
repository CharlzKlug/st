#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPainter>
#include <math.h>
#include <QPushButton>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QSlider>
#include <QLabel>
#include "Object3D.h"
#include "Autopilot.h"

class Widget : public QWidget
{
    Q_OBJECT
private:
    QSlider * aroundZSlider;
    QLabel * zAngleLabel;

    QSlider * aroundXSlider;
    QLabel * xAngleLabel;

    QSlider * aroundYSlider;
    QLabel * yAngleLabel;

    Object3D * object3d;
    QPushButton * autoPilotButton;
    Autopilot * myAutopilot;
    QThread * myThread;
    bool autopilotIsEnabled;
public:
    Widget(QWidget *parent = 0);
    void paintEvent(QPaintEvent *);
    ~Widget();
public  slots:
    void sliderZchanged(int value);
    void sliderXchanged(int value);
    void sliderYchanged(int value);
    void buttonAutopilotPressed();
    void autopilotDatas(qreal XAngle,
                        qreal YAngle,
                        qreal ZAngle);
    void anglesChanged(qreal, qreal, qreal);
};

#endif // WIDGET_H
