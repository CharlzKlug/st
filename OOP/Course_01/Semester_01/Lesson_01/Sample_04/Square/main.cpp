// Возведение в степень
#include <QCoreApplication>
#include <iostream>
#include <ctime>
#include <cmath>
using namespace std;
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    qreal someNumber, power, v;

    cout<<"Ведите число:";
    cin>>someNumber;

    cout<<"Введите степень:";
    cin>>power;

    (someNumber>0)&&(v = exp(log(someNumber)*power));
    (someNumber<0)&&(v = - exp(log(- someNumber)*power));

    cout<<"Результат:"<<v<<"\n";
    return 0;
}
