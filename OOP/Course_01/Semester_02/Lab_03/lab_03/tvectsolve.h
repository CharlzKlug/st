#ifndef TVECTSOLVE_H
#define TVECTSOLVE_H
#include "tvector.h"
class TVectSolve: public TVector{
private:
    //void swapItems(int, int);
public:
    TVectSolve();
    TVectSolve(int);
    TVectSolve(int, T * );
    void copyVectSolve(TVectSolve *);
    void selectionSort();
    void bubbleSort();
    void insertionSort();
    void chooseSort(int);
    void inverseItems();
    int maxItemIndex();
    qreal midAr();
    TVectSolve & operator = (TVectSolve *);
    void swapItems(int, int);
    qreal averGeom();
};

#endif // TVECTSOLVE_H
