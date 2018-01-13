//\...\myPainter.h                                           12.08.2015  Кожевников А.А.
#ifndef MYPAINTER_H
#define MYPAINTER_H
#include <QColorDialog>
#include <QPainter>
class MyPainter: virtual public QPainter
{
public:
   QRect winS;
   double px, qx, py, qy;
   QPolygon vs;
   QColor color;
   QList<QColor> aColor;
   QList<QRect> rectS;
   QPoint sa, sb;
public:
   MyPainter (QPaintDevice * =0);
   ~MyPainter();
   void myScale(qreal x1, qreal y1, qreal w, qreal h);
   void myScale(qreal x1, qreal y1, qreal w, qreal h, QRect &r);
   void myScale(QRectF &w, QRect &r);
   int xs(double);
   int ys(double);
   QPoint  pScreen(double x, double y);
   QPoint pScreen(QPointF &p);
   void  pScreen(QPolygonF &v, QPolygon &s);
   QPolygon &pScreen(QPolygonF &v);
   QPointF  pDekart(QPoint &s);
   void drawAxis(QRect &r);
   void drawLine(QLineF &line,  QPen pen);
   void drawLine(QPointF &a, QPointF &b,  QPen pen);
   void drawLines(QPolygonF &v,  QPen pen);
   void drawPoint(QPointF &a, QPen pen);
   void drawPolyline(QPolygonF &v,  QPen pen);
   void drawPolygon(QPolygonF &v,
                    QPen pen, QBrush brush,  bool flag=false);
   void drawPolygons(QVector<QPolygonF >&v, QPen pen, QBrush brush);
   void imagePnt(QPolygonF &v,  QPen pen, bool flag=false);
   void selectColPen(QVector<QColor>&c,  int m );
   void selectColBrush(QColor &c );
   QRect &getWinS();
   void setWinS(QRect &s);
   QGradient createColorGradient(QRect &r, QVector <QColor>&c, int t);
   void legend(QPoint coor,  int size,  int width, const QString &s);
   void grid(int nx, int ny);

   void drawGrid(QRectF &w, qreal hx, int ky, QPen pen);
   void drawParamRect(QRectF &w, QRect &r);
   QList<QRect> &rectScreen(int r=1, int c=1);
};
#endif // MYPAINTER_H
