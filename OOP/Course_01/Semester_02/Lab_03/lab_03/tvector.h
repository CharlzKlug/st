#ifndef TVECTOR_H
#define TVECTOR_H
#include <QtCore>
#include <ctime>
#include <iostream>
#include <iomanip>
typedef qreal T;
T const lTr=-5, hTr=5;
class TVector {
private:
    int size;
    T * myArray;
    T getRand();
protected:
    void setSize(int);
public:
    TVector ();
    TVector (int);
    TVector (int, T *);
    T getItem (int);
    void setItem (int, T);
    void printVector();
    int getSize();
};

#endif // TVECTOR_H
