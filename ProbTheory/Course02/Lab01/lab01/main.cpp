#include <QCoreApplication>
#include <QtGlobal>
#include <iostream>
#include <cmath>

qreal mMC (qreal (*f)(qreal), qreal a, qreal b, int N){
    qreal sum = 0, dist = b-a;
    for (int i = 0; i < N; i++)
        sum += f(rand() * dist / RAND_MAX + a);
    return dist / N * sum;
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    srand(time(0));
    std::cout << "Sin from 0 to 3.14: " << mMC(sin, 0, 3.14, 1000000) << "\n";
    return a.exec();
}
