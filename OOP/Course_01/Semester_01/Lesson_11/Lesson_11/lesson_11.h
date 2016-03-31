#ifndef LESSON_11_H
#define LESSON_11_H
#include <QCoreApplication>
#include <iostream>
using namespace std;
char menu(string *, char *);
void copyVector (qreal *, qreal *, int);
void showVector(qreal *, int);
void inputVectRnd (qreal *, qreal, qreal, int);
qreal sumItemAfterFirstMinus (qreal *, int);
qreal sumItemAfterLastPlus(qreal *, int);
qreal sumItemBetweenMinus (qreal *, int, int *, int *);
void createPositiveItem(qreal *, int *);
#endif // LESSON_11_H
