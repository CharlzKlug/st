#ifndef COMPLEX_H
#define COMPLEX_H
#include <QCoreApplication>

class Complex  {
private:
    qreal realPart, imaginaryPart;
public:
    Complex (qreal, qreal);
    Complex (const Complex&);
    Complex ();
    qreal getReal();
    qreal getImaginary();
    Complex& addComplexNumbers(Complex&);
    Complex& multipleComplexNumbers(Complex&);
    Complex& divisionComplexNumbers(Complex&);
    void setRealPart (qreal);
    void setImaginaryPart (qreal);
};


#endif // COMPLEX_H
