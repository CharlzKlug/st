#ifndef OPERVECTOR_H
#define OPERVECTOR_H
#include <QCoreApplication>
#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

const int N = 10;
typedef qreal TVect [N];
char menu();
void fillVect(qreal *, qreal, qreal);
void outputArray (qreal *);
void moveItemOddorEven(qreal *, bool);
int maxNegative (qreal *);
int maxElement (qreal *);
void twoBiggest (qreal *);
void fillZero (qreal *);
int negativeCount (qreal *, qreal *);
int countChange (qreal *);
void inverse (qreal []);
void moveNegItem (TVect);
#endif // OPERVECTOR_H
