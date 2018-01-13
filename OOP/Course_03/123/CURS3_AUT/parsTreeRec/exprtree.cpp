//BAKALAVR\..\CURS3_AUT\parsTreeRec\exprtree.cpp
//22.09.217  Кожевников А.А.
#include "exprtree.h"

Exprtree::Exprtree(QString &str, qreal ax, qreal bx, qreal hx):
        ParsTreeRec(str),  a(ax), b(bx), h(hx)
{
    nNode=round((b-a)/h+1.);
}
//-----
QPolygonF &Exprtree::createVector()
{//Создаётся вектор координат узлов ломаной линии (графика)
    qreal u=a, v;
    node.clear();
    for ( int i=0; i<nNode;  ++i)
    {
        ParsTreeRec::x=u;    v=ParsTreeRec::evalf(x);
        node<<QPointF(u, v);
        u+=h;  if (i==nNode-2) u=b;
    }
    return node;
}
//-----
void Exprtree::minMaxFunc()
{//Определяются наименьшее и наибольшее значения функции
    if (node.isEmpty()) return;
    fmin=fmax=node[0].y();
    for(int i=1; i<nNode; ++i)
    {
        if (fmin>node[i].y()) fmin=node[i].y();
        if (fmax<node[i].y()) fmax=node[i].y();
    }
}
//----
QRectF &Exprtree::rectWorld()
{//Вычисляются параметры прямоугольника с графиком функции
  //в декартовой системе координат a<=x<=b, fmin<y<fmax
    minMaxFunc();
    qreal ymin=(fmin<0)? fmin*1.05  :  fmin*0.9;
    qreal ymax=(fmax>0)? fmax*1.05  :  fmax*0.9;
//    return rectW=QRectF(a, fmax,  b - a, fmax-fmin);
    return rectW=QRectF(a, ymax,  b - a, ymax-ymin);
}
//----
