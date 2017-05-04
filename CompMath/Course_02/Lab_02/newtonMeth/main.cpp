#include <QCoreApplication>
#include <iostream>
#include <cmath>

const int n = 10;
const double accuracy = 0.001;
const double epsilon = 0.01;

double function(double x)
{
    //    return 20*sin(20*x);
    //return x*x - 3*x +2;
    return 200*sin(x/10) + x;
    //return -x*x+17;
}



double derive(double func(double), double x)
{
    return (func(x + accuracy) - func(x)) / accuracy;
}

double solve(double func(double), double x1, double x2)
{
    double root;
    root = (x1*func(x2) - x2*func(x1)) / (func(x2) - func(x1));
    for (int i = 0; i < n && fabs(func(root)) > epsilon; i++)
        root = root - func(root)/derive(func, root);
    return root;
}

double solveChord(double func(double), double x1, double x2, int count)
{
    if (count<n && fabs(func(x1))>epsilon)
    {
        double root;
        root = (x1*func(x2) - x2*func(x1)) / (func(x2) - func(x1));
        if (func(x1)*func(root)<0)
            solveChord(func, x1, root, count+1);
        else
            solveChord(func, root, x2, count+1);
    }
    return x1;

}

void findRootOnRange(double func(double), double a, double b, double step, int index)
{
    if (a<b)
    {
        if (func(a)*func(a+step) < 0)
        {
            std::cout << "X[" << index<<"] = " << solve(func, a, a+step) << "\n";
            index++;
        }
        findRootOnRange(func, a+step, b, step, index);
    }
}

void findRoots(double func(double), double a, double b)
{
    findRootOnRange(func, a, b, 0.1, 1);
}

void findRootOnRangeChord(double func(double), double a, double b, double step, int index)
{
    if (a<b)
    {
        if (func(a)*func(a+step) < 0)
        {
            std::cout << "X[" << index<<"] = " << solveChord(func, a, a+step, 1) << "\n";
            index++;
        }
        findRootOnRangeChord(func, a+step, b, step, index);
    }
}

void findRootsChord(double func(double), double a, double b)
{
    findRootOnRangeChord(func, a, b, 0.1, 1);
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    std::cout << "The Newton method\n";
    findRoots(function, -300, 300);
    std::cout << "\nThe chord method\n";
    findRootsChord(function, -300, 300);
    std::cout << "Job finished.\n";
    //std::cout << solve(function, 1.5, 3) << "\n";
    //std::cout << "Hello, world!\n";
    return a.exec();
}
