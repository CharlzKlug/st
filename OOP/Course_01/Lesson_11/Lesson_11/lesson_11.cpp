#include "lesson_11.h"
char menu(string *itemMenu, char *hot)
{   // Реализация меню.
    int i = 0;
    while (hot[i] != '\0')
    {
        cout << itemMenu[i] << endl;
        i++;
    }
    cout << "X - Выход из программы" << endl;
    cout << "Нажмите клавишу ";
    char code;
    cin >> code;
    code = toupper(code);
    return code;
}

void copyVector (qreal *rV, qreal *sV, int n)
{   // Копирование элементов из sV массива в массив rV.
    for (int i = 0; i < n; i++)
        rV[i] = sV[i];
}

void showVector(qreal *V, int n)
{   // Вывод на печать содержимого массива.
    for (int i = 0; i < n; i++)
        cout << i << " элемент: " << V[i] << endl;
}

void inputVectRnd (qreal *V, qreal lowBound, qreal highBound, int n)
{   // Заполнение массива случайными числами в некотором промежутке.
    for (int i = 0; i < n; i++)
        V[i] = (int)(rand()*(highBound - lowBound) / RAND_MAX + lowBound);
}

qreal sumItemAfterFirstMinus (qreal *V, int m)
{   // Возвращает сумму положительных чисел после первого отрицательного.
    qreal sum = 0;
    bool minusEncountered = false;
    for (int i = 0; i < m; i++)
    {
        if (V[i] > 0) sum += V[i] * minusEncountered;
        if (V[i] < 0) minusEncountered = true;
    }
    return sum;
}

qreal sumItemAfterLastPlus(qreal *V, int n)
{   // Сумма элементов после последнего положительного.
    qreal sum = 0;
    int i = n - 1;
    while (V[i] < 0 && i >= 0)
    {
        sum += V[i];
        i--;
    }
    if (i >= 0 && V[i] <= 0) sum = 0;
    return sum;
}

qreal sumItemBetweenMinus (qreal *V, int n, int *i1, int *i2)
{   // Вычисляем сумму элементов между первыми двумя отрицательными элементами.
    qreal sum = 0;
    *i1 = -1;
    *i2 = -1;
    int i = 0;
    while (*i2 < 0 && i < n)
    {
        if (V[i] > 0 && *i1 > -1 && *i2 < 0) sum += V[i];
        if (V[i] < 0 && *i1 > -1) *i2 = i;
        if (V[i] < 0 && *i1 < 0) *i1 = i;
        i++;
    }
    if (*i2 < 0) sum = 0;
    return sum;
}

void createPositiveItem(qreal *V, int *m)
{   // Создаём массив из положительных значений.
    int i = 0;
    while (i < *m)
    {
        if (V[i] > 0) i++;
        else
        {
            for (int j = i; j < *m - 1; j++)
                V[j] = V[j + 1];
            *m = *m -1;
        }
    }
    //return m;
}
