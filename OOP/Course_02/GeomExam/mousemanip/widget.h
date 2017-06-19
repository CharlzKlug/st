#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
#include <QString>
#include <cmath>
#include "GeometryFunctions.h"

class Widget : public QWidget
{
    Q_OBJECT
private:
    int x, y,
    manhattanDistance, capturedPoint;
    QString myString;
    QVector<QPoint> points;
    QPainter* painter;
    bool drawNumbers;
        void proc_poly(QVector<QPoint>); // Отрисовка полигона

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
