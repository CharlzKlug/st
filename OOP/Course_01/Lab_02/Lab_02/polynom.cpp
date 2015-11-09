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
        cout<<"Коэффициент "<<polynomOrder<<": "<<someCoefs[polynomOrder]<<endl;
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
                        qreal *myPoly, qreal ax, qreal bx, int dotCount )
{   // Вычисление значений полинома на отрезке [ax, bx] и занесение в массив myPoly.
    qreal step = (bx - ax)/(dotCount + one);
    int k = 0;
    for (qreal i = ax; i <= bx; i += step)
    {
        myPoly[k] = poly(coefs, polyLevel, i);
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

