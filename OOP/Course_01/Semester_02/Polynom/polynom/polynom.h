#ifndef POLYNOM_H
#define POLYNOM_H
#include <QtCore>
#include <iostream>
#include <iomanip>
class TPolynom{
private:
    int m;  // Степень полинома
    qreal * coefs;
    qreal calcGornerRecur(qreal x, int current);   // Вычисление значения полинома по схеме Горнера
public:
    TPolynom (int n, qreal *someCoefs);
    void printCoefs();
    qreal calcGorner(qreal x);
    friend void valuesBetween(qreal a, qreal b, qreal h, TPolynom & q);

};

#endif // POLYNOM_H
