#ifndef RKMETHOD_H
#define RKMETHOD_H
#include "vector.h"
const qreal G = 6.674 / 100000000000;
class RKMethod
{
private:
    Vector r1, r2, v1, v2, a1, a2;
    qreal h, m1, m2, t = 0;
    Vector gravityForce(Vector, Vector, qreal);
public:
    RKMethod(Vector, Vector, Vector, Vector,
             qreal, qreal, qreal);
    void setr1(Vector);
    void setr2(Vector);
    void setv1(Vector);
    void setv2(Vector);
    void setStep(qreal);
    void setm1(qreal);
    void setm2(qreal);
    void resetTime();

    Vector getr1();
    Vector getr2();
    Vector getv1();
    Vector getv2();
    qreal getStep();
    qreal getm1();
    qreal getm2();
    qreal getTime();

    void iterate();
};
#endif // RKMETHOD_H
