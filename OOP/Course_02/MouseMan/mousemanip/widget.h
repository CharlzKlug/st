#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
#include <QString>
#include <cmath>
//#include <QTMath>

class Widget : public QWidget
{
    Q_OBJECT
private:
    int x, y, pointsCount,
    manhattanDistance, capturedPoint, corePointsCount
    ;
    QString myString;
    QPoint centPoint;
    QPoint* points;
    QPoint* corePoints;
    QPoint coreCentMass; // Центр масс ядра
    QPoint centerPoint(QPoint*, int);
    double cosBetween(QPoint, QPoint);
    int vectProduct(QPoint, QPoint);
    double getAngle(QPoint, QPoint); // Угол между центром масс и некоторой точкой
    void sortByAngle(QPoint*, int, QPoint);
    void buildCore(); // Построение ядра
    void cutCore(QPoint, QPoint); // Обрезание четырёхугольника
public:
    Widget(QWidget *parent = 0);
    ~Widget();
    void paintEvent(QPaintEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void mousePressEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    void myDraw();
};

#endif // WIDGET_H
