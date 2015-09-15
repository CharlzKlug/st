// Среднее геометрическое из n положительных случайных чисел
#include <QCoreApplication>
#include <cmath>
#include <iostream>
#include <time.h>
using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int n;

    cout<<"n=";
    cin>>n;

    int n1; // Нижняя граница периода
    cout<<"n1=";
    cin>>n1;

    int n2; // Верхняя граница периода
    cout<<"n2=";
    cin>>n2;

    int mul = 1; // Общее произведение
    int m = 0; // Сколько положительных чисел

    int x; // Случайное число

    srand(time(0));
    for (int i = 1; i<=n; i++)
    {
        x = rand()%(n2 - n1 + 1) + n1;
        if (x>0)
        {
            mul = mul * x;
            m = m + 1;
        }
    }

    if (m>0) {cout<<"Average geometry = "<<exp(log(x)*1/m)<<"\n";}
    else {cout<<"Average geometry = 0"<<"\n";}
    return 0;
}
