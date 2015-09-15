// Вычислить сумму из n элементов последовательности 1/3, 1/5, ..., 1/(2n+1)
#include <QCoreApplication>
#include <cmath>
#include <iostream>
#include <time.h>
using namespace std;


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int n; // Количество элементов последовательности.
    cout<<"n=";
    cin>>n;

    qreal sum = 0; // Общая сумма.

    for (int i = 1; i<=n; i++)
    {
        sum = sum + 1./(2*n + 1);
    }

    cout<<"sum="<<sum<<"\n";

    return 0;
}
