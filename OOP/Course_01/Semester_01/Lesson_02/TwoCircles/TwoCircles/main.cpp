// Проверка расположения точки и окружностей
#include <QCoreApplication>
#include <iostream>
#include <ctime>
#include <cmath>
using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int XC1, YC1, RC1; // Координаты X и Y и радиус R окружности 1

    cout<<"Введите координату X окружности 1:";
    cin>>XC1;

    cout<<"Введите координату Y окружности 1:";
    cin>>YC1;

    cout<<"Введите радиус окружности 1:";
    cin>>RC1;

    int XC2, YC2, RC2; // Координаты X и Y и радиус R окружности 2

    cout<<"Введите координату X окружности 2:";
    cin>>XC2;

    cout<<"Введите координату Y окружности 2:";
    cin>>YC2;

    cout<<"Введите радиус окружности 2:";
    cin>>RC2;



    int X, Y; // Координаты точки

    cout<<"Введите координату X точки:";
    cin>>X;

    cout<<"Введите координату Y точки:";
    cin>>Y;

    bool InFirstCircle = ((XC1 - X)*(XC1 - X) + (YC1 - Y)*(YC1 - Y) <= RC1*RC1); // Выясняем принадлежность первой окружности
    bool InSecondCircle = ((XC2 - X)*(XC2 - X) + (YC2 - Y)*(YC2 - Y) <= RC2*RC2); // Выясняем принадлежность второй окружности

    if (InFirstCircle && InSecondCircle) { cout<<"Точка принадлежит обеим окружностям\n";}
    if (InFirstCircle && (InSecondCircle == false)) { cout<<"Точка принадлежит первой окружности\n";}
    if ((InFirstCircle == false) && InSecondCircle) { cout<<"Точка принадлежит второй окружности\n";}
    if ((InFirstCircle == false) && (InSecondCircle == false)) { cout<<"Точка не принадлежит обеим окружностям\n";}

    return 0;
}
