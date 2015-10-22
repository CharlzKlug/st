// ------------------- Лабораторная работа № 1 по объектно-ориентированному программированию -------------------
// Выполнил: Аметов И.И., ТМБО-01-15
#include <QCoreApplication>
//#include <iostream>
//#include <ctime>
//#include <cmath>
//#include <iomanip>
#include "myfunctions.h"
//using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    cout<<"Лабораторная работа № 1 по объектно-ориентированному программированию\n";
    cout<<"Выполнил: Аметов И.И., ТМБО-01-15\n";
    cout<<"Функция: f(x) = 3*sin(x) - x^2 + x + 4\n";
    cout<<pow(-5,0.5)<<" "<<pow(-5, 2);
    int choice; // Выбор пользователя
    while ((choice = menu()) != 8)
    {
        switch (choice) {
        case 1:
            choice1();
            break;
        case 2:
            choice2();
            break;
        case 3:
            choice3();
            break;
        case 4:
            choice4();
            break;
        case 5:
            choice5();
            break;
        case 6:
            choice6();
            break;
        default:
            cout<<"Некорректный ввод\n";
            break;
        }
    }
    return 0;
}
