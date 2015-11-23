#include "controlwork_01.h"

char selectMenu (string *menuStrings, char *hotKeys)
{   // Реализация выбора меню.
    int i = 0;
    while (hotKeys[i] != '\0')
    {
        cout << menuStrings[i] << endl;
        i++;
    }
    cout << "Выберите меню:";
    char selectedMenu;
    cin >> selectedMenu;
    selectedMenu = toupper(selectedMenu);
    return selectedMenu;
}

void loadRandomCoefs (qreal *coefs, int total)
{   // Загрузка случайных коэффициентов с генератора случайных чисел.
    srand(time(0));
    for (int i = 0; i < total; i++)
    {
        coefs[i] = ((qreal) rand()) / RAND_MAX *10 - 5;
    }
}

int indexMaxABS (qreal *V, int total)
{   // Индекс элемента с максимальным модулем.
    int indexMaxMod = 0;
    for (int i = 1; i < total; i++)
    {
        if (fabs(V[indexMaxMod]) < fabs(V[i])) indexMaxMod = i;
    }
    return indexMaxMod;
}

void printArray (qreal *V, int total)
{   // Печать элементов массива.
    for (int i = 0; i < total; i++)
        cout << fixed << setw(10) << "Элемент " << i << ": " << V[i] << endl;
}

qreal sumAfterFirstPos (qreal *V, int n)
{   // Возвращает сумму элементов массива после первого положительного элемента.
    qreal sum = 0;
    bool positiveFound = false;
    for (int i = 0; i < n; i++)
    {
        sum += V[i] * positiveFound;
        if (V[i] > 0) positiveFound = true;
    }
    return sum;
}

void swapElements(qreal &i, qreal &j)
{   // Замена двух значений.
    qreal temp;
    temp = i;
    i = j;
    j = temp;
}

void sortCaprice (qreal *V, int total, qreal a, qreal b)
{   // Капризная сортировка.
    for (int i = 0; i < total - 1; i++)
    {
        int k = i;
        while (!((int)V[k] >= a && (int)V[k] <= b) && k < total)
        {
            k++;
        }
        if (k != i && k < total) swapElements(V[k], V[i]);
    }
}
