#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPainter>
#include <cmath>
#include "Sleeper.h"
#include <QTimer>
#include <QLabel>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QPushButton>

class Widget : public QWidget
{
    Q_OBJECT
private:
    int R, r, n, x, y;
    QPolygon* polygon;
    int angle;
    int angleStep; // Шаг приращения угла шатуна
    int circleAngle; // Угол поворота колеса
    QLineEdit* REdit;
    QLineEdit* NEdit;
    QLineEdit* rEdit;
    double DegreeToRadian(int);
    double RadianToDegree(double);
    bool isRotateArea(int);
    void around();
    void straightLine();
    int getRotateArea(int);
    int getTreshold(); // Пороговое значение поворота вокруг угла
    int circleRotate(int);
public:
    Widget(QWidget *parent = 0);
    ~Widget();
    void calcPolygon();
    void drawScene(int x, int y);
protected:
    void paintEvent(QPaintEvent *);
public slots:
    void onTimer();
    void newValues(); // Смена радиусов и углов
};

#endif // WIDGET_H
