// Сумма натуральных чисел и сумма их квадратов.
#include <QCoreApplication>
#include <cmath>
#include <iostream>
#include <time.h>
using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    cout<<"Вычисление суммы натуральных чисел и их квадратов.\n";

    int n; // Переменная, хранящая количество чисел.

    cout<<"n=";
    cin>>n;

    int sum1 = 0; // Будет хранить сумму натуральных чисел.
    int sum2 = 0; // Будет хранить сумму квадратов натуральных чисел.

    for (int i = 1; i<=n; i++)
    {
        sum1 = sum1 + i;
        sum2 = sum2 + i*i;
    }

    cout<<"sum1="<<sum1<<"\n";
    cout<<"Check sum1="<<(n*(n + 1)/2)<<"\n";
    cout<<"sum2="<<sum2<<"\n";
    cout<<"Check sum2="<<(n*(n + 1)*(2*n + 1)/6)<<"\n";
    return 0;
}
