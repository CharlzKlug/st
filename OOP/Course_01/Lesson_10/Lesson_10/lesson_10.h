#ifndef LESSON_10_H
#define LESSON_10_H
#include <QCoreApplication>
#include <iostream>
#include <ctime>
#include <fstream>
using namespace std;
const int N = 19;
typedef qreal TVect[N];
void initRandom();
void fillArrayRand(qreal *, qreal, qreal);
void printArray(qreal *);
void swapElements (qreal *, qreal *);
void selectionSort (qreal *);
bool writeVectFile (char *, qreal *);
void bubbleSort (qreal *);
#endif // LESSON_10_H
