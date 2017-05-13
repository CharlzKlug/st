#include "speedometer.h"

Speedometer::Speedometer()
{
    currentAngle = 4.19;
    //currentAngle = 1.05;
    isIncreased = false;
}

Speedometer::~Speedometer()
{

}

void Speedometer::paintEvent(QPaintEvent * )
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setBrush(Qt::white);
    painter.drawEllipse(0, 0, width(), height());
    painter.setBrush(Qt::blue);
    int xc = width()/2;
    int yc = height()/2;
    int r = width()*3/4;
    painter.drawLine(xc, yc, r*cos(currentAngle)+xc, -r*sin(currentAngle)+yc);
}

void Speedometer::changeSpeed()
{
    double someAngle;
    if (isIncreased) someAngle = -0.001;
    else someAngle = + 0.01;
    currentAngle += someAngle;
    if (currentAngle < 1.05) currentAngle = 1.05;
    if (currentAngle > 4.19) currentAngle = 4.19;
    this->repaint();
}

/*
void Speedometer::stopStart()
{
    isIncreased = !isIncreased;
}
*/

void Speedometer::stopCar()
{
    isIncreased = false;
}

void Speedometer::startCar()
{
    isIncreased = true;
}
/*
void Speedometer::increaseAngle(double someAngle)
{
    currentAngle += someAngle;
}

void Speedometer::decreaseAngle(double someAngle)
{
    currenct
}
*/
