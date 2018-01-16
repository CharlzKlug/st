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
    void setr1(Vector); // Установить радиус-вектор A
    void setr2(Vector); // Установить радиус-вектор B
    void setv1(Vector); // Установить вектор скорости A
    void setv2(Vector); // Установить вектор скорости B
    void setStep(qreal); // Установить шаг приращения времени
    void setm1(qreal); // Установить массу A
    void setm2(qreal); // Установить массу B
    void resetTime(); // Сбросить время
    void resetAll(Vector, Vector, Vector, Vector,
                  qreal, qreal, qreal);

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
