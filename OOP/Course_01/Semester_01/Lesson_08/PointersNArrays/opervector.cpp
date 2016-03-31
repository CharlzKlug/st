#include "opervector.h"


char menu()
{   // Функция для выбора варианта меню.
    cout<<"Работа с указателями и массивами."<<endl;
    cout<<"Выберите исполняемый вариант:"<<endl;
    cout<<"A - Сдвиг чётных и нечётных индексов массива"<<endl;
    cout<<"B - Найти наибольший отрицательный элемент массива"<<endl;
    cout<<"С - Найти наибольший элемент массива"<<endl;
    cout<<"D - Найти два наибольших элемента массива"<<endl;
    cout<<"E - Сформировать векторы из положительных и отрицательных чисел и вывести количество отрицательных"<<endl;
    cout<<"F - Найти количество смен знаков"<<endl;
    cout<<"G - Инверсия вектора"<<endl;
    cout<<"H - Сдвиг отрицательных элементов массива"<<endl;
    cout<<"X - Выход из программы"<<endl;

    char select;    // Выбранный вариант
    cin>>select;
    return toupper(select);
}


void fillVect(qreal *V, qreal a, qreal b)
{   // Заполнение массива *V случайными значениями из [a,b].
    for (int i = 0; i<N; i++)
    {
        *(V + i) = (((qreal)rand())/RAND_MAX)*(b - a) + a;
    }
}

void outputArray (qreal *V)
{   // Вывод значений массива.
    for (int i = 0; i < N; i++)
        cout<<i<<" element: "<<V[i]<<endl;
}

void moveItemOddorEven(qreal *V, bool flag)
{   // Смещение чётных или нечётных индексов массива.
    for (int i = flag; i <= (N - 1)/2; i += 2)
    {
        qreal temp = *(V + i);
        for (int k = i; k < (N - 1); k++)
        {
            *(V + k) = *(V + k + 1);
        }
        *(V + N - 1) = temp;
    }
}

int maxNegative (qreal *V)
{   // Нахождение наибольшего отрицательного элемента массива.
    int m = -1;
    for (int i = 0; i < N; i++)
    {
        if (m > -1)
        {
            if (*(V + m) < *(V + i) && *(V + i) < 0)
                m = i;
        }
        else
        {
            if (*(V + i) < 0) m = i;
        }
    }
    return m;
}

int maxElement (qreal *V)
{   // Нахождение индекса максимального элемента.
    int m = 0;
    for (int i = 1; i<N; i++)
        if (V[m]<V[i]) m = i;
    return m;
}

void twoBiggest (qreal *V)
{   // Нахождение двух наибольших значений массива.
    for (int i = 0; i < 2; i++)
    {
        int m = i;
        for (int k = i + 1; k < N; k++)
            if (*(V + m) < *(V + k)) m = k;
        qreal temp = *(V + i);
        *(V + i) = *(V + m);
        *(V + m) = temp;
    }
}

void fillZero (qreal *V)
{   // Заполнение массива нулями.
    for (int i = 0; i < N; i++)
        V[i] = 0;
}

int negativeCount (qreal *V, qreal *W)
{   // Возвращаем количество отрицательных элементов, попутно формируя массив из отрицательных элементов.
    int m = 0;
    for (int i = 0; i < N; )
        if (V[i] < 0)
        {
            W[m] = V[i];
            m++;
            for (int k = i; k < N - 1; k++)
                V[k] = V[k + 1];
            if (m == 1) V[N - 1] = 0;
        }
        else i++;
    return m;
}

int countChange (qreal *V)
{   // Подсчёт смены знаков.
    int count = 0;
    for (int i = 0; i < N - 2; i++)
        if (V[i] * V[i + 1] < 0) count++;
    return count;
}

void inverse (qreal v[])
{   // Инверсия массива
    int i = 0, j = N - 1;
    while (i < j)
    {
        qreal t = v[i]; v[i] = v[j]; v[j] = t;
        ++i; --j;
    }
}

void moveNegItem (TVect V)
{   // Сдвиг отрицательных элементов в конец массива
    int i = 0, m = 0;
    while (i < N - m)
    {
        if (V[i] >= 0) ++i;
        else
        {
            ++m;
            qreal t = V[i];
            for (int k = i; k < N - 1; ++k) V[k] = V[k + 1];
            V[N - 1] = t;
        }
    }
}
