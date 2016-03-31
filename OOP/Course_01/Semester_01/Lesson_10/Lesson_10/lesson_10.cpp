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

bool readVectFile (string fileName, qreal *V)
{   // Считывание вектора из файла.
    char *cstr = new char[fileName.length() + 1];
    strcpy(cstr, fileName.c_str());
    ifstream fin (cstr);
    if (!fin)
    {
        cerr << "File is not open!\n";
        delete [] cstr;
        return false;
    }
    int m = 0;
    while (m < N)
    {
        fin >> V[m];
        ++m;
    }
    delete [] cstr;
    return true;
}

/*
void bubbleSort (qreal *V)
{   // Пузырьковая сортировка.
    for (int i = 0; i <= N - 2; i++)
        for (int j = N - 1; j >= i; j--)
            if (V[j] > V[j - 1])
            {
                qreal temp = V[j];
                V[j] = V[j - 1];
                V[j - 1] = temp;
                //swapElements(&V[j], &V[j - 1]);
            }
}
*/

void bubbleSort(qreal *a) {
     for (int j = 0; j < N-1; j++) {
         for (int i = 0; i < N-j-1; i++) {
             if (a[i] < a[i+1]) {
                 swapElements(&a[i], &a[i+1]);
                 //qreal b = a[i]; //change for elements
                 //a[i] = a[i+1];
                 //a[i+1] = b;
             }
         }
     }
 }

void insertionSort (qreal *V, int n)
{   // Сортировка вставкой.
    qreal temp;
    int k;
    if (n > 1)
    for (int i = 1; i < n; i++)
    {
        temp = V[i];
        k = i;
        while (temp > V[k - 1] && k > 0)
        {
            V[k] = V[k - 1];
            V[k - 1] = temp;
            k--;
        }
    };
}

char menu (char *itemMenu[], char *hotKeys)
{   // Реализация меню.
    int i = 0;
    while (hotKeys[i] != '\0')
    {
        cout << itemMenu[i] << endl;
        ++i;

    }
cout << "X - Выход из программы" << endl;
    char code;
    for (; true; )
    {
        cout << "Код задания: ";
        cin >> code;
        code = toupper(code);
        if (code == 'X') {
            cout << "Нажмите [Enter]" << endl;
            exit(0);
        }
        if ('A' <= code && code <= 'G') return code;
    }

}

void flushVector(qreal *V)
{   // Обнуление некоторого вектора.
    for (int i = 0; i < N; i++)
        V[i] = 0;
}


void loadTestVector (qreal *V, qreal *testVector)
{   // Загрузка некоторого тестового вектора.
    flushVector(V);
    for (int i = 0; i < N; i++)
        V[i] = testVector[i];
}

