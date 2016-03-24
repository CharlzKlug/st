#include "wrapperComplex.h"
WrapperComplex :: WrapperComplex (){
    // Конструктор с пустыми аргументами
}

WrapperComplex :: WrapperComplex (qreal xx, qreal yy){
    myComplex.setRealPart(xx);
    myComplex.setImaginaryPart(yy);
}

void WrapperComplex :: setValue(Complex & someComplex){
    // Задание новых значений
    myComplex.setImaginaryPart(someComplex.getImaginary());
    myComplex.setRealPart(someComplex.getReal());
}

void WrapperComplex :: printComplex(){
    // Печать значения комплексного числа
    std::cout << "Real part: " << myComplex.getReal() << std::endl;
    std::cout << "Imaginary part: " << myComplex.getImaginary() << std::endl << std::endl;
}

void WrapperComplex :: divisionComplexNumbers(WrapperComplex & anotherWrapper) {
    myComplex.divisionComplexNumbers(anotherWrapper.myComplex);
}
