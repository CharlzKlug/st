#include "polynom.h"

qreal poly(TCoef coefs, int k, qreal x)
{   // Функция, возвращающая значение полинома с коэффициентами coefs, количеством коэффициентов k для аргумента x.
    // Используется схема Горнера.

    qreal result = coefs[k];

    while (k) {
        result = result * x;
        k = k - 1;
        result = result + coefs[k];
    }

    return result;
}

char menu()
{   // Функция для выбора варианта меню.
    cout<<"Выберите исполняемый вариант:"<<endl;
    cout<<"A - Вывести начальные значения"<<endl;
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

void outputCoefs(TCoef someCoefs, int polynomOrder)
{   // Выдача всех коэффициентов полинома
    //polynomOrder++;
    while (polynomOrder > -1)
    {
        cout<<someCoefs[polynomOrder]<<" ";
        polynomOrder = polynomOrder - 1;
    }
    cout<<endl;
}
