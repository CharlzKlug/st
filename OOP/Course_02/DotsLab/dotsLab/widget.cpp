#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    this->setMouseTracking(true);
    pointsCount=0;
    //points = new QPoint[pointsCount];
    manhattanDistance = 10;
    capturedPoint = -1;

    // Добавляем координаты экрана в corePoints
    corePoints = new QPoint[4];
    corePoints[0] = QPoint(width(),0);
    corePoints[1] = QPoint(0, 0);
    corePoints[2] = QPoint(0, height());
    corePoints[3] = QPoint(width(), height());
    corePointsCount = 4;
    coreCentMass = centerPoint(corePoints, corePointsCount);
    sortByAngle(corePoints, corePointsCount, coreCentMass);
}

Widget::~Widget()
{

}

void Widget::myDraw()
{
    /*
    QPainter painter(this);
    painter.setPen(Qt::blue);
    painter.setBrush(Qt::black);
    painter.setFont(QFont("Arial", 13));
    for (int i=0; i<pointsCount; i++){
        painter.drawEllipse(points[i], 5, 5);
        painter.drawText(points[i], QString::number(i));
        if (i>0) painter.drawLine(points[i], points[i-1]);
    }
    if (pointsCount !=0)
        painter.drawLine(points[0], points[pointsCount-1]);
    */


    QPainter painter(this);
    painter.setPen(Qt::blue);
    painter.setBrush(Qt::red);
    painter.setFont(QFont("Arial", 13));
    //QPolygon myPoly;
    //myPoly.setPoints(5, 0,0, 100, 0, 50, 50, 10, 30, 110, 30);
    //QPainterPath tmpPath;
    //tmpPath.addPolygon(myPoly);
    //painter.drawPolygon(myPoly);
    //painter->fillPath(tmpPath);

    /*
    QPolygon somePolygon;
    somePolygon.append(QPoint(0,0));
    somePolygon.append(QPoint(0, 100));
    somePolygon.append(QPoint(100, 100));
    somePolygon.append(QPoint(300, 300));
    somePolygon.append(QPoint(100, 0));


    painter.drawPolygon(somePolygon);
    */
    //painter.drawPolygon(points, pointsCount);

    //painter.drawPolygon(corePoints, 4);

    for (int i=0; i<pointsCount; i++){
        painter.drawEllipse(points[i], 5, 5);
        /*
        painter.drawText(points[i], QString::number(i)+" "+
                         QString::number(cosBetween(points[i])) + " " +
                         QString::number(vectProduct(points[i]))
                         );
                         */
        if (i<pointsCount-1) painter.drawLine(points[i], points[i+1]);
        painter.drawText(points[i], QString::number(i) + " " +
                         QString::number(getAngle(points[i], centPoint)));
    /*
        if (i-2>-1) painter.drawLine(points[i], points[i-2]);
        else if (i>0) painter.drawLine(points[i], points[i-1]);
        */
    }
    if (pointsCount>2)
        painter.drawLine(points[pointsCount-1], points[0]);

    painter.drawEllipse(centPoint, 2, 2);
    painter.drawText(centPoint, "c");

    if (pointsCount>2)
    {
    buildCore();
    painter.drawPolygon(corePoints, corePointsCount);
    }
    /*
    if (pointsCount !=0)
        painter.drawLine(points[0], points[pointsCount-1]);
    */
}

void Widget::paintEvent(QPaintEvent *){
    myDraw();
}

void Widget::mouseMoveEvent(QMouseEvent * event){
    if (capturedPoint != -1){
        points[capturedPoint] = QPoint(event->x(), event->y());
        centPoint = centerPoint(points, pointsCount);
        update();
    }
    if (capturedPoint == -1) sortByAngle(points, pointsCount, centPoint);
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
    centPoint = centerPoint(points, pointsCount);
    sortByAngle(points, pointsCount, centPoint);
    update();
}

void Widget::mouseReleaseEvent(QMouseEvent *){
    capturedPoint = -1;
    sortByAngle(points, pointsCount, centPoint);
    update();
}

QPoint Widget::centerPoint(QPoint* arr, int total)
{
    double xc, yc;
    xc = 0;
    yc = 0;
    for (int i=0; i<total; i++)
    {
        xc += arr[i].rx();
        yc += arr[i].ry();
    }
    xc /= total;
    yc /= total;
    return QPoint(xc, yc);
}

