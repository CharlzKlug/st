#ifndef POINT_H
#define POINT_H

#include <QtGlobal>
class Point{
private:
    qreal x,y;
public:
    Point();
    Point (qreal, qreal);
    Point (Point&);
    qreal getX();
    qreal getY();
};

#endif // POINT_H
