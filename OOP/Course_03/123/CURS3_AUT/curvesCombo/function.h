//..\curvesCombo\function.h         22.09.2015  Кожевников А.А.
#ifndef FUNCTION_H
#define FUNCTION_H
#include <QWidget>

#include <cmath>
#include <QtWidgets>

typedef double TFunc (double);
typedef TFunc* PFunc;
class Function
{//Класс для вычисления параметров функции
//public:
    qreal a, b, h;                                             //параметры табулирования функции
    int nNode;                                            //число узлов ломаной линии (графика)
    QPolygonF node;                                                  //вектор узлов ломаной линии
    qreal fmin, fmax;                       //наибольшее и наименьшее значения функции
    QRectF rectW;                     //прямоугольник в декартовой системе для графика
    PFunc pf;                                                                     //указатель на  функцию
public:
    Function(PFunc pf, qreal ax=-5, qreal bx=5, qreal hx=1);   
    qreal getA(){return a;}
    qreal getB(){return b;}
    qreal getH(){return h;}
    int getN(){return nNode;}

    void setA(qreal aa){a=aa;}
    void setB(qreal bb){b=bb;}
    void setH(qreal hh){h=hh;}
    void setN(int nn){nNode=nn;}
    void setPFunc(PFunc pp){pf=pp;}

    QRectF &rectWorld();
    QPolygonF &createVector();                   //создаётся вектор узлов ломаной линии
    void minMaxFunc();
    ~Function(){}
};
#endif // FUNCTION_H
