//BAKALAVR\..\CURS3_AUT\parsTreeRec\exprtree.h
//22.09.217  Кожевников А.А.
#ifndef EXPRTREE_H
#define EXPRTREE_H

#include<QWidget>
#include"parsTreeRec.h"

class Exprtree:  public ParsTreeRec
{
//public:
    qreal a, b, h;                                                            //параметры табулирования
    int nNode;                                             //число узлов ломаной линии (графика)
    QPolygonF node;                                                  //вектор узлов ломаной линии
    qreal fmin, fmax;                      //наибольшее и наименьшее значения функции
    QRectF rectW;   //параметры мирового прямоугольника a, fmax, b-a, fmax-fmin
public:
    Exprtree(QString &str, qreal a=-5, qreal b=5, qreal h=0.5);
    qreal getA(){return a;}
    qreal getB(){return b;}
    qreal getH(){return h;}
    int getN(){return nNode;}
    void setA(qreal aa){a=aa;}
    void setB(qreal bb){b=bb;}
    void setH(qreal hh){h=hh;}
    void setN(int  nn){nNode=nn;}

    QPolygonF &createVector();              //возвращает вектор узлов ломаной линии
    void minMaxFunc();
    QRectF &rectWorld();       //возвращает параметры прямоугольника с графиком
    ~Exprtree(){}
};

#endif // EXPRTREE_H
