#include <QCoreApplication>
#include <iostream>
#include "polynom.h"
int main()
{
    std::cout << "Hello, World!" << std::endl;
    qreal coefsArray[]={2, 4, 5};
    TPolynom myPolynom(3, coefsArray);
    myPolynom.printCoefs();
    std::cout << "Значение полинома при x=1: " << myPolynom.calcGorner(2.0)<<std::endl;
    qreal a=0, b=5, h=0.5;
    std::cout<<"Отрезок ["<<a<<", "<<b<<"], шаг "<<h<<std::endl;
    valuesBetween(a, b, h, myPolynom);
    return 0;
}
