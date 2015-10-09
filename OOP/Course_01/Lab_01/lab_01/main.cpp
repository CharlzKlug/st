// ------------------- Лабораторная работа № 1 по объектно-ориентированному программированию -------------------
// Выполнил: Аметов И.И., ТМБО-01-15
#include <QCoreApplication>
#include <iostream>
#include <ctime>
#include <cmath>
#include <iomanip>
using namespace std;

int menu()  // Выбор меню
{
    cout<<"Меню программы:\n";
    cout<<"1 - Вычислить значения функции и производной\n";
    cout<<"2 - Наибольшие и наименьшие табличные значения функции\n";
    cout<<"3 - Количество отрезков в которых функция обращается в 0\n";
    cout<<"4 - Вычислить среднее арифметическое, среднее геометрическое, среднее гармоническое\n";
    cout<<"5 - Вычислить нули функции итерационными методами дихотомии и Ньютона\n";
    cout<<"6 - Вычислить нули функции рекурсивными методами дихотомии и Ньютона\n";
    cout<<"7 - Вложенные отрезки с нулём функции\n";
    cout<<"8 - Выход из программы\n";
    int choice = 0;

    cin>>choice;

    return choice;
}

double f(double x)  // Исходная функция
{
    return 3 * sin(x) - x*x + x + 4;
}

double d(double x)  // Вычисляемая производная от функции
{
    double delta = 0.01;
    return (f(x + delta) - f(x)) / delta;
}

double math_deriv(double x) // Математически строгая производная
{
    return 3 * cos(x) - 2 * x + 1;
}

void choice1()  // Обработка пункта первого
{
    int a = -4; // Нижняя граница
    int b = 3;  // Верхняя граница
    double h = 0.35;    // Шаг приращения
    int tab = 10;   // Табуляция для форматированного вывода
    cout<<setw(tab)<<"x"<<setw(tab)<<"f(x)"<<setw(tab)<<"~f'(x)"<<setw(tab)<<"f'(x)"<<endl;
    for (double x = a; x <= b; x += h)
    {
        cout<<setprecision(2)<<setw(tab)<<x<<setw(tab)<<f(x)<<setw(tab)<<d(x)<<setw(tab)<<math_deriv(x)<<endl;
    }
}

void choice2()  // Обработка пункта второго
{
    int a = -4; // Нижняя граница
    int b = 3;  // Верхняя граница
    double h = 0.35;    // Шаг приращения
    int tab = 10;   // Табуляция для форматированного вывода
    double f_min = f(a);    // Минимальное табличное значение функции
    double f_max = f(a);    // Максимальное табличное значение функции
    double x_max = a;   // Аргумент максимального табличного значения функции
    double x_min = a;   // Аргумент минимального табличного значения функции
    cout<<setw(tab)<<"x"<<setw(tab)<<"f(x)"<<setw(tab)<<"~f'(x)"<<setw(tab)<<"f'(x)"<<endl;
    for (double x = a; x <= b; x += h)
    {
        cout<<setprecision(2)<<setw(tab)<<x<<setw(tab)<<f(x)<<setw(tab)<<d(x)<<setw(tab)<<math_deriv(x)<<endl;

        if (f_min > f(x))   // Ищем минимальное табличное значение функции и его аргумент
        {
            f_min = f(x);
            x_min = x;
        }

        if (f_max < f(x))   // Ищем максимальное табличное значение функции и его аргумент
        {
            f_max = f(x);
            x_max = x;
        }
    }
    cout<<"f_max = "<<f_max<<" x = "<<x_max<<endl;
    cout<<"f_nim = "<<f_min<<" x = "<<x_min<<endl;
}

void choice3()  // Обработка третьего выбора
{
    int a = -4; // Нижняя граница
    int b = 3;  // Верхняя граница
    double h = 0.35;    // Шаг приращения
    //int tab = 10;   // Табуляция для форматированного вывода
    //cout<<setw(tab)<<"x"<<setw(tab)<<"f(x)"<<setw(tab)<<"~f'(x)"<<setw(tab)<<"f'(x)"<<endl;
    for (double x = a; x <= b; x += h)
    {
        //cout<<setprecision(2)<<setw(tab)<<x<<setw(tab)<<f(x)<<setw(tab)<<d(x)<<setw(tab)<<math_deriv(x)<<endl;
        if (f(x)<0 && f(x + h)>0)
        {
            cout<<"["<<x<<", "<<x + h<<"]"<<endl;
        }

    }

}

