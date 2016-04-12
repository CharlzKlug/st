#include <QCoreApplication>
#include "point.h"
#include "triangle.h"
#include "iostream"
using namespace std;
const int zero=0;
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Point pa(0, 0);
    Point pb(4, 2);
    Point pc(5, 0);
    Triangle myTriangle(pa, pb, pc);
    cout<<myTriangle.getPX(0)<<endl;
    cout<<myTriangle.getPY(0)<<endl;
    cout<<"Square: "<<myTriangle.square()<<endl;
    cout<<"Height X: "<<myTriangle.heightX(2)<<endl;
    cout<<"Height Y: "<<myTriangle.heightY(2)<<endl;
    cout<<"Median X: "<<myTriangle.medianX(0)<<endl;
    cout<<"Median Y: "<<myTriangle.medianY(0)<<endl;
    cout<<"Side 1 length: "<<myTriangle.sideLength(2)<<endl;
    cout<<"Median length: "<<myTriangle.medianLength(0)<<endl;
    cout<<"Height length: "<<myTriangle.heightLength(2)<<endl;
    cout<<"Bis X: "<<myTriangle.bisX(0)<<endl;
    cout<<"Bis Y: "<<myTriangle.bisY(0)<<endl;
    cout<<"Bis length: "<<myTriangle.bisLength(0)<<endl;
    return zero;
}
