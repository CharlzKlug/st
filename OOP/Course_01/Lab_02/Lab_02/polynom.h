#ifndef POLYNOM_H
#define POLYNOM_H

#include <QCoreApplication>
#include <cmath>
#include <iostream>

using namespace std;

const int m = 11;  // Количество коэффициентов полинома

typedef qreal TCoef [m];    // Прототип для типа коэффициенты полинома

typedef qreal TPoly (TCoef, int, qreal);  // Прототип для функции, возвращающей значение полинома с коэффициентами TCoef,
// количеством коэффициентов int для аргумента qreal.

qreal poly(TCoef, int, qreal);  // Функция, возвращает значение для аргумента x, TCoef - коэффициенты полинома, int - количество коэффициентов

char menu(); // Прототип для выбора меню

void outputCoefs(TCoef, int);   // Прототип печати коэффициентов полинома.
#endif // POLYNOM_H