double Widget::cosBetween(QPoint A, QPoint B)
{
    // Косинус угла между двумя векторами
    double sP = A.rx()*B.rx() + A.ry()*B.ry();
    double delimiter = sqrt((A.rx()*A.rx()+A.ry()*A.ry())*(B.rx()*B.rx()+B.ry()*B.ry()));
    if (delimiter == 0) return 0;
    return sP/delimiter;
}

int Widget::vectProduct(QPoint A, QPoint B)
{
    // Векторное произведение вектора A на вектор B
    //return somePoint.ry() - centPoint.ry();
    return A.rx()*B.ry() - B.rx()*A.ry();
}

double Widget::getAngle(QPoint somePoint, QPoint massPoint)
{
    double tempCos = cosBetween(somePoint-massPoint, QPoint(1,0));
    //int tempVect = vectProduct(somePoint);
    //if (tempVect<0) return arccos(tempCos);
    if (vectProduct(QPoint(1,0), somePoint-centPoint)>0) return 3.14+acos(-tempCos);
    return acos(tempCos);
}

void Widget::sortByAngle(QPoint* arr, int totalPoints, QPoint massPoint)
{
    int minIndex;
    QPoint tempPoint;
    for (int i=0; i<totalPoints-1; i++)
    {
        minIndex=i;
        for (int j=i+1; j<totalPoints; j++)
            if (getAngle(arr[minIndex], massPoint)>getAngle(arr[j], massPoint))
                minIndex=j;
        if (minIndex != i)
        {
            tempPoint=arr[i];
            arr[i]=arr[minIndex];
            arr[minIndex]=tempPoint;
        }
    }
}

void Widget::buildCore()
{ // Построение ядра

    if (pointsCount>2)
    {
    delete [] corePoints;
    corePoints = new QPoint[4];
    corePoints[0] = QPoint(width(),0);
    corePoints[1] = QPoint(0, 0);
    corePoints[2] = QPoint(0, height());
    corePoints[3] = QPoint(width(), height());
    corePointsCount = 4;

    //corePoints = new

    for (int i=0; i<pointsCount; i++)
    {
        if (i==pointsCount-1) cutCore(points[i], points[0]);
        else cutCore(points[i], points[i+1]);
    }
}
}

void Widget::cutCore(QPoint A, QPoint B)
{
    QPoint v = B - A;
    int nextPoint;
    QPoint vc;
    double ax, ay, bx, by, sax, say, sbx, sby, delimiter, x, y, proportion;
    QVector <QPoint> intersections;
    ax = v.rx();
    ay = v.ry();
    sax = A.rx();
    say = A.ry();
    for (int i=0; i<corePointsCount; i++)
    {
        if (i==corePointsCount-1) nextPoint = 0;
        else nextPoint = i+1;
        vc = corePoints[nextPoint] - corePoints[i];
        bx = vc.rx();
        by = vc.ry();
        sbx = corePoints[i].rx();
        sby = corePoints[i].ry();
        delimiter = ay*bx - by*ax;
        if (delimiter != 0)
        {
            x = ((sby-say)*ax*bx - sbx*by*ax + sax*ay*bx)/delimiter;
            y = ((sbx-sax)*ay*by - sby*bx*ay + say*ax*by)/(-delimiter);
            proportion = (x - sbx)/bx;
            double proportiony = (y - sby)/by;
            if ((proportion>=0 && proportion<=1) || (proportiony>=0 && proportiony<=1))
                intersections.append(QPoint(x, y));
        }
    }

    // Проходим по точкам ядра и где векторное произведение меньше
    // либо равно нулю заносим в intersections
    for (int i=0; i<corePointsCount; i++)
    {
        if (vectProduct(v, corePoints[i] - A) <= 0)
            intersections.append(QPoint(corePoints[i].rx(), corePoints[i].ry()));
    }

    // Уничтожаем corePoints и вносим туда содержимое intersections
    delete [] corePoints;
    corePointsCount = intersections.size();
    corePoints = new QPoint[corePointsCount];
    for (int i=0; i<corePointsCount; i++)
        corePoints[i] = QPoint(intersections[i].rx(), intersections[i].ry());

    // Сортируем corePoints
    coreCentMass = centerPoint(corePoints, corePointsCount);
    sortByAngle(corePoints, corePointsCount, coreCentMass);

}
