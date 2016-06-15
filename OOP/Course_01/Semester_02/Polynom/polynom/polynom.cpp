#include "polynom.h"

TPolynom::TPolynom(int n, qreal * someCoefs){
    // ��������� �������� �� ���ᨢ�
    m = n;
    coefs = new qreal[m];
    for (int i=0; i<n; i++){
        coefs[i]=someCoefs[i];
    }
}

void TPolynom::printCoefs(){
    // ����� ���祭�� ��������
    std::cout << "����� ���祭�� �����樥�⮢" << std::endl;
    std::cout << std::setw(10) << "�������: ";
    for (int i=0; i<m; i++)
        std::cout << std::setw(6) << i;
    std::cout << std::endl;
    std::cout << std::setw(10) << "���祭��: ";
    for (int i=0; i<m; i++){
        std::cout << std::setw(6) << coefs[i];
    }
    std::cout << std::endl;
}

qreal TPolynom::calcGornerRecur(qreal x, int current){
    // ���᫥��� ���祭�� �������� �� �奬� ��୥� (४��ᨢ��)
    if (current == m-1) return coefs[current];
    return (coefs[current]+x*calcGornerRecur(x, current+1));
}

qreal TPolynom::calcGorner(qreal x){
    // ���᫥��� ���祭�� �������� �� �奬� ��୥�
    return calcGornerRecur(x, 0);
}

void valuesBetween(qreal a, qreal b, qreal h, TPolynom & q){
    // ��� ��� ���᫥��� ���祭�� �� ��१�� [a, b] � 蠣�� h
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
    std::cout<<"�।��� ���祭�� �������� �� ��१�� ["<<a<<", "<<b<<"]: "<<sum/steps<<std::endl;
}
