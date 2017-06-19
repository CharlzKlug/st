#include <QCoreApplication>
#include "GeometryFunctions.h"
#include <iostream>
int test_func(int f(int))
{
    return f(5);
}

int an_func(int k)
{
    return k;
}

int an2(int a, int b)
{
    return a+b;
}

void myProc(QVector<QPoint> p)
{
    int n=p.size();
    for (int i=0; i<n; i++)
        std::cout << "(" << p[i].x() << "," << p[i].y() << ")\n";
    std::cout << "---\n";
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QVector<QPoint> poly;
    poly<<QPoint(3,1)<<QPoint(9,1)<<QPoint(7,2)
        <<QPoint(9,5)<<QPoint(7,8)<<QPoint(4,8)
        <<QPoint(6,10)<<QPoint(2,9)<<QPoint(3,7)
        <<QPoint(7,5)<<QPoint(5,3)<<QPoint(3,4)
        <<QPoint(4,5)<<QPoint(1,5);
    QVector<QPoint> test_poly;
    test_poly<<QPoint(1,0)<<QPoint(4,0)<<QPoint(4,3)
            <<QPoint(3,2)<<QPoint(1,3);

    //process_poly(poly+test_poly);
   // std::cout << test_func(an_func) << "\n";
    QVector<QPoint> sum=tri_poly(poly);
    process_poly(sum);
    return a.exec();
}
