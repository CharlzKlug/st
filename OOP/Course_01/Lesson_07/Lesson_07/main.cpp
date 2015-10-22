//#include <QCoreApplication>
#include "Lesson_07.h"
#include <ctime>


using namespace std;
typedef qreal TFunc (qreal);

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    cout<<"Урок №7. Дихотомия, метод Ньютона и все-все-все"<<endl;
    srand(time(0));
    char selected;
    qreal af = -3;   // Нижняя граница
    qreal b = 5;    // Верхняя граница
    qreal h = 0.09; // Шаг
    qreal epsilon = 0.01;   // Погрешность
    while (selected = menu(), selected != 'X')
        switch (selected) {
        case 'A':   // Таблица значений функции
            showTable(sin);
            break;
        case 'B':   // Смена значений задачи
            cout<<"Смена значений задачи"<<endl;
            cout<<"a = ";
            cin>>af;
            cout<<"b = ";
            cin>>b;
            cout<<"h = ";
            cin>>h;
            cout<<"epsilon = ";
            cin>>epsilon;
            break;
        case 'C':   // Нахождение максимума и минимума функции
            functionMaxMin(sin, af, b, h);
            break;
        case 'D':   // Поиск нуля функции методом дихотомии
            dixotomyZero(sin, af, b, h, epsilon);
            break;
        case 'E':
            NewtonZero(sin, af, b, h, epsilon);
            break;
        case 'F':
            intersectionDixotomy(sin, someLine, af, b, h, epsilon);
            break;
        case 'G':
        {    cout<<"Операции с числом"<<endl;
            long n = rand();
            cout<<"Исходное число: "<<n<<endl;
            cout<<"Число составленное из нечётных цифр: "<<buildNewNumber(n)<<endl;
            cout<<"Сумма чётных цифр: "<<evenSum(n)<<endl;
            cout<<"Среднее арифметическое нечётных цифр: "<<oddAverage(n)<<endl;
            }
            break;
        default:
            cout<<"Выбран несуществующий вариант."<<endl;
            break;
        }
    return 0;
}
