

#include <QCoreApplication>
#include <iostream>
#include <cmath>
#include <ctime>
#include <iomanip>
//#include <random>
using namespace std;

char menu()
{
    cout<<"A - proverka na nalichie cifry m v chisle\n";
    cout<<"B - grafik\n";
    cout<<"C - вернуть число n без m"<<endl;
    cout<<"D - вернуть число n без двойного m"<<endl;
    cout<<"E - вычислить длину кривой некоторой функции"<<endl;
    cout<<"X - vyhod.\n";
    char ch;
    cin>>ch;
    return toupper(ch);
}

bool CheckWithM(long n, int m)
{
    bool result = false;
    while(n && !result)
    {
        if (n%10 == m)
        {
            result = true;
        }
        n = n / 10;
    }
    return result;
}

void PresentM() // Если в тексте есть цифра m, то возвращается true
{
    srand(time(0));
    cout<<"Vvedite cifru m:";
    int m;
    cin>>m;
    long n = rand();
    cout<<"n = "<<n<<"\n";
    if (CheckWithM(n, m))
    {
        cout<<"true\n";
    }
    else
    {
        cout<<"false\n";
    }
}

void Curve()
{
    for (double i = 0; i<10; i = i + 0.1)
    {
        cout<<setw(sin(i) * 10 + 20)<<"x\n";
    }
}

void withoutM()
{   // Печать числа n без цифры m
    int m;  // Исключаемая цифра
    cout<<"Возвращает число n без цифры m"<<endl;
    cout<<"Введите m:";
    cin>>m;
    long n = rand();    // Сокращаемое число
    cout<<"n начальное:"<<n<<endl;
    long nn = 0;    // Результирующее значение
    int k = 1;  // Множитель на 10
    int fig;    // Промежуточное значение
    while (n)
    {
        fig = n % 10;
        if (fig != m)
        {
            nn = nn + fig * k;
            k = k * 10;

        }
        n = n / 10;
    }
    cout<<"n конечное:"<<nn<<endl;
}

void withoutDoubleM()
{   // Печать числа n без двойных цифр m
    int m;  // Исключаемая цифра
    cout<<"Возвращает число n без двойных цифры m"<<endl;
    cout<<"Введите m:";
    cin>>m;
    long n;    // Сокращаемое число
    cout<<"Введите n:";
    cin>>n;
    //cout<<"n начальное:"<<n<<endl;
    if (n<10)
    {
        cout<<"n конечное:"<<n<<endl;
    }
    else
    {
        int fig1 = n%10;    // Первая цифра с конца
        int fig2;   // Вторая цифра с конца
        long nn = 0;    // Результат конечный
        int k = 1;  // Множитель на 10 в какой-то степени
        n = n / 10;
        while (n)
        {
            fig2 = n%10;
            if (fig2 != fig1)
            {   // Если соседние цифры разные
                nn = nn + fig1 * k;
                k = k * 10;
                fig1 = fig2;
            }
            else
            {   // Если соседние цифры одинаковы
                n = n /10;
                fig1 = n % 10;
            }
            n = n / 10;
        }
        nn = nn + fig1 * k;
        cout<<"n конечное:"<<nn<<endl;
    }
}

typedef qreal TFunc (qreal);

void curveLength (TFunc f, qreal a, qreal b, qreal h)
{   // Вычисляем длину кривой
    qreal s = 0;    // Результат
    for (qreal i = a; i < b; i = i + h)
    {
        s = s + sqrt(h * h + (f(i) - f(i + h)) * (f(i) - f(i + h)));
    }
    cout<<"Длина кривой равна:"<<s<<endl;
}

qreal myFunction (qreal x)
{
    return x;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    char ch;
    while((ch = menu()) != 'X')
    {
        switch (ch) {
        case 'A':
            PresentM();
            break;
        case 'B':
            Curve();
            break;
        case 'C':
            withoutM();
            break;
        case 'D':
            withoutDoubleM();
            break;
        case 'E':
            curveLength(myFunction, 0, 10, 0.01);
            break;
        default:
            cout<<"Oshibka! Vvedite korrektnoe znachenie.\n";
            break;
        }
    }

    return 0;
}

