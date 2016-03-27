#include <QCoreApplication>
#include "fraction.h"
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Fraction fa (1, 2);
    Fraction ab (-1, 4);
    Fraction temp;
    //ab = fa - ab - ab;
    ab = fa * ab * ab;
    cout << ab.getNumerator() << "/" << ab.getDenominator() << endl;
    return 0;
}
