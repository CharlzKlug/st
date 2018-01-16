#ifndef VECTOR_H
#define VECTOR_H
#include <QtGlobal>

class Vector
{
private:
    qreal x,y;
public:
    Vector();
    Vector(qreal, qreal);
    Vector operator +(Vector);
    Vector operator -(Vector&);
    Vector operator *(qreal);
    Vector operator /(qreal);
    void add(qreal, qreal);
    void deduct(qreal, qreal);
    void multiple(qreal);
    void divide(qreal);
    qreal getX();
    qreal getY();
    qreal module();
};
#endif // VECTOR_H
