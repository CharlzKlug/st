#include <QCoreApplication>
#include <iostream>
#include <cmath>
#include <ctime>

qreal mmc (qreal (* f)(qreal), qreal a, qreal b,
           int counts){
    qreal max, min, y, x;
    int ni=0, n=0;
    max = f(a);
    min = f(a);
    for (int i = 0; i < counts; i++){
        x = (b-a)*rand()/RAND_MAX + a;
        y = (max - min) * rand() / RAND_MAX;
        if (f(x) > max) max = f(x);
        if (f(x) < min) min = f(x);
        n++;
        if (f(x) - min >= y) ni++;
    }
    return (b-a)*(ni* (max-min)/n  + min);
}

qreal test (qreal x){
    return x * x -3;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    srand(time(0));
    std::cout << "Enter a: ";
    qreal a1;
    std::cin >> a1;
    std::cout << "Enter b: ";
    qreal b;
    std::cin >> b;
    std::cout << "Enter counts: ";
    int N;
    std::cin >> N;

    std::cout << "Integral value: " << mmc(sin, a1, b, N);
    return a.exec();
}
