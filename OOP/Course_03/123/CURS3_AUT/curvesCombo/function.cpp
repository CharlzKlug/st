//..\curvesCombo\function.cpp    22.09.2015  Кожевников А.А.
#include "function.h"
Function::Function(PFunc pf, qreal ax, qreal bx, qreal hx): a(ax), b(bx), h(hx)
{
    nNode=qRound((b-a)/h+1.0);  
    setPFunc(pf);                                                                      // Function:: pf=pf;
    createVector();
    minMaxFunc();
}
//----
QPolygonF &Function::createVector()
{//Создаётся вектор координат узлов ломаной линии (графика)
    qreal x=a, y;
    node.clear();
    for ( int i=0; i<nNode;  ++i)
    {     
        y=pf(x);
        node<<QPointF(x, y);
        x+=h;  if (i==nNode-2) x=b;
    }
    return node;
}
//-----
void Function::minMaxFunc()
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
QRectF &Function::rectWorld()
{//Вычисляются параметры прямоугольника с графиками функций
  //в декартовой системе координат a<=x<=b, fmin<y<fmax
    minMaxFunc();
    qreal ymin=(fmin<0)? fmin*1.05  :  fmin*0.9;
    qreal ymax=(fmax>0)? fmax*1.05  :  fmax*0.9;
    return rectW=QRectF(a, fmax,  b - a, fmax-fmin);
//    return rectW=QRectF(a, ymax,  b - a, ymax-ymin);
}
//----
