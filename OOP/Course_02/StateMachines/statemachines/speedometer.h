#ifndef SPEEDOMETER_H
#define SPEEDOMETER_H

#include <QWidget>
#include <QPainter>
//#include <QObject>

class Speedometer : public QWidget
{
    Q_OBJECT
private:
    double currentAngle;
public:
    Speedometer();
    ~Speedometer();
    void increaseAngle();
    void decreaseAngle();
protected:
    void paintEvent(QPaintEvent *);
};
#endif // SPEEDOMETER_H
