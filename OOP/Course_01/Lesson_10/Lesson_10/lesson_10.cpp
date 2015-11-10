#include "lesson_10.h"

void fillArrayRand(qreal *V, qreal ax, qreal bx)
{   // Заполнение некоторого массива случайными данными.
    for (int i = 0; i < N; i++)
    {
        V[i] = (bx - ax)*rand()/RAND_MAX + ax;
    }
}

void initRandom()
{   // Инициализация генератора случайных чисел.
    srand(time(NULL));
}

void printArray(qreal *V)
{   // Вывести на печать содержимое массива.
    for (int i = 0; i < N; ++i)
        cout << i << " element: " << V[i] << endl;
}

void swapElements (qreal *a, qreal *b)
{   // Перестановка двух элементов
    qreal t = *a;
    *a = *b;
    *b = t;
}

void selectionSort (qreal *V)
{   // Сортировка выбором.
    int temp;
    for (int i = 0; i < N - 1; ++i)
    {
        temp = i;
        for (int j = i+1; j < N; ++j)
            if (V[temp] < V[j]) temp = j;
        if (V[temp] != V[i]) swapElements (&V[temp], &V[i]);
    }
}

bool writeVectFile (char *nameF, qreal *V)
{   // Запись вектора в файл.
    ofstream fout(nameF);
    if (!fout)
    {
        cerr << "File is not open\n";

        return false;
    }
    for (int i = 0; i < N; ++i)
        fout << V[i] <<endl;
    return true;
}

void bubbleSort (qreal *V)
{   // Пузырьковая сортировка.
    for (int i = 0; i <= N - 2; i++)
        for (int j = N - 1; j >= i; j--)
            if (V[j] > V[j - 1]) swapElements(&V[j], &V[j - 1]);
}
