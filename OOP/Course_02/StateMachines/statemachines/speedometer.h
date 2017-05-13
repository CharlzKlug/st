#ifndef SPEEDOMETER_H
#define SPEEDOMETER_H

#include <QWidget>
#include <QPainter>
#include <cmath>
//#include <QObject>

class Speedometer : public QWidget
{
    Q_OBJECT
private:
    double currentAngle;
    bool isIncreased;
    //void increaseAngle(double);
    //void decreaseAngle(double);

public:
    Speedometer();
    ~Speedometer();
protected:
    void paintEvent(QPaintEvent *);
public slots:
    void changeSpeed();
    //void stopStart();
    void stopCar();
    void startCar();
};
#endif // SPEEDOMETER_H
