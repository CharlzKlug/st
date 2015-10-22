#ifndef LESSON_07_H
#define LESSON_07_H
#include <QCoreApplication>
#include <iostream>
#include <iomanip>
#include <cmath>

typedef qreal TFunc (qreal);

void myFunction();

char menu();

void showTable(TFunc);

void functionMaxMin(TFunc, qreal, qreal, qreal);

void dixotomyZero(TFunc, qreal, qreal, qreal, qreal);

void dixotomyIter(TFunc, qreal, qreal, qreal);

qreal dixotomyRecur (TFunc, qreal, qreal, qreal);

qreal NewtonIter (TFunc, qreal, qreal, qreal);

qreal NewtonRecur (TFunc, qreal, qreal, qreal);

qreal d(TFunc, qreal);

qreal NewtonInner (TFunc, qreal, qreal);

void NewtonZero(TFunc, qreal, qreal, qreal, qreal);

qreal searchIntersection (TFunc, TFunc, qreal, qreal, qreal);

void intersectionDixotomy (TFunc, TFunc, qreal, qreal, qreal, qreal);

qreal someLine (qreal);

long newNumberRecur(long, long, int);

long buildNewNumber(long);

long evenSum (long);

qreal oddAverage (long);
#endif // LESSON_07_H
