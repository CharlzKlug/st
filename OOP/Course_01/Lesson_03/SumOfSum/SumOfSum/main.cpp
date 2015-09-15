// Вычисление суммы сумм
#include <QCoreApplication>
#include <cmath>
#include <iostream>
#include <time.h>
using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int n; // Количество циклов

    cout<<"n=";
    cin>>n;

    double sum = 0;

    for (int i = 1; i<=n; i++)
        for (int k = 1; k<=i; k++)
            sum = sum + 1.0/sqrt(k);

    cout<<"sum="<<sum<<"\n";
    return 0;
}
