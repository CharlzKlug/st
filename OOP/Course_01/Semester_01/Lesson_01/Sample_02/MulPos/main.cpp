// Вычисление произведения положительных чисел.
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

    // Отмечает присутствие хотя бы одного положительного числа.
    bool positivePresent = false;

    // Вводим значения трёх чисел.
    cout<<"number1=";
    cin>>number1;
    (number1>0) && (positivePresent = true);

    cout<<"number2=";
    cin>>number2;
    (number2>0) && (positivePresent = true);

    cout<<"number3=";
    cin>>number3;
    (number3>0) && (positivePresent = true);

    // Объявляем переменную, которая будет сохранять в себе произведение.
    qreal multiple = 0;

    // Вычисляем произведение положительных чисел.
    positivePresent && (multiple = (number1*(number1>0) + (number1<=0))*(number2*(number2>0) + (number2<=0))*(number3*(number3>0) + (number3<=0)));

    cout<<"Произведение положительных чисел равно "<<multiple<<"\n";

    return 0;
}
