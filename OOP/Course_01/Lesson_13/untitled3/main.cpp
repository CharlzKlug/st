#include <QCoreApplication>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <ctime>
using namespace std;

qreal randomReal (int xa, int xb){
    return (qreal)(xa - xb) * rand()/RAND_MAX + xb;
}

class Point{
    qreal xp, yp, dp;
    char rp;
public:
    Point (qreal x, qreal y){
        xp = x;
        yp = y;
        dp = sqrt(xp * xp + yp * yp);
        if (xp >= 0)
            if (yp >= 0) {rp = 'A';}
            else {rp = 'D';}
        else
            if (yp >= 0) {rp = 'B';}
            else {rp = 'C';};
    }

    void reInit (qreal x, qreal y){
        xp = x;
        yp = y;
        dp = sqrt(xp * xp + yp * yp);
        if (xp >= 0)
            if (yp >= 0) {rp = 'A';}
            else {rp = 'D';}
        else
            if (yp >= 0) {rp = 'B';}
            else {rp = 'C';};
    }
    Point(){}
    qreal getX(){return xp;}
    qreal getY(){return yp;}
    qreal getD(){return dp;}
    char getR(){return rp;}
};

class DPoint {
private:
    int np; //Количество точек
    Point* ap;
public:
    DPoint (int n){
        np = n;
        ap = new Point [np];
        for (int i = 0; i < np; ++i){
            ap[i].reInit(randomReal(100, -100), randomReal(100, -100));
        }
    }

    DPoint (const DPoint& q){
        np = q.np;
        ap = q.ap;
    }

    void printD (){
        for (int i = 0; i < np; ++i){
            cout << i << ":" << endl;
            cout << "x: " << ap[i].getX() << endl;
            cout << "y: " << ap[i].getY() << endl;
            cout << "d: " << ap[i].getD() << endl;
            cout << "r: " << ap[i].getR() << endl;
            cout << endl;
        }
    }

};


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    srand(time(0));
    Point pointA(randomReal(100, -100), randomReal(100, -100));
    DPoint someD(3);
    DPoint newD(someD);
    cout << "Origin class" << endl;
    someD.printD();
    cout << "Cloned class" << endl;
    newD.printD();
    //printD(someD);
    cout << "Hello, World!\n";
    return 0;
}
