#include <QCoreApplication>
#include "fraction.h"
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Fraction fa (1, 2);
    Fraction ab (-1, 4);
    //cout << ab.getNumerator() << "/" << ab.getDenominator() << endl;
    //ab = fa = ab;
    ab = (2 / fa) + 1;
    cout << "fa = " << fa.getNumerator() << "/" << fa.getDenominator() << endl;
    cout << "ab = " << ab.getNumerator() << "/" << ab.getDenominator() << endl;
    return 0;
}
