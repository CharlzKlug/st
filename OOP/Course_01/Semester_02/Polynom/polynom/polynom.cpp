#include "polynom.h"

TPolynom::TPolynom(int n, qreal * someCoefs){
    // Конструктор полинома из массива
    m = n;
    coefs = new qreal[m];
    for (int i=0; i<n; i++){
        coefs[i]=someCoefs[i];
    }
}

void TPolynom::printCoefs(){
    // Печать значений полинома
    std::cout << "Печать значений коэффициентов" << std::endl;
    std::cout << std::setw(10) << "Индексы: ";
    for (int i=0; i<m; i++)
        std::cout << std::setw(6) << i;
    std::cout << std::endl;
    std::cout << std::setw(10) << "Значения: ";
    for (int i=0; i<m; i++){
        std::cout << std::setw(6) << coefs[i];
    }
    std::cout << std::endl;
}

qreal TPolynom::calcGornerRecur(qreal x, int current){
    // Вычисление значения полинома по схеме Горнера (рекурсивно)
    if (current == m-1) return coefs[current];
    return (coefs[current]+x*calcGornerRecur(x, current+1));
}

qreal TPolynom::calcGorner(qreal x){
    // Вычисление значения полинома по схеме Горнера
    return calcGornerRecur(x, 0);
}

void valuesBetween(qreal a, qreal b, qreal h, TPolynom & q){
    // Друг для вычисления значений на отрезке [a, b] с шагом h
    int steps=0;
    qreal sum=0, currentPolynomValue;
    std::cout<<std::setprecision(4);
    std::cout<<std::setw(10)<<"X"<<std::setw(10)<<"Y"<<std::endl;
    for (qreal x=a; x<=b; x+=h){
        std::cout<<std::setw(10)<<x;
        currentPolynomValue=q.calcGorner(x);
        sum+=currentPolynomValue;
        steps++;
        std::cout<<std::setw(10)<<currentPolynomValue<<std::endl;
    }
    std::cout<<"Среднее значение полинома на отрезке ["<<a<<", "<<b<<"]: "<<sum/steps<<std::endl;
}
