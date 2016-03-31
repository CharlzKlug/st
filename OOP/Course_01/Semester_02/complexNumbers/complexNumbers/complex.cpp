#include "complex.h"

Complex :: Complex (qreal xre = 0, qreal yir = 0){
    // Конструктор с двумя аргументами
    realPart = xre;
    imaginaryPart = yir;
}

Complex :: Complex (){
    // Пустой вызов конструктора
    Complex (0, 0);
}

Complex& Complex :: addComplexNumbers(Complex& anotherComplexNumber){
    // Сложение данного комплексного числа с другим комплексным числом
    realPart += anotherComplexNumber.getReal();
    imaginaryPart += anotherComplexNumber.getImaginary();
    return *this;
}

qreal Complex :: getImaginary(){
    // Возврат мнимой части
    return imaginaryPart;
}

qreal Complex :: getReal(){
    // Возврат вещественной части
    return realPart;
}

Complex& Complex :: multipleComplexNumbers (Complex& anotherComplexNumber){
    // Перемножение комплексных чисел
    qreal tempReal = realPart;
    qreal tempImaginary = imaginaryPart;
    realPart = tempReal * anotherComplexNumber.getReal() -
            tempImaginary * anotherComplexNumber.getImaginary();
    imaginaryPart = tempImaginary * anotherComplexNumber.getReal() +
            tempReal * anotherComplexNumber.getImaginary();
    return *this;
}

Complex& Complex :: divisionComplexNumbers (Complex& anotherComplexNumber){
    // Деление комплексных чисел
    qreal tempReal = realPart;
    qreal tempImaginary = imaginaryPart;
    qreal denominator = anotherComplexNumber.getImaginary() *
            anotherComplexNumber.getImaginary() +
            anotherComplexNumber.getReal() *
            anotherComplexNumber.getReal();
    realPart = (tempReal * anotherComplexNumber.getReal() +
            tempImaginary * anotherComplexNumber.getImaginary()) / denominator;
    imaginaryPart = (tempImaginary * anotherComplexNumber.getReal() -
                     tempReal * anotherComplexNumber.getImaginary()) / denominator;
    return *this;
}

void Complex :: setRealPart(qreal someNumber) {
    // Смена вещественной части
    realPart = someNumber;
}

void Complex :: setImaginaryPart(qreal someNumber) {
    // Смена мнимой части
    imaginaryPart = someNumber;
}
