#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    this->setMouseTracking(true);
    manhattanDistance = 10;
    capturedPoint = -1;
    //painter = new QPainter(this);
}

Widget::~Widget()
{

}

void Widget::myDraw()
{
    //QPainter painter(this);
    painter = new QPainter(this);
    painter->setPen(Qt::blue);
    painter->setBrush(Qt::red);
    painter->setFont(QFont("Arial", 13));
    drawNumbers=true;
    proc_poly(points);
    drawNumbers=false;

    /*
    QVector<QPoint> tt;
    tt<<QPoint(110,87)<<QPoint(523,77)<<QPoint(455,348)<<QPoint(149,344);
    QVector<QPoint> t2 = tri_poly(tt);
    */


    if (points.size()>3 && !isCrossedPoly(points))
    {
        QVector<QPoint> tmp = tri_poly(points);
        for (int i=2; i<tmp.size(); i+=3)
        {
            QVector<QPoint> triangle;
            triangle.append(tmp[i-2]);
            triangle.append(tmp[i-1]);
            triangle.append(tmp[i]);
            proc_poly(triangle);
        }
    }

    //tri_poly(points, proc_poly);
    //painter->drawLine(t1(), t2());
    delete painter;
}

void Widget::proc_poly(QVector<QPoint> p)
{
    for (int i=0; i<p.size(); i++)
    {
        if (drawNumbers)
        {
            painter->drawEllipse(p[i], 5, 5);
            painter->drawText(p[i], QString::number(i) + " ("+QString::number(p[i].x())+
                              ","+QString::number(p[i].y())+")");
        }
        if (i<p.size()-1) painter->drawLine(p[i], p[i+1]);
    }
    if (p.size()>2)
        painter->drawLine(p[p.size()-1], p[0]);
}

void Widget::paintEvent(QPaintEvent *){
    myDraw();
}

void Widget::mouseMoveEvent(QMouseEvent * event){
    if (capturedPoint != -1)
    {
        points[capturedPoint] = QPoint(event->x(), event->y());
        update();
    }
}

void Widget::mousePressEvent(QMouseEvent * event){
    myString = "";
    x=event->x();
    y=event->y();
    if (event->button() == Qt::RightButton)
    {
        int removeIndex=-1;
        for (int i=0; i<points.size(); i++)
        {
            if (abs(event->x()-points[i].x())+abs(event->y()-points[i].y())<10)
                removeIndex=i;
        }
        if (removeIndex!=-1)
        {
            points.remove(removeIndex);
        }
    }
    if (event->button()==Qt::LeftButton){
        capturedPoint=-1;
        for (int i=0; i<points.size(); i++)
            if (abs(event->x()-points[i].x())+abs(event->y()-points[i].y())<10)
                capturedPoint=i;
        if (capturedPoint==-1)
        {
            points.append(QPoint(x,y));
        }
    }
    update();
}

void Widget::mouseReleaseEvent(QMouseEvent *){
    capturedPoint = -1;
    update();
}

//--- Из GeometryFunctions ---
