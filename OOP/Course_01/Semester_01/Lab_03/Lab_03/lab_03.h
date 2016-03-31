#ifndef LAB_03_H
#define LAB_03_H
#include <QCoreApplication>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <ctime>
#include <cmath>
//#include <QDir>
//#include <QApplication>
//#include <ofstream>
using namespace std;
bool menuFromFile (string, string *, int);
char menu (string *, int);
void changeDimensions(int &, int &);
void fillMatrixRandom (qreal *, int, int, int, int);
qreal randBetween (int, int);
void printMatrix (qreal *, int, int);
void copyMatrix (qreal *, qreal *, int, int, int);
qreal getME (qreal *, int, int, int);
void setME (qreal *, int, int, int, qreal);
void loadMatrixKeyboard (qreal *, int, int);
bool saveMatrix (string, qreal *, int, int);
bool loadMatrixFile (string, qreal *, int &, int &);
qreal rowMaxNorm (qreal *, int, int);
qreal rowNorm (qreal *, int, int);
qreal columnMaxNorm (qreal *, int, int);
qreal columnNorm (qreal *, int, int, int);
qreal sumSqrt (qreal *, int, int);
int minME (qreal *, int, int, int &);
int maxME (qreal *, int, int, int &);
void replaceRow (qreal *, int, int);
void linearCopyMatrix (qreal *, qreal *, int, int);
void sortMatrixByColumn (qreal *, int, int, int, bool);
int selectRowInColumn (qreal *, int, int, int, int, bool);
void changeRows (qreal *, int, int, int);
void inverseMatrixRows (qreal *, int, int);
#endif // LAB_03_H
