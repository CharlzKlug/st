// Вычисление вложенного синуса
#include <QCoreApplication>
#include <cmath>
#include <iostream>
#include <time.h>
using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int n; // Уровень вложенности

    cout<<"n=";
    cin>>n;
    double result = 0; // Результат.
    for (int i = n; i>0; i--)
    {
        result = sin(result + i);

    }

    cout<<"Result="<<result<<"\n";
    return 0;
}
