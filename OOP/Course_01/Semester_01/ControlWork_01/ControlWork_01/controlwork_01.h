#ifndef CONTROLWORK_01_H
#define CONTROLWORK_01_H
#include <QCoreApplication>
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
char selectMenu (string *, char *);
void loadRandomCoefs (qreal *, int);
int indexMaxABS (qreal *, int);
void printArray (qreal *, int);
qreal sumAfterFirstPos (qreal *, int);
void swapElements(qreal &, qreal &);
void sortCaprice (qreal *, int, qreal, qreal);
#endif // CONTROLWORK_01_H
