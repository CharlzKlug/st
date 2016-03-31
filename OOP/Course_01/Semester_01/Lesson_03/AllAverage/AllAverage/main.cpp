// Среднее арифметическое всех вводимых с клавиатуры чисел
#include <QCoreApplication>
#include <cmath>
#include <iostream>
#include <time.h>
using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int sum = 0; // Общая сумма
    int x; // Очередное считанное число
    qreal n; // Общее количество считанных чисел
    while (cout<<"x=", cin>>x, x)
    {
        sum = sum + x;
        n = n + 1;
    }

    cout<<"Average "<<(sum/n)<<"\n";
    return 0;
}
