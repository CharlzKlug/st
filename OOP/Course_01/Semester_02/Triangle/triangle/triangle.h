#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "point.h"
class Triangle{
private:
    Point points [3];
    int firstDot(int);
    int secondDot(int);
    qreal dist(Point&, Point&);
public:
    Triangle (Point&, Point&, Point&);
    qreal getPX(int);
    qreal getPY(int);
    qreal square();
    qreal heightX(int);
    qreal heightY(int);
    qreal medianX(int);
    qreal medianY(int);
    qreal sideLength(int);
    qreal medianLength(int);
    qreal heightLength(int);
    qreal bisX(int);
    qreal bisY(int);
    qreal bisLength(int);
};

#endif // TRIANGLE_H
