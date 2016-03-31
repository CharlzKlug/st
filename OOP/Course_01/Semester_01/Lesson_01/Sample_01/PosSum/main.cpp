// Вычисление суммы положительных чисел и вычисление среднего арифметического положительных чисел.
#include <QCoreApplication>
#include <iostream>
#include <ctime>
#include <cmath>
using namespace std;
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Объявляем три целых числа.
    int number1, number2, number3;

    // Вводим значения трёх чисел.
    cout<<"number1=";
    cin>>number1;

    cout<<"number2=";
    cin>>number2;

    cout<<"number3=";
    cin>>number3;

    // Объявляем переменную, которая будет сохранять в себе эти три числа.
    double sum = 0;

    // Вычисляем сумму положительных чисел.
    sum = number1*(number1>0) + number2*(number2>0) + number3*(number3>0);

    cout<<"Сумма положительных чисел равна "<<sum<<"\n";

    // Объявляем переменную, которая будет содержать количество положительных чисел.
    int m = 0;

    // Посчитали количество положительных чисел.
    m = (number1>0) + (number2>0) + (number3>0);

    // Если количество положительных чисел больше нуля, то делим сумму на количество положительных чисел m.
    m>0 && (sum /= m);

    cout<< "Среднее арифметическое равно "<<sum<<"\n";
    return 0;
}
