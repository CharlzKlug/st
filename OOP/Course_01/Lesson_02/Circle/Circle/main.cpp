// Проверка расположения точки и окружности
#include <QCoreApplication>
#include <iostream>
#include <ctime>
#include <cmath>
using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int XC, YC, RC; // Координаты X и Y и радиус R окружности

    cout<<"Введите координату X окружности:";
    cin>>XC;

    cout<<"Введите координату Y окружности:";
    cin>>YC;

    cout<<"Введите радиус окружности:";
    cin>>RC;

    int X, Y; // Координаты точки

    cout<<"Введите координату X точки:";
    cin>>X;

    cout<<"Введите координату Y точки:";
    cin>>Y;

    if ((XC - X)*(XC - X) + (YC - Y)*(YC - Y) <= RC*RC)
    {
        cout<<"Точка внутри окружности\n";
    }
    else
    {
        cout<<"Точка снаружи окружности\n";
    }
    return 0;
}
