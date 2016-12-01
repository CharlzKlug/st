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

class Widget : public QWidget
{
    Q_OBJECT
private:
    int x, y;
    QSlider * aroundZSlider;
    QLabel * zAngleLabel;
    QSlider * aroundXSlider;
    QLabel * xAngleLabel;
    QSlider * aroundYSlider;
    QLabel * yAngleLabel;

public:
    Widget(QWidget *parent = 0);
    void paintEvent(QPaintEvent *);
    ~Widget();
public  slots:
    void butPress();
    void sliderZchanged(int value);
    void sliderXchanged(int value);
    void sliderYchanged(int value);
};

#endif // WIDGET_H