void choice4()
{
    int a = -4; // Нижняя граница
    int b = 3;  // Верхняя граница
    double h = 0.35;    // Шаг приращения
    int tab = 10;   // Табуляция для форматированного вывода
    cout<<"Вычисление среднего арифметического с использованием оператора цикла с параметром"<<endl;
    cout<<setw(tab)<<"x"<<setw(tab)<<"f(x)"<<setw(tab)<<"~f'(x)"<<setw(tab)<<"f'(x)"<<endl;
    int items = 0;  // Количество элементов
    double sum = 0; // Сумма
    for (double x = a; x <= b; x += h)
    {
        cout<<setprecision(2)<<setw(tab)<<x<<setw(tab)<<f(x)<<setw(tab)<<d(x)<<setw(tab)<<math_deriv(x)<<endl;
        sum += f(x);
        items++;
    }
    cout<<"Среднее арифметическое = "<<sum / (items * 1.0)<<endl;

    cout<<"Вычисление среднего гармонического для отрицательных значений с использованием оператора цикла с постусловием"<<endl;

    // Обнуляем нужные переменные
    sum = 0;
    items = 0;

    double a_c = a; // Копия переменной a для цикла
    double b_c = b; // Копия переменной b для цикла

    do
    {
        if (f(a_c) < 0)
        {
            sum += 1 / f(a_c);
            items++;
        }
        //sum += f(a_c);

        a_c += h;
    } while (a_c <= b_c);
    cout<<"Среднее гармоническое для отрицательных значений функции равно "<< items / sum<<endl;

    // Оператор цикла с предусловием, вычисление среднего геометрического для положительных значений

    // Сбрасываем нужные переменные
    a_c = a;
    b_c = b;
    items = 0;
    double mul = 1; // Для подсчёта произведения
    while(a_c <= b_c)
    {
        if (f(a_c) > 0)
        {
            mul *= f(a_c);
            items++;
        }
        a_c += h;
    }
    cout<<"Среднее геометрическое для положительных чисел (оператор цикла с предусловием) равно "<<pow(mul, 1.0/items)<<endl;
}

double dispx1(double x,  double epsilon)  // Отрицательный разброс для дихотомии
{
    return x - epsilon;
}

double dispx2(double x,  double epsilon)    // Положительный разброс для дисперсии
{
    return x + epsilon;
}


void choice5()  // Поиск нулей функции итерационным методом дихотомии и Ньютона
{
    cout<<"Поиск нулей функции итерационным методом дихотомии и Ньютона"<<endl;
    double a = -4; // Нижняя граница
    double b = 3;  // Верхняя граница
    double a_n = a; // Для метода Ньютона
    double b_n = b; // Для метода Ньютона
    double epsilon; // Погрешность
    cout<<"epsilon = ";
    cin>>epsilon;
    double x = (a + b) / 2; // Находим середину отрезка
    double x1, x2;  // Разброс от погрешности
    while(abs(f(x)) > epsilon)
    {
        x1 = dispx1(x, epsilon);
        x2 = dispx2(x, epsilon);
        if (abs(f(x1)) < abs(f(x2)))
        {
            b = x1;
        }
        else
        {
            a = x2;
        }

        x = (a + b)/2;
    }
    cout<<"Метод дихотомии: x = "<<x<<endl;

    // Находим нули функции методом Ньютона
    x = (a_n + b_n)/2;
    while (abs(f(x)) > epsilon)
    {
        x = x - f(x)/d(x);
    }
    cout<<"Метод Ньютона: x = "<<x<<endl;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    cout<<"Лабораторная работа № 1 по объектно-ориентированному программированию\n";
    cout<<"Выполнил: Аметов И.И., ТМБО-01-15\n";
    cout<<"Функция: f(x) = 3*sin(x) - x^2 + x + 4\n";
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
        default:
            cout<<"Некорректный ввод\n";
            break;
        }
    }
    return 0;
}
