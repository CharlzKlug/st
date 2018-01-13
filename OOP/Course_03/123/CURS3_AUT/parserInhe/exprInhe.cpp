//BAKALAVR\CURS3\parserInhe\exprInhe.cpp          16.08.2017 Кожевников А.А.
#include "exprInhe.h"

ExprInhe::ExprInhe(QString &str, qreal ax, qreal bx, qreal hx):
         ParserInhe(str),  a(ax), b(bx), h(hx)
{
    nNode=round((b-a)/h+1.0);   
}
//-----
QPolygonF &ExprInhe::createVector()
{//Создаётся вектор координат узлов ломаной линии (графика)
    qreal u=a, v;
    node.clear();
    for ( int i=0; i<nNode;  ++i)
    {
        ParserInhe::setX(u);    v=evalf(getStr());
        node<<QPointF(u, v);
        u+=h;  if (i==nNode-2) u=b;
    }
    return node;
}
//-----
void ExprInhe::minMaxFunc()
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
QRectF &ExprInhe::rectWorld()
{//Вычисляются параметры прямоугольника с графиком функции
  //в декартовой системе координат a<=x<=b, fmin<y<fmax
    minMaxFunc();
    qreal ymin=(fmin<0)? fmin*1.05  :  fmin*0.9;
    qreal ymax=(fmax>0)? fmax*1.05  :  fmax*0.9;
    return rectW=QRectF(a, fmax,  b - a, fmax-fmin);
//    return rectW=QRectF(a, ymax,  b - a, ymax-ymin);
}
//----
