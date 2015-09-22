#include <QCoreApplication>
#include <iostream>
#include <ctime>
#include <cmath>
using namespace std;

int selectedProgramm()
{
    cout<<"1) Определить НОД\n";
    cout<<"2) Заменить цифру n в числе на 0\n";
    cout<<"3) Исключить цифру n из числа\n";
    cout<<"4) Наибольшая цифра и её позиция справа\n";
    cout<<"5) Сумма цифр числа слева от наибольшего числа\n";
    cout<<"6) Наименьшая цифра и её позиция слева\n";
    cout<<"7) Завершение работы\n";
    int sp;
    cin>>sp;
    return sp;
}

long GetBigNumber(long someValue)
{
    return rand()%someValue +1;
}

void NOD()
{
    long a = GetBigNumber(50);
    long b = GetBigNumber(50);
    cout<<"a = "<<a<<"\n";
    cout<<"b = "<<b<<"\n";
    while (a && b) {
        if (a>b) a = a % b;
        else b = b % a;
    }
    cout<<"НОД:"<<a+b<<"\n\n";

}

void ReplaceN()
{
    long a = GetBigNumber(3000000);
    cout<<"a = "<<a<<"\n";
    long b = 0, k = 1, f;
    long number;
    cout<<"Введите заменяемое число:";
    cin>>number;
    while(a)
    {
        f = a%10;
        if (f != number)
        {
            b = b + f*k;

        }
        k = k*10;
        a = a/10;
    }
    cout<<"b = "<<b<<"\n";
}

void RemoveN()
{
    long a = GetBigNumber(3000000);
    cout<<"a = "<<a<<"\n";
    long b = 0, k = 1, f;
    long number;
    cout<<"Введите исключаемое число:";
    cin>>number;
    while(a)
    {
        f = a%10;
        if (f != number)
        {
            b = b + f*k;
            k = k*10;
        }

        a = a/10;
    }
    cout<<"b = "<<b<<"\n";

}

void BiggestRight()
{
    long a = GetBigNumber(3000000);
    cout<<"a = "<<a<<"\n";
    int BiggestNumber = 0, BiggestNumberPosition, currentPosition = 0, f;

    while (a)
    {
        f = a%10;
        if (BiggestNumber < f)
        {
            BiggestNumber = f;
            BiggestNumberPosition = currentPosition;
        }
        currentPosition = currentPosition + 1;
        a = a / 10;
    }
    cout<<"BiggestNumber = "<<BiggestNumber<<" Position = "<<BiggestNumberPosition<<"\n\n";

}

void LeftSum()
{
    long a = GetBigNumber(3000000);
    cout<<"a = "<<a<<"\n";
    int MaxNumber = 0, Sum = 0, f;
    while(a)
    {
        f = a%10;
        if (MaxNumber<f)
        {
            MaxNumber = f;
            Sum = MaxNumber;
        }
        else
        {
            Sum = Sum + f;
        }
        a = a / 10;
    }
    cout<<"Sum = "<<Sum<<"\n\n";
}

void SmallerLeft()
{
    long a = GetBigNumber(3000000);
    cout<<"a = "<<a<<"\n";
    int Min = 9, MinPos, f, currentPos = -1;
    while (a)
    {
        currentPos = currentPos + 1;
        f = a % 10;
        if (Min>f)
        {
            Min = f;
            MinPos = currentPos;
        }

        a = a / 10;

    }
    cout<<"Min = "<<Min<<" Pos = "<<currentPos - MinPos<<"\n";
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    srand(time(0));
    cout<<"Многофункциональная программа\n";
    int sp;
    while((sp = selectedProgramm()) != 7)
    {
        switch (sp) {
        case 1:
            NOD();
            break;
        case 2:
            ReplaceN();
            break;
        case 3:
            RemoveN();
            break;
        case 4:
            BiggestRight();
            break;
        case 5:
            LeftSum();
            break;
        case 6:
            SmallerLeft();
            break;
        default:
            cout<<"Некорректный ввод!\n";
        }
    }
    return 0;
}
