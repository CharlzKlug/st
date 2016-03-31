#ifndef WRAPPERCOMPLEX_H
#define WRAPPERCOMPLEX_H
#include "complex.h"
#include <iostream>
class WrapperComplex{
public:
    Complex myComplex;
    WrapperComplex();
    WrapperComplex(qreal, qreal);
    //WrapperComplex(Complex&);
    void setValue(Complex&);
    void printComplex();
    void divisionComplexNumbers(WrapperComplex&);
};
#endif // WRAPPERCOMPLEX_H
