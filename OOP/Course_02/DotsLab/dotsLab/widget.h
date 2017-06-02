#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPainter>

class Dots : public QWidget
{
    Q_OBJECT

public:
    Dots(QWidget *parent = 0);
    ~Dots();
protected:
    void paintEvent(QPaintEvent *);
};

#endif // WIDGET_H
