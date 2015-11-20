#include "polynom.h"


char menu()
{   // Функция для выбора варианта меню.
    cout<<"Работа с полиномом, массивами и указателями."<<endl;
    cout<<"Выберите исполняемый вариант:"<<endl;
    cout<<"A - Вывести начальные значения"<<endl;
    cout<<"B - Сменить условия задачи"<<endl;
    cout<<"С - Загрузить значения коэффициентов с клавиатуры"<<endl;
    cout<<"D - Сгенерировать случайные коэффициенты"<<endl;
    cout<<"E - Прочитать коэффициенты из файла"<<endl;
    cout<<"F - Вычисление значений полинома и его производной на отрезке"<<endl;
    cout<<"G - Упорядочить массив значений полинома по убыванию сортировкой выбором"<<endl;
    cout<<"H - Упорядочить массив значений полинома по убыванию пузырьковой сортировкой"<<endl;
    cout<<"K - Упорядочить массив значений полинома по убыванию сортировкой методом вставки"<<endl;
    cout<<"L - Инвертировать массив значений полинома"<<endl;
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
        cout<<fixed<<setprecision(3)<<"Элемент "<<setw(2)<<polynomOrder<<": "<<setw(7)<<someCoefs[polynomOrder]<<endl;
        //        cout<<someCoefs[polynomOrder]<<" ";
        polynomOrder = polynomOrder - 1;
    }
    cout<<endl;
}

qreal poly (TCoef coefs, int polyLevel, qreal x)
{   // Вычисление значения полинома методом Горнера
    qreal result = coefs[polyLevel];

    while (polyLevel) {
        result = result * x;
        polyLevel--;
        result += coefs[polyLevel];
    }

    return result;
}


void calculateEdgePoly (TCoef coefs, int polyLevel,
                        qreal *myPoly, qreal *myDPoly, qreal ax, qreal bx, int dotCount )
{   // Вычисление значений полинома на отрезке [ax, bx] и занесение в массив myPoly.
    // Вычисление значений производной полинома на отрезке [ax, bx] и занесение в массив myDPoly.
    qreal step = (bx - ax)/(dotCount + one);
    int k = 0;
    cout <<fixed <<  setprecision(2)<< setw(10) << "x" << setw(10) << "f" << setw(10) << "f'" << endl;
    for (qreal i = ax; i <= bx; i += step)
    {
        myPoly[k] = poly(coefs, polyLevel, i);
        myDPoly[k] = polyD(coefs, polyLevel, i);
        cout <<  setw(10) << i << setw(10) << myPoly[k] << setw(10) << myDPoly[k] << endl;
        k++;
    }
}


qreal polyD (TCoef coefs, int polyLevel, qreal x)
{   // Вычисление значения производной полинома от аргумента x.
    qreal result = polyLevel * coefs[polyLevel];
    while (polyLevel > one) {
        result *= x;
        polyLevel--;
        result += coefs[polyLevel];
    }
    return result;
}

void calculateEdgeDPoly(TCoef coefs, int polyLevel,
                        TDPoly myDPoly, qreal ax, qreal bx, int dotCount )
{   // Вычисление значений производной полинома на отрезке [ax, bx] и занесение в массив myPoly.
    qreal step = (bx - ax)/(dotCount - one);

    for (int i = zero; i <= dotCount - one; i++)
    {
        myDPoly[i] = poly(coefs, polyLevel, ax + step * i);
    }
}

void highOrder (TFunc myFunc, int x)
{
    cout<<myFunc(x)<<"\n";
}

int someFunc (int x)
{
    return x + x;
}

void loadCoefKeyboard(TCoef myCoefs, int order)
{   // Загрузка коэффициентов с клавиатуры.
    for (int i = 0; i<=order; i++)
    {
        cout<<"Коэффициент "<<i<<": ";
        cin>>myCoefs[i];
    }
}

void loadRandomCoefs (qreal *coefs, int order)
{   // Загрузка случайных коэффициентов с генератора случайных чисел.
    srand(time(0));
    for (int i = 0; i <= order; i++)
    {
        coefs[i] = ((qreal) rand()) / RAND_MAX *10 - 5;
    }
}

void loadCoefsFile(qreal *coefs, int order, char *fileName)
{   // Загрузка коэффициентов из файла.
    fstream F;
    qreal b;

    F.open(fileName, ios::in);
    for (int i = 0; i <= order; i++)
    {
        F>>b;
        coefs[i] = b;
    }
    F.close();

}

qreal calcStep (qreal b, qreal a, int dotCount)
{   // Вычисление шага на отрезке
    return (a - b) / (dotCount++);
}

void swapElements (qreal *a, qreal *b)
{   // Перестановка двух элементов
    qreal t = *a;
    *a = *b;
    *b = t;
}

void selectionSort (qreal *V, int n)
{   // Сортировка выбором.
    int temp;
    for (int i = 0; i < n - 1; ++i)
    {
        temp = i;
        for (int j = i+1; j < n; ++j)
            if (V[temp] < V[j]) temp = j;
        if (V[temp] != V[i]) swapElements (&V[temp], &V[i]);
    }
}

void bubbleSort(qreal *a, int n) {  // Пузырьковая сортировка.
    for (int j = 0; j < n-1; j++) {
        for (int i = 0; i < n-j-1; i++) {
            if (a[i] < a[i+1]) {
                swapElements(&a[i], &a[i+1]);
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

void inverseArray(qreal *V, int total)
{   // Инверсия массива. *V - указатель на массив, total - общее количество элементов в массиве.
    total--;
    for (int i = 0; i < total; i++)
    {
        swapElements(&V[i], &V[total]);
    }
}
