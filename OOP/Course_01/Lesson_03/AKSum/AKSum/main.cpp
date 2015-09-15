// Вычисление суммы из n элементов последовательности 1/a^k
#include <QCoreApplication>
#include <cmath>
#include <iostream>
#include <time.h>
using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int n; // Сколько элементов надо просуммировать.
    cout<<"n=";
    cin>>n;

    int aValue;
    cout<<"aValue=";
    cin>>aValue;

    qreal sum = 0; // Результирующая сумма
    qreal element = 1.0;

    for (int i = 1; i<=n; i++)
    {
        element = element * (1.0/aValue);
        sum = sum + element;
    }

    cout<<"sum="<<sum<<"\n";
    return 0;
}
