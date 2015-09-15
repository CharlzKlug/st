// Вычислить сумму нечётных цифр числа
#include <QCoreApplication>
#include <cmath>
#include <iostream>
#include <time.h>
using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int x; // Некоторое число

    cout<<"x=";
    cin>>x;

    int sum = 0; // Общая сумма

    while (x>0)
    {
        if ((x%10)%2)
        {
            sum = sum + x%10;
        }

        x = x/10;
    }

    cout<<"sum="<<sum<<"\n";
    return 0;
}
