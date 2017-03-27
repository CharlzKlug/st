#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
#include <QString>

class Widget : public QWidget
{
    Q_OBJECT
private:
    int x, y, pointsCount, manhattanDistance, capturedPoint;
    QString myString;
    QPoint* points;
public:
    Widget(QWidget *parent = 0);
    ~Widget();
    void paintEvent(QPaintEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void mousePressEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
};

#endif // WIDGET_H
