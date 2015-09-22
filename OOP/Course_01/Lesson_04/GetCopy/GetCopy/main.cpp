// Получение копии переменной
#include <QCoreApplication>
#include <iostream>
#include <ctime>
#include <cmath>
using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    cout<<"Получить копию N\n";
    srand(time(0));
    int n = rand()%1000 + 1; // Создаём случайное число
    cout<<"n = "<<n<<"\n";
    int m = 0, k = 1; // m - результат, k - степень 10
    int f; // промежуточная переменная, хранящая по очереди каждую цифру
    while (n)
    {
        f = n % 10;
        m = m + f*k;
        k = k * 10;
        n = n / 10;
    }
    cout<<"m = "<<m<<"\n";
    return 0;
}
