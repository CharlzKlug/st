#include "Lesson_07.h"
//#include <cmath>

using namespace std;





char menu()
{
    cout<<"Выберите исполняемый вариант:"<<endl;
    cout<<"A - Напечатать таблицу значений функции"<<endl;
    cout<<"B - Сменить условия задачи"<<endl;
    cout<<"С - Найти максимум и минимум функции"<<endl;
    cout<<"D - Найти ноль функции методом дихотомии"<<endl;
    cout<<"E - Найти ноль функции методом Ньютона"<<endl;
    cout<<"F - Найти точку пересечения двух функций методом дихотомии"<<endl;
    cout<<"X - Выход из программы"<<endl;
    char select;    // Выбранный вариант
    cin>>select;
    return toupper(select);

}

void showTable(TFunc f)
{
    cout<<"Печать таблицы значений функции"<<endl;
    qreal a;    // Меньшая граница
    qreal b;    // Большая граница
    qreal h;    // Шаг
    cout<<"Нижняя граница:";
    cin>>a;
    cout<<"Верхняя граница:";
    cin>>b;
    cout<<"Шаг:";
    cin>>h;
    cout<<setprecision(2)<<setw(6)<<fixed;
    cout<<"x"<<setw(6)<<"f(x)";
    for (qreal i = a; i <= b; i += h)
    {
        cout<<setw(6)<<i<<setw(6)<<f(i)<<endl;
    }
}

void functionMaxMin(TFunc f, qreal a, qreal b, qreal h)
{   // Вычисление максимума и минимума
    qreal Max = f(a);   // Максимальное значение будет храниться здесь
    qreal Min = Max;    // Минимальное значение будет храниться здесь
    qreal t;    // Временная переменная
    for (qreal i = a; i <= b; i += h)
    {
        t = f(i);
        if (t > Max) Max = t;
        if (t < Min) Min = t;

    }
    cout<<"Max = "<<Max<<endl;
    cout<<"Min = "<<Min<<endl;
}

void dixotomyZero(TFunc f, qreal a, qreal b, qreal h, qreal epsilon)
{   // Вычисление нуля функции методом дихотомии. Итерационно и рекурсивно.
    cout<<"Вычисление нуля функции методом дихотомии."<<endl;
    cout<<"Итерационный метод."<<endl;
    for (qreal i = a; i < b; i += h)
    {
        if (f(i) * f(i + h) < 0) dixotomyIter(f, i, i + h, epsilon);
    }
    cout<<"Рекурсивный метод"<<endl;
    for (qreal i = a; i < b; i += h)
    {
        if (f(i) * f(i + h) < 0)
        {
            cout<<"x = "<<dixotomyRecur(f, i, i + h, epsilon)<<endl;
        }
    }

}

void dixotomyIter(TFunc f, qreal a, qreal b, qreal epsilon)
{   // Метод дихотомии. Итерационный подход.
    qreal middle;   // Середина отрезка ab
    while (fabs(f(middle = (a + b) / 2)) > epsilon) {
        if (f(a) * f(middle) < 0)
        {
            b = middle;
        }
        if (f(middle) * f(b) < 0)
        {
            a = middle;
        }
    }
    cout<<"x = "<<middle<<endl;
}

qreal dixotomyRecur (TFunc f, qreal a, qreal b, qreal epsilon)
{   // Метод дихотомии. Рекурсивный метод.
    qreal middle = (a + b) / 2; // Середина отрезка ab
    if (fabs(f(middle)) > epsilon)
    {
        if (f(a) * f(middle) < 0) dixotomyRecur(f, a, middle, epsilon);
        if (f(middle) * f(b) < 0) dixotomyRecur(f, middle, b, epsilon);
    }
    return middle;
}

