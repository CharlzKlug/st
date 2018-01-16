#include "rkmethod.h"

RKMethod::RKMethod(Vector tr1, Vector tr2, Vector tv1,
                   Vector tv2, qreal step, qreal tm1,
                   qreal tm2):
    r1(tr1), r2(tr2), v1(tv1), v2(tv2), h(step), m1(tm1), m2(tm2){
}

void RKMethod::resetAll(Vector tr1, Vector tr2, Vector tv1, Vector tv2,
                        qreal step, qreal tm1, qreal tm2){
    setr1(tr1);
    setr2(tr2);
    setv1(tv1);
    setv2(tv2);
    setStep(step);
    setm1(tm1);
    setm2(tm2);
    resetTime();
}

void RKMethod::setr1(Vector v){
    r1 = v;
}

void RKMethod::setr2(Vector v){
    r2 = v;
}

void RKMethod::setv1(Vector v){
    v1 = v;
}

void RKMethod::setv2(Vector v){
    v2 = v;
}

void RKMethod::setStep(qreal step){
    h = step;
}

void RKMethod::setm1(qreal m){
    m1 = m;
}

void RKMethod::setm2(qreal m){
    m2 = m;
}

void RKMethod::resetTime(){
    t = 0;
}

Vector RKMethod::getr1(){return r1;}

Vector RKMethod::getr2(){return r2;}

Vector RKMethod::getv1(){return v1;}

Vector RKMethod::getv2(){return v2;}

qreal RKMethod::getStep(){return h;}

qreal RKMethod::getm1(){return m1;}

qreal RKMethod::getm2(){return m2;}

qreal RKMethod::getTime(){return t;}

void RKMethod::iterate(){
    Vector c; // r1
    Vector d; // r2
    Vector e; // v1
    Vector f; // v2

    a1 = (r2 - r1) * G * m2 / pow((r2 - r1).module(), 3); // Ускорение первого тела
    a2 = (r1 - r2) * G * m1 / pow((r1 - r2).module(), 3); // Ускорение второго тела

    Vector g1, g2, g3, g4;
    g1 = v1;
    g2 = v1 + g1 * 0.5 * h;
    g3 = v1 + g2 * 0.5 * h;
    g4 = v1 + g3 * h;
    c = (g1 + g2 * 2 + g3 * 2 + g4) * h / 6.0 + r1; // Радиус-вектор первого тела

    Vector h1, h2, h3, h4;
    h1 = v2;
    h2 = v2 + h1 * 0.5 * h;
    h3 = v2 + h2 * 0.5 * h;
    h4 = v2 + h3 * h;
    d = (h1 + h2 * 2 + h3 * 2 + h4) * h / 6.0 + r2; // Радиус-вектор второго тела

    Vector k1, k2, k3, k4;
    k1 = gravityForce(r1, r2, m2);
    k2 = gravityForce(r1 + g1 * 0.5 * h, r2 + h1 * 0.5 * h, m2);
    k3 = gravityForce(r1 + g2 * 0.5 * h, r2 + h2 * 0.5 * h, m2);
    k4 = gravityForce(r1 + g2 * h, r2 + h2 * h, m2);
    e = (k1 + k2 * 2 + k3 * 2 + k4) * h / 6.0 + v1; // Скорость первого тела

    Vector l1, l2, l3, l4;
    l1 = k1 * (-1);
    l2 = k2 * (-1);
    l3 = k3 * (-1);
    l4 = k4 * (-1);
    f = (l1 + l2 * 2 + l3 * 2 + l4) * h / 6.0 + v2; // Скорость второго тела

    r1 = c;
    r2 = d;
    v1 = e;
    v2 = f;
    t += h;
}

Vector RKMethod::gravityForce(Vector s1, Vector s2, qreal mass){
    return (s2 - s1) * G * mass / pow((s2 - s1).module(), 3);
}
