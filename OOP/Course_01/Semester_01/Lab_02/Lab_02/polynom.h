#ifndef POLYNOM_H
#define POLYNOM_H

#include <QCoreApplication>
#include <cmath>
#include <iostream>
#include <ctime>
#include <fstream>
#include <iomanip>

using namespace std;

const int polynomCoefsCount = 11;    // Степень полинома.

const int zero = 0; // Константа ноль.

const int one = 1; // Константа единица.

typedef qreal TCoef [polynomCoefsCount];    // Тип TCoef - массив с коэффициентами полинома

typedef qreal TVect;    // Тип TPoly - массив со значениями полинома

typedef qreal TDPoly [polynomCoefsCount];   // Тип TDPoly - массив со значениями производной
                                            // полинома.

typedef int TFunc (int);    // Экспериментальное объявление.

void highOrder (TFunc, int);

TFunc someFunc;

void loadCoefKeyboard(TCoef, int);  // Загрузка коэффициентов с клавиатуры.

qreal poly (TCoef, int, qreal); // Вычисление полинома методом Горнера.

//void calculateEdgePoly (TCoef, int, TPoly, qreal, qreal, int);  // Вычисление значений полинома
                                                            // на отрезке и занесение
                                                            // результатов в массив.

qreal polyD (TCoef, int, qreal);

char menu(); // Прототип для выбора меню

void outputCoefs(TCoef, int);   // Прототип печати коэффициентов полинома.

void loadRandomCoefs (qreal *, int); // Сгенерировать случайные коэффициенты

void loadCoefsFile(qreal *, int, char *);   // Считывание коэффициентов из файла

qreal calcStep (qreal, qreal, int); // Вычисление шага на отрезке

void calculateEdgePoly (TCoef, int, qreal *, qreal *, qreal, qreal, int);  // Вычисление значений полинома на некотором отрезке и занесение значений
// в массив.

void swapElements (qreal *, qreal *);
void selectionSort (qreal *, int);
void bubbleSort(qreal *, int);
void insertionSort (qreal *, int);
void inverseArray(qreal *, int);
#endif // POLYNOM_H