void NewtonZero(TFunc f, qreal a, qreal b, qreal h, qreal epsilon)
{   // Вычисление нуля функции методом Ньютона. Итерационно и рекурсивно.
    cout<<"Вычисление нуля функции методом Ньютона."<<endl;
    cout<<"Итерационный метод."<<endl;
    for (qreal i = a; i < b; i += h)
    {
        if (f(i) * f(i + h) < 0)
            cout<<"x = "<<NewtonIter(f, i, i + h, epsilon)<<endl;
    }
    cout<<"Рекурсивный метод"<<endl;
    for (qreal i = a; i < b; i += h)
    {
        if (f(i) * f(i + h) < 0)
        {
            cout<<"x = "<<NewtonRecur(f, i, i + h, epsilon)<<endl;
        }
    }
}

qreal NewtonIter (TFunc f, qreal a, qreal b, qreal epsilon)
{    // Поиск нуля итерационным методом Ньютона
    qreal x = (a + b)/2;    // Серединное значение для начала

    while (fabs(f(x) / d(f, x)) > epsilon) {
        x = x - f(x) / d(f, x);
    }
    return x;
}

qreal NewtonRecur (TFunc f, qreal a, qreal b, qreal epsilon)
{   // Функция - обёртка для рекурсии
    return NewtonInner(f, (a + b) / 2, epsilon);
}

qreal NewtonInner (TFunc f, qreal x, qreal epsilon)
{   // Метод Ньютона рекурсивная внутренняя функция
    if (fabs(f(x)/d(f, x)) > epsilon)
        return NewtonInner(f, x - f(x) / d(f, x), epsilon);
    return x;
}

qreal d(TFunc f, qreal x)
{
    return (f(x + 0.01) - f(x)) / 0.01;
}

void intersectionDixotomy (TFunc f1, TFunc f2, qreal a, qreal b, qreal h, qreal epsilon)
{   // Главная функция поиска пересечения методом дихотомии
    for (qreal i = a; i<b; i += h)
    {
        //cout<<(f1(i) - f2(i)) * (f1(i + h) - f2(i + h))<<endl;
        if ((f1(i) - f2(i)) * (f1(i + h) - f2(i + h)) < 0)
            cout<<"x = "<<searchIntersection(f1, f2, i, i + h, epsilon)<<endl;
    }
}

qreal searchIntersection (TFunc f1, TFunc f2, qreal a, qreal b, qreal epsilon)
{   // Рекурсивный поиск точек пересечения
    qreal middle = (a + b) / 2;
    if (fabs(a - b) > epsilon)
    {
        if ((f1(middle) - f2(middle)) * (f1(b) - f2(b)) < 0)
            return searchIntersection(f1, f2, middle, b, epsilon);
        if ((f1(a) - f2(a)) * (f1(middle) - f2(middle)) < 0)
            return searchIntersection(f1, f2, a, middle, epsilon);
    }
    return middle;
}

qreal someLine (qreal x)
{   // Просто функция
    return x;
}

long buildNewNumber(long n)
{   // Строим число из нечётных цифр числа
    //long n = rand() * rand();
    return newNumberRecur(n, 0, 1);
    //return 2222222;
}

long newNumberRecur(long n, long r, int k)
{   // Функция для генерации нового числа
    //return 33333;
    if (n == 0) return r;
    int fig = n % 10;
    if (fig % 2 != 0) return newNumberRecur(n / 10, r + k * fig, k * 10);
    return newNumberRecur(n / 10, r, k);
}

long evenSum (long n)
{   // Вычисляем сумму чётных цифр числа n
    long sum = 0;
    int fig;
    while (n)
    {
        fig = n % 10;
        if (fig % 2 == 0) sum = sum + fig;
        n = n /10;
    }
    return sum;
}

qreal oddAverage (long n)
{   // Считаем среднее арифметическое
    qreal sum = 0;
    qreal k = 0;
    int fig;
    while (n)
    {
        fig = n % 10;
        if (fig % 2 != 0) {sum = sum + fig; k++;}
        n = n / 10;

    }
    return sum / k;
}
