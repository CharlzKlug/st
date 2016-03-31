#ifndef MATRIXOPERATION_H
#define MATRIXOPERATION_H
#include <QCoreApplication>
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
char selectMenu(string *, int);
const int RMAX = 9, CMAX = 9;
typedef qreal TMatr[RMAX][CMAX];
void loadMatrix(TMatr, TMatr, int, int);
void printMatrix(TMatr, int, int);
qreal getRandom(int, int);
void loadRandomMatrix(TMatr, int, int, int, int);
void transposeMatrix(TMatr, int, int);
void sumMatrix(TMatr, TMatr, int, int);
void subMatrix(TMatr, TMatr, int, int);
void mulMatrix(TMatr, TMatr, TMatr, int, int);
typedef qreal TVect [RMAX];
void makeVectMaxModRow (TVect, TMatr, int, int);
void printVect(TVect, int, bool);
void makeVectMaxModCol (TVect, TMatr, int, int);
qreal diagSum(TMatr, int, int, int);
#endif // MATRIXOPERATION_H
