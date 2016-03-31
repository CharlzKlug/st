// Вычисление максимального и минимального из трёх чисел.
#include <QCoreApplication>
#include <iostream>
#include <ctime>
#include <cmath>
using namespace std;
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Объявляем три числа.
    qreal number1, number2, number3;

    // Вводим значения трёх чисел.
    cout<<"number1=";
    cin>>number1;

    cout<<"number2=";
    cin>>number2;

    cout<<"number3=";
    cin>>number3;

    qreal zmin = number1, zmax = number1;

    number1>number2? zmin = number2: zmax = number2;
    (zmin>number3) && (zmin = number3);
    (zmax<number3) && (zmax = number3);

    cout<<"Минимальное число "<<zmin<<"\n";
    cout<<"Максимальное число "<<zmax<<"\n";

    cout<<"Сумма двух наименьших "<<number1 + number2 + number3 - zmax<<"\n";
    cout<<"Сумма двух наибольших "<< number1 + number2 + number3 - zmin<<"\n";
    return 0;
}
