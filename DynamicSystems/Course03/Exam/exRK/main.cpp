#include <QCoreApplication>
#include <iostream>
#include "vector.h"
#include "rkmethod.h"

qreal derivFunc(qreal);
qreal RK(qreal (*)(qreal), qreal, qreal, qreal);

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    /*
    Vector r1 (5, 5);
    Vector r2 (3, 2);
    Vector rst;
    rst = r1 / 3;
    Vector r3 (3, 4);
    std::cout << r1.getX() << ", " << r1.getY() << "\n";
    std::cout << r2.getX() << ", " << r2.getY() << "\n";
    std::cout << rst.getX() << ", " << rst.getY() << "\n";
    std::cout << rst.module() << "\n";
    std::cout << r3.module() << "\n";
    //std::cout << derivFunc(5) << "\n";
    //std::cout << RK(derivFunc, 0, 0, 1) << "\n";
    */
    RKMethod rk (Vector (0, 0), Vector(384000000, 0), Vector(0,0), Vector(-10, 10),
                 0.01, 73400000000000000000000.0, 6000000000000000000000000.0);

    for (int i=0; i<1000000; i++){
        std::cout << "t = " << rk.getTime() << "\n";
        std::cout << "Earth x = " << rk.getr1().getX() << ", y = " << rk.getr1().getY() << "\n";
        std::cout << "Moon x = " << rk.getr2().getX() << ", y = "<< rk.getr2().getY() << "\n";
        rk.iterate();
    }
    return a.exec();
}

/*
qreal derivFunc(qreal t){
    return 10*t + 5;
}
*/
/*
qreal RK(qreal (*f)(qreal), qreal y0, qreal x0, qreal x1){
    qreal yp = y0;
    qreal k1, k2, k3, k4, xtmp = x0;
    for (int i = 1; i < (x1 - x0) * h; i++){
        xtmp += 1/h;
        k1 = f(xtmp);
        k2 = f(xtmp + 1/(2*h));
        k3 = f()
    }
    return f(5);
}
*/
