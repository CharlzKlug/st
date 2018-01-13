//..\myPainter.cpp                       18.08.2015  Кожевников А.А.
#include "myPainter.h"
#include <QDebug>

MyPainter::MyPainter(QPaintDevice * dev):QPainter(dev)
{             
    color=rand()%256;
    aColor<<0x0000FF<<0xA52A2A<<0xFF7F50<<0x008B8B<<0x4B0082<<
                  0x006400<<0x8B008B<<0xE9967A<<0x8B008B<<0xFF00FF<<
                  0xFFA500<<0xDA70D6<<0xFF0000<<0xEE82EE<<0xFFFF00<<
                  0x808000<<0x4B0082<<0xADFF2F<<0x9932CC<<0x00B8B8;
}
//-------
void MyPainter::myScale(qreal x1, qreal y1, qreal w, qreal h)
{//Вычисляются масштабные множители в формулах преобразования
  //мировых координат в экранные
    px=  winS.width()/w;     qx=winS.x() - px*x1;
    py= -winS.height()/h;     qy=winS.y() - py*y1;
}
//----
void MyPainter::myScale(qreal x1, qreal y1, qreal w, qreal h, QRect&r)
{//Вычисляются масштабные множители в формулах преобразования
    //мировых координат в экранные
    px= r.width()/w;     qx=r.x() - px*x1;
    py=-r.height()/h;    qy=r.y() - py*y1;
}
//----
void MyPainter::myScale(QRectF &w, QRect &r)
{//Вычисляются масштабные множители в формулах преобразования
 // мировых координат в экранные
   px=  r.width()/w.width();        qx=r.x() - px*w.x();
   py= -r.height()/w.height();      qy=r.y() - py*w.y();
}
//============
int MyPainter::xs(double x)
{//преобразуется  мировая координата в экранную
   return int(px*x+qx);
}
//=============
int MyPainter::ys(double y)
{//преобразуется  мировая координата в экранную
   return int(py*y+qy);
}
//=============
QPoint  MyPainter::pScreen(double x, double y)
{//возвращается тчк окна, которая соответствует тчк  (x,y)
   return QPoint(xs(x), ys(y));
}
QPointF  MyPainter::pDekart(QPoint &s)
{//возвращается тчк мирового окна, которая соответствует тчк s окна  экрана
    qreal x=(s.x()-qx)/px,  y=(s.y()-qy)/py;
    return QPointF(x, y);
}
//=============
QPoint  MyPainter::pScreen(QPointF &p)
{//возвращается тчк окна, которая соответствует тчк p(x,y)
   return QPoint(xs(p.x()), ys(p.y()));
}
//------
QPolygon &MyPainter::pScreen(QPolygonF &v)
{//создаётся вектор тчк окна, которые соответствуют вектору тчк v
   vs.clear();
   foreach(QPointF p, v)   vs<<pScreen(p);
   return vs;
}
//===========
void MyPainter::drawPolyline(QPolygonF &v, QPen pen)
{//Изображается ломаная линия
   QPolygon ps;                                                     //массив узловых (оконных) тчк
   foreach(QPointF p, v)   ps<<pScreen(p);
   save();
   setPen(pen);
   QPainter::drawPolyline(ps);
   restore();
}
//------
void MyPainter::drawPoint(QPointF &a, QPen pen)
{//Изображается тчк
   setPen(pen);
   return QPainter::drawPoint(pScreen(a));
}
//-------
void MyPainter::drawLines(QPolygonF &v, QPen pen)
{//Изображаются отрезки
   QPolygon ps;                                                                     //вектор тчк на экране
   foreach(QPointF p,  v)  ps<< pScreen(p);
   save();
   setPen(pen);
   QPainter::drawLines(ps);
   restore();
}
//------
void MyPainter::drawLine(QPointF &a, QPointF &b, QPen pen)
{//Изображается отрезок
   save();
   setPen(pen);   
   QPoint as=pScreen(a), bs=pScreen(b);
   QPainter::drawLine(as, bs);
   restore();
}
//------
void MyPainter::drawLine(QLineF &line, QPen pen)
{//Изображается отрезок
   QPointF a(line.p1()),   b(line.p2());   drawLine(a, b, pen);
}
//==============
void MyPainter::imagePnt(QPolygonF &v, QPen pen, bool flag)
{//Изображаются  тчк
 // Если flag=true, то изображаются индексы точек
   save();
   //setPen(pen);
   for(int i=0; i<v.size(); i++)
   {      
      drawPoint(v[i], pen);                                                    //drawEllipse(ps[i], 3, 3);
      if (flag)
      {
         QPoint d(pen.width(), pen.width());
         d*=0.5;                                                   //сдвиг изображения номера точки
         QString s;
         drawText(d+pScreen(v[i]),  s.setNum(i, 10));
      }
   }
   restore();
}                        //drawPoints(ps, n);
//------
void MyPainter::drawPolygon(QPolygonF &v, QPen pen, QBrush brush, bool flag)
{//Изображается полигон
   QPolygon ps;                                                                  //вектор экранных точек
   save();
   setBrush(brush);  setPen(pen);
   foreach(QPointF q, v)  ps<< pScreen(q);
   QPainter::drawPolygon(ps);
   if (flag)  imagePnt(v, pen, flag);                                    //изображаются  вершины
   restore();
}
//------
void MyPainter::drawPolygons(QVector<QPolygonF >&v, QPen pen, QBrush brush)
{//Изображаются многоугольники
    for ( int m=0; m<v.size(); ++m)
        drawPolygon(v[m], pen, brush);
}
//----
void MyPainter::drawAxis(QRect &r)
{//Изображаются оси.
   save();
   setPen(QPen(Qt::black, 1));
   QPoint p1, p2;
   setFont(QFont("Times", 10, QFont::Normal));
   if (ys(0)>r.y() && ys(0)<r.y()+r.height() )
   {
       p1=QPoint(r.x(), ys(0));                                               //изображается ось 0X
       p2=QPoint(r.x()+r.width(), ys(0));
       QPainter::drawLine(p1, p2);
       drawText(r.x()+r.width()-10,  ys(0)-5, "X");
   }
   if( xs(0)>r.x() && xs(0)<r.x()+r.width()  )
   {
       p1=QPoint(xs(0), r.y());                                              //изображается ось  0Y
       p2=QPoint(xs(0), r.y()+r.height());
       QPainter::drawLine(p1, p2);
       drawText(xs(0)+5,  r.y()+15, "Y");
   }
   restore();
}
//=================
void MyPainter::selectColPen(QVector<QColor>&c,  int m )
{//Выбирается цвет пера
   for (int i=1; i<=m; i++)
   {
      QColor color=QColorDialog::getColor(c[i]);
      if ( color. isValid() ) c[i]=color;
   }
}
//=====
void MyPainter::selectColBrush(QColor &c )
{//Выбирается цвет кисти
   c=QColorDialog::getColor(Qt::yellow);
}
//----
QRect &MyPainter::getWinS()
{//Возвращаются параметры экранного окна
   return winS;
}
//----
void MyPainter::setWinS(QRect &s)
{  winS=s; }                              //Устанавливаются параметры экранного окна
//===========
QGradient MyPainter::createColorGradient(QRect &r, QVector <QColor>&c, int t)
{//создаются цветовые градиенты; r-пр-к, c-вектор цветов, t-тип гр-та
   QGradient grad;
   int n=c.size();
   qreal h=1.0/(n-1);
   QVector<qreal>x;                               //создаётся вектор узлов-цветовых точек
   x<<0;
   for(int i=1; i<n-1; ++i)  x<<i*h;
   x<<1.0;
   switch (t)
   {
   case 0: grad=QConicalGradient(r.width()/5, r.height()/2, 180);  break;
   case 1: grad=QLinearGradient(r.x(), r.y(), r.width(), r.height()); break;
   case 2:
            {QPointF center(r.center());//*0.7
              QPointF focal(r.width(), r.height());//*0.8*0.8
              grad=QRadialGradient (center,  r.width()/2,  focal); break;
            }
   }
   for(int i=0; i<n; ++i)  grad.setColorAt(x[i], c[i]);
   return grad;
}
//=================
void MyPainter::legend(QPoint coor,  int size,  int width, const QString &s)
{//legend
   QFont font("Times", size, width); setFont(font);
   drawText(coor.x(), coor.y(),  s);
}
//----
void MyPainter::grid(int nx, int ny)
{//nx, ny числа ячеек сетки вдоль  осей
   QPoint p1, p2;
   setPen(QPen(Qt::black, 0.5));
   int  hx=abs(xs(0)/nx), hy=abs(ys(0)/ny);
   if (!hx) hx=10;    if (!hy) hy=10;
   int x=0;
   while(x<winS.width())
   {
      p1=QPoint(winS.x()+x, winS.y());
      p2=QPoint(winS.x()+x, winS.y()+winS.height());
      QPainter::drawLine(p1, p2);
      x+=hx;
   }
   p1=QPoint(winS.x()+winS.width(), winS.y());                          //последняя линия
   p2=QPoint(winS.x()+winS.width(), winS.y()+winS.height());
   QPainter::drawLine(p1, p2);
   int y=0;
   while (y<winS.height())
   {
      p1=QPoint(winS.x(),                   winS.y()+y);
      p2=QPoint(winS.x()+winS.width(), winS.y()+y);
      QPainter::drawLine(p1, p2);
      y+=hy;
   }
   p1=QPoint(winS.x(), winS.y()+winS.height());                          //последняя линия
   p2=QPoint(winS.x()+winS.width(), winS.y()+winS.height());
   QPainter::drawLine(p1, p2);
}
//----
void MyPainter::drawGrid(QRectF &w, qreal hx, int ky, QPen pen)
{//Изображается сетка координатных линий. hx- шаг сетки вдоль оси 0x,
  //ky- число  линий сетки вдоль оси 0y (y=const)
    qreal hy=w.height()/(ky-1);
    qreal x, y;
    qreal x1=w.x(), x2=x1+w.width(), y1=w.y(), y2=y1-w.height();
    QPointF p1, p2;
    save();
    setPen(pen);
    if (x1>=0 || x2<=0)
    {
        x=x1+hx;
        do                                                                    //x отсчитывется от x1 вправо
        {//ветрикальные линии
            setPen(QPen(Qt::red, 6));
            p1=QPointF(x, y1), p2=QPointF(x, y2);
            drawLine(p1, p2, pen); x+=hx;
        }  while (x<x2);
    }
    if (x1<0 && x2>0)
    {
       x=0;
       do                                                                        //x отсчитывется от  0 влево
       {//ветрикальные линии
           p1=QPointF(x, y1), p2=QPointF(x, y2);
           drawLine(p1, p2, pen); x-=hx;
       }  while (x>x1);
       x=hx;
       do                                                                      //x отсчитывется от  0 вправо
       {//ветрикальные линии
           p1=QPointF(x, y1), p2=QPointF(x, y2);
           drawLine(p1, p2, pen); x+=hx;
       }  while (x<x2);
    }
    if (y1<0 || y2>0) y=y2+hy;
    do                                                                          //y отсчитывется от y2 вверх
    {//горизонтальные линии
        p1=QPointF(x1, y), p2=QPointF(x2, y);
        drawLine(p1, p2, pen); y+=hy;
    } while (y<y1);
    if (y1>0 && y2<0)
    {
        y=hy;
        do                                                                        //y отсчитывется от 0 вверх
        {//горизонтальные линии
            p1=QPointF(x1, y), p2=QPointF(x2, y);
            drawLine(p1, p2, pen); y+=hy;
        }  while (y<y1);
        y=-hy;
        do                                                                          //y отсчитывется от 0 вниз
        {//горизонтальные линии
            p1=QPointF(x1, y), p2=QPointF(x2, y);
            drawLine(p1, p2, pen); y-=hy;
        }  while (y>y2);
    }
    restore();
}
//----
void MyPainter::drawParamRect(QRectF &w, QRect &r)
{//Числа y1=w.y(), y2=w.y()-w.height() изображаются справа, а числа
  //x1=w.x(), x2=w.x()+w.width() снизу от прямоугольника r
    QPainter::setFont(QFont("Times", 8, QFont::Normal));
    //изображаются x1 и x2
    QPoint pL(r.x(), r.y()+r.height()+15);
    QPoint pR(r.x()+r.width()-10, r.y()+r.height()+15);
    QPainter::drawText(pL,  QString().setNum(w.x(), 'f', 1));
    QPainter::drawText(pR,  QString().setNum(w.x()+w.width(), 'f', 1));
    //изображаются y1 и y2
    QPoint pT(r.x()+r.width(), r.y()+5);
    QPoint pB(r.x()+r.width(), r.y()+r.height());
    QPainter::drawText(pT,  QString().setNum(w.y(), 'f', 0));
    QPainter::drawText(pB,  QString().setNum(w.y()-w.height(), 'f', 0));
}
//----
QList<QRect> &MyPainter::rectScreen(int r, int c)
{//Вычисляются параметры массива прямоугольников;
  //r-число рядов прямоугольников, c-число прямоугольников в ряду
    int dx=20, dy=20;                                                                                 //отступы
    int w=(winS.width()-dx*(c+1))/c ;                //ширина и высота прямоугольника
    int h=(winS.height()-dy*(r+1))/r;
    rectS.clear();
    for(int i=0; i<r; ++i)
        for(int j=0; j<c; ++j)
        {
            QRect rect=QRect(j*(w+dx)+dx, i*(h+dy)+dy, w, h);
            rectS<<rect;
            QPainter::drawRect(rect);
        }
    return rectS;
}
//-----
MyPainter::~MyPainter(){}
//----
