#include "triangle.h"
#include <cmath>
Triangle::Triangle(Point & a, Point & b, Point & c){
    points[0]=a;
    points[1]=b;
    points[2]=c;
}

int Triangle::firstDot(int d){
    return (d+1)%3;
}

int Triangle::secondDot(int d){
    return (d+2)%3;
}

qreal Triangle::getPX(int i){
    return points[i].getX();
}

qreal Triangle::getPY(int i){
    return points[i].getY();
}

qreal Triangle::square(){
    return fabs(((getPX(1)-getPX(0))*(getPY(2)-getPY(0))-
            (getPX(2)-getPX(0))*(getPY(1)-getPY(0))))/2;
}

qreal Triangle::heightX(int i){
    qreal lambda;
    qreal x1, x0, x2;
    qreal y1, y0, y2;
    x1=getPX(i);
    x0=getPX(firstDot(i));
    x2=getPX(secondDot(i));
    y1=getPY(i);
    y0=getPY(firstDot(i));
    y2=getPY(secondDot(i));
    qreal dx, dy;
    dx=x2-x0;
    dy=y2-y0;
    lambda=((x1-x0)*dx+(y1-y0)*dy)/(dx*dx+dy*dy);
    return x0+lambda*dx;
}

qreal Triangle::heightY(int i){
    qreal lambda;
    qreal x1, x0, x2;
    qreal y1, y0, y2;
    x1=getPX(i);
    x0=getPX(firstDot(i));
    x2=getPX(secondDot(i));
    y1=getPY(i);
    y0=getPY(firstDot(i));
    y2=getPY(secondDot(i));
    qreal dx, dy;
    dx=x2-x0;
    dy=y2-y0;
    lambda=((x1-x0)*dx+(y1-y0)*dy)/(dx*dx+dy*dy);
    return y0+lambda*dy;
}

qreal Triangle::medianX(int i){
    return (getPX(firstDot(i))+getPX(secondDot(i)))/2;
}

qreal Triangle::medianY(int i){
    return (getPY(firstDot(i))+getPY(secondDot(i)))/2;
}

qreal Triangle::dist(Point & a, Point & b){
    qreal vx, vy;
    vx=b.getX()-a.getX();
    vy=b.getY()-a.getY();
    return sqrt(vx*vx+vy*vy);
}

qreal Triangle::sideLength(int i){
    return dist(points[firstDot(i)], points[secondDot(i)]);
}

qreal Triangle::medianLength(int i){
    Point m(medianX(i), medianY(i));
    return dist(points[i], m);
}

qreal Triangle::heightLength(int i){
    Point h(heightX(i), heightY(i));
    return dist(points[i], h);
}

qreal Triangle::bisX(int i){
    qreal bc=dist(points[i], points[firstDot(i)]);
    qreal ab=dist(points[i], points[secondDot(i)]);
    qreal koef=bc/(ab+bc);
    return points[firstDot(i)].getX()+
            (points[secondDot(i)].getX()-points[firstDot(i)].getX())*koef;
}

qreal Triangle::bisY(int i){
    qreal bc=dist(points[i], points[firstDot(i)]);
    qreal ab=dist(points[i], points[secondDot(i)]);
    qreal koef=bc/(ab+bc);
    return points[firstDot(i)].getY()+
            (points[secondDot(i)].getY()-points[firstDot(i)].getY())*koef;
}

qreal Triangle::bisLength(int i){
    Point b(bisX(i), bisY(i));
    return dist(points[i], b);
}
