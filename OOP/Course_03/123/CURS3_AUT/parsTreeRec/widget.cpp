//BAKALAVR\..\CURS3_AUT\parsTreeRec\widget.cpp
//22.09.217  Кожевников А.А.
#include "widget.h"

qreal a, b, h;                                    //вводятся для удобства описания алгоритмов
int n;
QPolygonF node;
QRectF rectW;

Widget::Widget(QWidget *parent) : QWidget(parent), MyPainter()
{
    setGeometry (100, 100, 600, 400);
    QString str="x^2*sin(x)-2*x+3";
    obj =new Exprtree(str);
    a=obj->getA(); b=obj->getB(); h=obj->getH(); n=round((b-a)/h+1.);   
    createWidgets();
    createLayouts();
    createConnections();
    //строятся таблица и график для тестовой функции
    showTable();
}
//-----
void Widget::createWidgets()
{//создаются виджеты в объекте group для ввода параметров табулир.
    group = new QGroupBox();
    group->setGeometry (width()+x()+20, y(), 250, height());
    edit = new QLineEdit(group);  
    edit->setText(obj->getExpr());
    spinA = new QDoubleSpinBox(group);
    spinA->setRange(-10, 10);   spinA->setSingleStep(0.5);
    spinA->setPrefix("A=");        spinA->setValue(a);

    spinB = new QDoubleSpinBox(group);
    spinB->setRange(-10, 10);     spinB->setSingleStep(0.5);
    spinB->setPrefix("B=");          spinB->setValue(b);

    spinH = new QDoubleSpinBox(group);
    spinH->setPrefix("H=");       spinH->setValue(h);
    spinH->setRange(0.1, 1.5); spinH->setSingleStep(0.1);
    butTab = new QPushButton("Table+Graph", group);

    table  = new QTableWidget(group);
    table->setGeometry (30, group->height()+80,  150, 250);
    group->show();
}
//-----
void Widget::createLayouts()
{
    QGridLayout *gLay = new QGridLayout(group);
    gLay->addWidget (edit, 0, 0, 1, 3);
    gLay->addWidget (spinA, 1, 0, 1, 1);
    gLay->addWidget (spinB, 1, 1, 1, 1);
    gLay->addWidget (spinH, 2, 0, 1, 1);
    gLay->addWidget (butTab, 2, 1);
    gLay->addWidget (table,  3, 0, 2, 2);
}
//-----
void Widget::createConnections()
{
     connect(edit, SIGNAL(editingFinished()), this, SLOT(slotEdit()));
     connect(butTab, SIGNAL (clicked()), this, SLOT(showTable()));
     connect(spinA, SIGNAL (valueChanged(double)),  this, SLOT(slotABH(qreal )));
     connect(spinB, SIGNAL (valueChanged(double)),  this, SLOT(slotABH(qreal )));
     connect(spinH, SIGNAL (valueChanged(double)),  this, SLOT(slotABH(qreal )));
}
//-----
void Widget::slotEdit()
{//Обрабатывается событие - окончание редактирования, т.е. нажата ENTER
  //или edit потерял фокус
    QString str=edit->text();
    obj-> generateTree(str);                                                        //создаётся дерево
}
//-----
void Widget::slotABH(qreal )
{//читаются параметры табулирования функций
    obj->setA(a=spinA->value());
    obj->setB(b=spinB->value());
    obj->setH(h=spinH->value());
    obj->setN(n=(b-a)/h+1.05);
    //изменяется изображение
    node=obj->createVector();
    rectW=obj->rectWorld();
    update();
}
//----
void Widget::showTable()
{//создаётся таблица
    node=obj->createVector();
    table->setRowCount(n);           table->setColumnCount(2);
    table->setHorizontalHeaderLabels(QStringList()<<"x"<<"f(x)");
    //ширина колонок
    table->setColumnWidth(0, 55);  table->setColumnWidth(1, 100);
    QTableWidgetItem *item;
    for( int i=0; i<n; ++i)
    {
        table->setRowHeight(i, 20);                                                       //высота ряда
        item=new QTableWidgetItem(QString("%1").arg(node[i].x(), 8, 'f', 2));
        table->setItem(i, 0, item);
        item->setBackground(QBrush(Qt::lightGray));
        item= new QTableWidgetItem(QString("%1").arg(node[i].y(), 8, 'f', 2));
        table->setItem(i, 1, item);
    }
    rectW=obj->rectWorld();
    update();
}
//-----
QRect &Widget::rectScreen()
{
    int dx=20, dy=20;
    winS=QRect(dx, dy, width()-2*dx, height()-2*dy);
    return winS;
}
//-----
void Widget::paintEvent(QPaintEvent *)
{//изображается график
    QRect rectS=rectScreen();
    begin(this);
    myScale(rectW, rectS);
    setRenderHint(QPainter::Antialiasing, true);
    drawAxis(rectS);
    setPen(QPen(Qt::blue, 2));
    drawRect(rectS);
    drawPolyline(node, QPen(Qt::blue, 2));
    drawGrid(rectW, h, 11, QPen(Qt::gray, 1));
    drawParamRect(rectW, rectS);                               //выводятся параметры rectW
    end();
}
//-----
