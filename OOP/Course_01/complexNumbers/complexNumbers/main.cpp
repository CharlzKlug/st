#include <QCoreApplication>
#include "complex.h"
#include <iostream>
#include "wrapperComplex.h"
using namespace std;

void printComplex(Complex& q){
    cout << "Real part: " << q.getReal() << endl;
    cout << "Imaginary part: " << q.getImaginary() << endl << endl;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    WrapperComplex myWrapper(1, 2);
    WrapperComplex anotherWrapper(5, 8);
    //Complex myComplex(1, 2);
    //myWrapper.setValue(1, 2);
    myWrapper.divisionComplexNumbers(anotherWrapper);
    myWrapper.printComplex();
    return 0;
}
