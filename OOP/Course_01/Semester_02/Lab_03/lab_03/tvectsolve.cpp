#include "tvectsolve.h"

TVectSolve::TVectSolve(int n):TVector(n){}

TVectSolve::TVectSolve(int n, T * anotherArray):TVector(n, anotherArray){}

void TVectSolve::copyVectSolve(TVectSolve *q){
    int qSize = q->getSize();
    setSize(qSize);
    for (int i=0; i<qSize; i++){
        setItem(i, q->getItem(i));
    }
}

void TVectSolve::selectionSort(){
    int mySize=getSize();
    int smallestElementIndex;
    T temp;
    for (int i=0; i<mySize-1; i++){
        smallestElementIndex=i;
        for (int j=i+1; j<mySize; j++)
            if (getItem(smallestElementIndex)>getItem(j))
                smallestElementIndex=j;
        if (smallestElementIndex!=i){
            temp=getItem(i);
            setItem(i, getItem(smallestElementIndex));
            setItem(smallestElementIndex, temp);
        }
    }
}

void TVectSolve::bubbleSort(){
    int mySize=getSize();
    T temp;
    for (int i=mySize; i>0; i--){
        for (int j=1; j<mySize; j++)
            if (getItem(j-1)>getItem(j)){
                temp=getItem(j-1);
                setItem(j-1, getItem(j));
                setItem(j, temp);
            }
    }

}

void TVectSolve::insertionSort(){
    int mySize=getSize(), place;
    T temp;
    for (int i=1; i<mySize; i++)
        if (getItem(i)<getItem(i-1)){
            temp=getItem(i);
            place=i;
            while (place!=0 && getItem(place-1)>temp) {
                setItem(place, getItem(place-1));
                place--;
            }
            setItem(place, temp);
        }
}

void TVectSolve::chooseSort(int s){
    switch (s) {
    case 0:
        selectionSort();
        break;
    case 1:
        bubbleSort();
        break;
    default:
        insertionSort();
        break;
    }
}

void TVectSolve::swapItems(int j, int k){
    T temp=getItem(j);
    setItem(j, getItem(k));
    setItem(k, temp);
}

void TVectSolve::inverseItems(){
    int mySize=getSize();
    for (int i=0; i<mySize-i-1; i++)
        swapItems(i, mySize-i-1);
}

int TVectSolve::maxItemIndex(){
    int index=0, mySize=getSize();
    T value=getItem(index);
    for (int i=1; i<mySize; i++)
        if (value<getItem(i)){
            index=i;
            value=getItem(i);
        }
    return index;
}

qreal TVectSolve::midAr(){
    T sum=0;
    int mySize=getSize();
    for (int i=0; i<mySize; i++) sum += getItem(i);
    return (sum*1.0)/mySize;
}

TVectSolve & TVectSolve::operator = (TVectSolve *q){
    copyVectSolve(q);
    return *this;
}

TVectSolve::TVectSolve():TVector(){}
