//BAKALAVR\CURS3\parserInhe\widget.cpp          16.08.2017 Кожевников А.А.
#include "widget.h"
//переменные вводятся для удобства при описании алгоритмов
qreal a, b, h;
int n;
QPolygonF node;
QRectF rectW;
//-----
Widget::Widget(QWidget *par):QWidget(par),   MyPainter()
{
    setGeometry (50, 100, 800, 600);
    QString str="x^2+2*x-3";                                                 //передаётся объекту
    objExpr = new ExprInhe(str);
    a=objExpr->getA(), b=objExpr->getB(), h=objExpr->getH(), n=round((b-a)/h+1.0);
    createWidgets();
    createLayouts();
    createConnections();
    //строятся таблица и график для тестовой функции
    showTable();
    showGraph();
}
//-----
void Widget::createWidgets()
{//создаются виджеты в объекте group для ввода параметров табулир.
    group = new QGroupBox();
    group->setGeometry (width()+30, 50, 300, 300);
    edit = new QLineEdit(group);   
    QString str=objExpr->getStr();  str.remove(QChar('#'));
    edit->setText(str);

    spinA = new QDoubleSpinBox(group);
    spinA->setRange(-10, 10);    spinA->setSingleStep(0.1);
    spinA->setPrefix("A=");         spinA->setValue(a);

    spinB = new QDoubleSpinBox(group);
    spinB->setRange(-10, 10);     spinB->setSingleStep(0.1);
    spinB->setPrefix("B=");          spinB->setValue(b);

    spinH = new QDoubleSpinBox(group);
    spinH->setPrefix("H=");        spinH->setValue(h);
    spinH->setRange(0.1, 2.0);  spinH->setSingleStep(0.1);

    butTab = new QPushButton("showTable", group);
    butGraph = new QPushButton("showGraph", group);
    table  = new QTableWidget(group);
    table->setGeometry (width()+30, group->height()+80,  250, 250);
    dock = new QDockWidget("Param", 0);
    dock->setGeometry(x()+width()+20, 100, 350, 450);
    dock->setStyleSheet("background: lightgray");
    dock->setWidget(group);
    dock->show();
    QString s;
    s="QLineEdit, QPushButton{color:blue; font: 10pt;}"; //italic
    dock->setStyleSheet(s);
}
//-----
void Widget::createLayouts()
{
    QGridLayout *gLay = new QGridLayout(group);
    gLay->addWidget (edit, 0, 0, 1, 3);
    gLay->addWidget (butTab,  0, 3);
    gLay->addWidget (spinA, 1, 0);
    gLay->addWidget (spinB, 1, 1);
    gLay->addWidget (spinH, 1, 2);
    gLay->addWidget (butGraph, 1, 3);
    gLay->addWidget (table,  2, 0, 1, 3);
}
void Widget::createConnections()
{
     connect(butTab, SIGNAL (clicked()), this, SLOT(showTable()));
     connect(butGraph, SIGNAL (clicked()), this, SLOT(showGraph()));
     connect(spinA, SIGNAL (valueChanged(qreal)),  this, SLOT(slotABH(qreal)));
     connect(spinB, SIGNAL (valueChanged(qreal)),  this, SLOT(slotABH(qreal)));
     connect(spinH, SIGNAL (valueChanged(qreal)),  this, SLOT(slotABH(qreal)));
     connect(edit, SIGNAL(editingFinished()),            this, SLOT(slotEdit()));
}
//-----
void Widget::slotEdit()
{//Обрабатывается событие - окончание редактирования, т.е. нажата ENTER
  //или edit теряет фокус
    QString str=edit->text();                                          //читается выражение из edit
    objExpr->processingExpr(str);                                                                      //str->fs
}
//-----
void Widget::slotABH(qreal )
{//читаются параметры табулирования функций
    objExpr->setA(a=spinA->value());
    objExpr->setB(b=spinB->value());
    objExpr->setH(h=spinH->value());
    objExpr->setN(n=round((b-a)/h+1.0));
    //изменяется изображение
    node=objExpr->createVector();
    rectW=objExpr->rectWorld();
    update();
}
//----
void Widget::showGraph()
{
    rectW=objExpr->rectWorld();
    update();
}
//----
QRect &Widget::rectScreen()
{
    int dx=20, dy=20;
    winS=QRect(dx, dy, width()-2*dx, height()-2*dy);
    return winS;
}
//-----
void Widget::showTable()
{//Создаётся таблица
    node=objExpr->createVector();
    table->setRowCount(1);
    table->setRowCount(n);        table->setColumnCount(2);
    table->setHorizontalHeaderLabels(QStringList()<<"x"<<"f(x)");
    //ширина колонок
    table->setColumnWidth(0, 60);  table->setColumnWidth(1, 80);
    QTableWidgetItem *item;
    for( int i=0; i<n; ++i)
    {
        table->setRowHeight(i, 20);                                           //высота строки
        item=new QTableWidgetItem(QString("%1").arg(node[i].x(), 8, 'f', 2));
        table->setItem(i, 0, item);
        item->setBackground(QBrush(Qt::lightGray));
        item= new QTableWidgetItem(QString("%1").arg(node[i].y(), 8, 'f', 2));
        table->setItem(i, 1, item);
    }
}
//-----
void Widget::paintEvent(QPaintEvent *ev)
{
    begin(this);
    save();
    winS=rectScreen();
    setRenderHint(QPainter::Antialiasing, true);
    myScale(rectW, winS);
    setPen(QPen(Qt::black, 3));  setBrush(QColor(0xE0FFFF));  //lightcyan
    QPainter::drawRect(winS);
    drawParamRect(rectW, winS);                                  //выводятся параметры rectW
    setClipRect(winS);
    drawAxis(winS);

    drawGrid(rectW, h, 11, QPen(Qt::gray, 1));
    drawPolyline(node, QPen(Qt::blue, 2));
    winS=this->rect();
    restore();
    end();
}
