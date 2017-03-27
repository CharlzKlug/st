#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    this->setMouseTracking(true);
    pointsCount=0;
    //points = new QPoint[pointsCount];
    manhattanDistance = 10;
    capturedPoint = -1;
}

Widget::~Widget()
{

}

void Widget::paintEvent(QPaintEvent *){
    QPainter painter(this);
    painter.setPen(Qt::blue);
    //    painter.setFont(QFont("Arial", 30));
    //    painter.drawText(rect(), Qt::AlignCenter, "Qt");
    painter.setBrush(Qt::black);
    //painter.drawEllipse(100, 100, 5, 5);
    painter.setFont(QFont("Arial", 13));
    //painter.drawText(100, 100, QString::number(x));
    //    painter.drawEllipse(x, y, 5, 5);
    //    painter.drawText(x, y, QString::number(x)+" "+QString::number(y));
    for (int i=0; i<pointsCount; i++){
        painter.drawEllipse(points[i], 5, 5);
        painter.drawText(points[i], QString::number(i));
        if (i>0) painter.drawLine(points[i], points[i-1]);
    }
}

void Widget::mouseMoveEvent(QMouseEvent * event){
    if (capturedPoint != -1){
        points[capturedPoint] = QPoint(event->x(), event->y());
        update();
    }
}

void Widget::mousePressEvent(QMouseEvent * event){
    myString = "";
    x=event->x();
    y=event->y();
    if (event->button() == Qt::RightButton){
        int removeIndex=-1;
        for (int i=0; i<pointsCount; i++){
            if (abs(event->x()-points[i].x())+abs(event->y()-points[i].y())<10)
                removeIndex=i;}
        if (removeIndex!=-1 && pointsCount!=1){
            QPoint * doublePoints=new QPoint[pointsCount-1];
            int indexDouble=0;
            for (int i=0; i<pointsCount; i++){
                if (i!=removeIndex){
                    doublePoints[indexDouble]=points[i];
                    indexDouble++;
                }}
            delete [] points;

            points = new QPoint[pointsCount-1];
            for (int i=0; i<pointsCount-1; i++) points[i]=doublePoints[i];
            delete [] doublePoints;
            pointsCount--;} else {
            if (removeIndex!=-1 && pointsCount==1){
                delete [] points;
                pointsCount=0;}
        }}

    //    if (event->button() == Qt::LeftButton) {
    //        pointsCount++;
    //        if (pointsCount>1) {
    //            QPoint * doublePoints = new QPoint[pointsCount-1];
    //            for (int i=0; i<pointsCount-1; i++) doublePoints[i]=points[i];
    //            delete [] points;
    //            points = new QPoint[pointsCount];
    //            for (int i=0; i<pointsCount-1; i++) points[i]=doublePoints[i];
    //            delete [] doublePoints;
    //            points[pointsCount-1] = QPoint(x, y);
    //        } else {
    //            points = new QPoint[pointsCount];
    //            points[pointsCount-1] = QPoint(x, y);}}

    if (event->button()==Qt::LeftButton){
        capturedPoint=-1;
        for (int i=0; i<pointsCount; i++)
            if (abs(event->x()-points[i].x())+abs(event->y()-points[i].y())<10)
                capturedPoint=i;
        if (capturedPoint==-1){
            pointsCount++;
            if (pointsCount>1){
                QPoint* doublePoints = new QPoint[pointsCount-1];
                for (int i=0; i<pointsCount-1; i++) doublePoints[i]=points[i];
                delete [] points;
                points = new QPoint[pointsCount];
                for (int i=0; i<pointsCount-1; i++) points[i] = doublePoints[i];
                delete [] doublePoints;
                points[pointsCount-1] = QPoint(x, y);
            } else {
                points = new QPoint[pointsCount];
                points[pointsCount-1] = QPoint(x, y);
            }
        }
    }
    //this->setWindowTitle("Test... " + myString);
    update();
}

void Widget::mouseReleaseEvent(QMouseEvent *){
    capturedPoint = -1;
}
