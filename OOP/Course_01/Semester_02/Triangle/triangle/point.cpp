#include "point.h"

Point::Point(qreal xx, qreal yy): x(xx), y(yy){}

qreal Point::getX(){return x;}

qreal Point::getY(){return y;}

Point::Point() {}

Point::Point(Point& q){
    x=q.getX();
    y=q.getY();
}
