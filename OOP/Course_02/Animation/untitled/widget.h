#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QGraphicsColorizeEffect>
#include <QPropertyAnimation>
#include <QScrollArea>
#include <QStateMachine>
#include <QTimer>

class Widget : public QWidget
{
    Q_OBJECT
private:
    QRect yellowHoriz();
    QRect blueHoriz();
public:
    Widget(QWidget *parent = 0);
    ~Widget();
};

#endif // WIDGET_H
