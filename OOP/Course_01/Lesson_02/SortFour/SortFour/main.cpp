// Сортировка четырёх чисел в порядке возрастания
#include <QCoreApplication>
#include <iostream>
#include <ctime>
#include <cmath>
using namespace std;
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    qreal NumberA, NumberB, NumberC, NumberD;

    cout<<"Ведите число A:";
    cin>>NumberA;

    cout<<"Ведите число B:";
    cin>>NumberB;

    cout<<"Ведите число C:";
    cin>>NumberC;

    cout<<"Ведите число D:";
    cin>>NumberD;

    qreal t;

    // Приведение NumberA
    if (NumberA > NumberB)
    {
        t = NumberA;
        NumberA = NumberB;
        NumberB = t;
    }

    if (NumberA > NumberC)
    {
        t = NumberA;
        NumberA = NumberC;
        NumberC = t;
    }

    if (NumberA > NumberD)
    {
        t = NumberA;
        NumberA = NumberD;
        NumberD = t;
    }

    // Приведение NumberB
    if (NumberB > NumberC)
    {
        t = NumberB;
        NumberB = NumberC;
        NumberC = t;
    }

    if (NumberB > NumberD)
    {
        t = NumberB;
        NumberB = NumberD;
        NumberD = t;
    }

    // Приведение NumberC
    if (NumberC > NumberD)
    {
        t = NumberC;
        NumberC = NumberD;
        NumberD = t;
    }

    // Печать результата
    cout<<"A="<<NumberA<<"\n";
    cout<<"B="<<NumberB<<"\n";
    cout<<"C="<<NumberC<<"\n";
    cout<<"D="<<NumberD<<"\n";
    return 0;
}
