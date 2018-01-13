#include "vector.h"

Vector::Vector(qreal x1, qreal y1) : x(x1), y(y1) {}

Vector::Vector() : x(0), y(0){}

void Vector::add(qreal x1, qreal y1){
    x += x1;
    y += y1;
}

void Vector::deduct(qreal x1, qreal y1){
    x -= x1;
    y -= y1;
}

void Vector::multiple(qreal k){
    x *= k;
    y *= k;
}

void Vector::divide(qreal k){
    x /= k;
    y /= k;
}

qreal Vector::getX(){
    return x;
}

qreal Vector::getY(){
    return y;
}

Vector Vector::operator +(Vector param){
    Vector tmpvect(x, y);
    tmpvect.add(param.getX(), param.getY());
    return tmpvect;
}

Vector Vector::operator -(Vector& param){
    Vector tmpvect(x, y);
    tmpvect.deduct(param.getX(), param.getY());
    return tmpvect;
}

Vector Vector::operator *(qreal k){
    Vector tmpvect(x, y);
    tmpvect.multiple(k);
    return tmpvect;
}

Vector Vector::operator /(qreal k){
    Vector tmpvect(x, y);
    tmpvect.divide(k);
    return tmpvect;
}

qreal Vector::module(){
    return sqrt(x*x + y*y);
}
