#include <tvector.h>

TVector::TVector(){
    size = 10;
    srand(std::time(0)*1021);
    myArray = new T[size];
    for (int i=0; i<size; i++){
        myArray[i]=getRand();
    }
}

TVector::TVector(int n){
    size = n;
    srand(std::time(0)*1021);
    myArray = new T[size];
    for (int i=0; i<size; i++){
        myArray[i]=getRand();
    }
}

TVector::TVector(int n, T * someArray){
    size=n;
    myArray=new T[size];
    for(int i=0; i<size; i++){
        myArray[i]=someArray[i];
    }
}

T TVector::getItem(int k){
    return myArray[k];
}

void TVector::setItem(int k, T el){
    myArray[k]=el;
}

T TVector::getRand(){
    return (rand()*(hTr-lTr))/RAND_MAX+lTr;
}

void TVector::printVector(){
    std::cout<<std::setprecision(2);
    for (int i=0; i<size; i++)
        std::cout<<std::setw(6)<<i;
    std::cout<<std::endl;
    for (int i=0; i<size; i++)
        std::cout<<std::setw(6)<<myArray[i];
    std::cout<<std::endl;
}

void TVector::setSize(int n){
    size=n;
    delete myArray;
    myArray = new T[size];
}

int TVector::getSize(){
    return size;
}
