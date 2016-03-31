// Работа с манипуляторами
#include <QCoreApplication>
#include <iostream>
#include <ctime>
#include <cmath>
#include <iomanip>
using namespace std;

int selectedProgramm()
{
    cout<<"1) Сложение двух двузначных чисел\n";
    cout<<"2) Вычитание двух двузначных чисел\n";
    cout<<"3) Определить количество разных цифр в числе n, которых нет в числе m\n";
    cout<<"4) Вывод двузначных чисел кратных m в k колонках\n";
    cout<<"5) Завершение работы\n";
    int sp;
    cin>>sp;
    return sp;
}

void Addition()
{
    int a = (rand() * 90.0)/RAND_MAX + 10;
    int b = (rand() * 90.0)/RAND_MAX + 10;
    cout<<"a = "<<a<<"\n";
    cout<<"b = "<<b<<"\n";
    int r, addition;
    if (a%10 + b%10 > 9)
    {
        r = (a%10 + b%10)%10;
        addition = 1;
    }
    else
    {
        r = a%10 + b%10;
        addition = 0;
    }
    a = a /10;
    b = b /10;
    r = r + (a + b + addition)*10;
    cout<<"Addition: "<<r<<"\n";
}


void Differences()
{
    long n = rand(), m = rand(); // n - основное число, m - число, с отличающимися цифрами
    cout<<"n = "<<n<<" m = "<<m<<"\n";
    int n_seq = 0, m_seq = 0, fig;
    //cout<<(m_seq / (int) pow(10, fig))%10;
    while (m)
    {
        fig = m % 10;
        if ((m_seq / (int) pow(10, fig))%10 == 0)
        {
            m_seq = m_seq + pow(10.0, fig);
        }
        m = m / 10;
    }
    //cout<<"m_seq = "<<m_seq<<"\n";
    while (n)
    {
        fig = n % 10;
        if ((n_seq / (int) pow(10, fig))%10 == 0)
        {
            n_seq = n_seq + pow(10.0, fig);
        }
        n = n / 10;
    }
    //cout<<"n_seq = "<<n_seq<<"\n";
    int k = 0; // Счётчик различающихся цифр
    while(n_seq)
    {
        if (n_seq % 10 == 1 && n_seq % 10 != m_seq % 10)
        {
            k = k + 1;
        }
        n_seq = n_seq / 10;
        m_seq = m_seq / 10;
    }
    cout<<"Количество различающихся цифр - "<<k<<"\n";
}

void Subtraction()
{
    int a = (rand() * 90.0)/RAND_MAX + 10;
    int b = (rand() * 90.0)/RAND_MAX + 10;
    cout<<"a = "<<a<<"\n";
    cout<<"b = "<<b<<"\n";
    int c;
    int mul;
    if (a<b)
    {
        c = a;
        a = b;
        b = c;
        mul = -1;
    }
    else
    {
        mul = 1;
    }
    int sub;
    int r;
    if (a%10<b%10)
    {
        r = (a%10 + 10) - b%10;
        sub = -1;
    }
    else
    {
        r = a%10 - b%10; sub = 0;
    }
    a = a /10;
    b = b / 10;
    r = ((a + sub - b)*10 + r)*mul;
    cout<<"Subtraction result:"<<r<<"\n";
}

void Columns()
{
    int m, // число должно быть кратно m
            k; // k - количество столбцов
    cout<<"m = ";
    cin>>m;
    cout<<"k = ";
    cin>>k;
    int t = 1;// t - некоторый множитель
    while (t*m<10)
    {
        t = t + 1;
    }
    int c = 0; // c - счётчик столбцов
    while (t*m<100)
    {
        cout<<setw(4)<<t*m;
        c = c + 1;
        if (c>=k)
        {
            cout<<"\n";
            c = 0;
        }
        t = t + 1;
    }
    cout<<"\n";
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    srand(time(0));
    cout<<"Работа с манипуляторами\n";
    int sp;
    while((sp = selectedProgramm()) != 5)
    {
        switch (sp) {
        case 1:
            Addition();
            break;
        case 2:
            Subtraction();
            break;
        case 3:
            Differences();
            break;
        case 4:
            Columns();//BiggestRight();
            break;
        case 5:
            //LeftSum();
            break;
        case 6:
            //SmallerLeft();
            break;
        default:
            cout<<"Некорректный ввод!\n";
        }
    }
    return 0;
}
