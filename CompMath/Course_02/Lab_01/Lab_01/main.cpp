#include <QCoreApplication>
#include <cmath>
#include <iostream>

qreal function (qreal x){
    // Некоторая функция
    return sin(x);
}

qreal polynom (qreal x, qreal * xs, qreal * fs, qreal n){
    // Возвращает приближённое значение функции от x,
    // вычисленное с помощью интерполяционного полинома Лагранжа.
    // xs - точки абсцисс, ys - ординаты, n - количество точек
    qreal result = 0, m;
    for (int i=0; i<n; i++){
        m = fs[i];
        for (int j=0; j<n; j++){
            if (j != i)
                m *= (x - xs[j])/(xs[i]-xs[j]);
        }
        result+=m;
    }
    return result;
}

void genArrays (qreal * xs, qreal * ys, int n, qreal (* f) (qreal)){
    // Генерация массивов узловых абсцисс и ординат
    for (int i=0; i<n; i++){
        xs[i]=cos(M_PI/n*(0.5+i));
        ys[i]=f(xs[i]);
    }
}

void inputXus (qreal * xus){
    for (int i=0; i<4; i++){
        std::cout << "X[" << i << "] = ";
        std::cin >> xus[i];
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    int n;
    std::cout << "N = ";
    std::cin >>n;
    qreal xus [4];
    inputXus(xus);
    qreal * xs = new qreal[n];
    qreal * ys = new qreal[n];
    genArrays(xs, ys, n, function);
    for (int i=0; i<4; i++){
    qreal orig = function(xus[i]);
    qreal pol = polynom(xus[i], xs, ys, n);
    std::cout << "Original function: " << xus[i] << " -> " << orig << "\n";
    std::cout << "Interpolation polynom: " << xus[i] << " -> " <<  pol << "\n";
    std::cout << "Absolute error: " << fabs(orig - pol) << "\n";}
    return a.exec();
}
