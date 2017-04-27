#include <QCoreApplication>
#include <iostream>
#include <mathlib.h>
#include <ctime>

struct Rasp {
    double x;
    double p;
};

const int n = 4;
Rasp r[] = {{-40, 0.1}, {14, 0.1}, {-33, 0.1}, {2, 0.7}};

double expVal()
{
    double M = 0;
    for (int i = 0; i < n; i++) M += r[i].p * r[i].x;
    return M;
}

double dispersion()
{
    double D = 0;
    double M = expVal();
    for (int i = 0; i < n; i++) D += r[i].p * (r[i].x - M) * (r[i].x - M);
    return D;
}

double function(double x)
{
    return 2 / (2 - x);
}

double getNewValue()
{
    return function(rnd());
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    initGen();
    int N = 110;
    int q = 15;
    double m = 0;
    double currentValue;
    double g = 0;
    for (int i = N; i > 0; i--)
    {
        currentValue = getNewValue();
        m += currentValue;
        g += currentValue * currentValue;
        if (q>0) std::cout << "X[" << q << "] = " << currentValue << "\n";
        q--;
    }
    m = m / N;
    g = g / (N - 1) - N / (N - 1) * m * m;
    double M = 1.39;
    double D = 0.08;
    std::cout << "M = " << M << "\n";
    std::cout << "D = " << D << "\n";
    std::cout << "m = " << m << "\n";
    std::cout << "g = " << g << "\n";
    std::cout << "M - m = " << M - m << "\n";
    std::cout << "D - g = " << D - g << "\n";
    return a.exec();
}
