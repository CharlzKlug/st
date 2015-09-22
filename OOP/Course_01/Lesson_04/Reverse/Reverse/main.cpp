// Переворачивание числа.
#include <QCoreApplication>
#include <iostream>
#include <cmath>
#include <time.h>
using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    cout<<"Возвращение перевёрнутого числа\n";
    srand(time(0));
    int n = rand()%1000 + 1;
    cout<<"n = "<<n<<"\n";
    int m = 0;
    int f;
    while (n)
    {
        f = n % 10;
        m = m*10 + f;
        n = n /10;
    }
    cout<<"m = "<<m<<"\n";
    return 0;
}
