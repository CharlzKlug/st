//..\curvesCombo\mainwin.cpp           22.09.2015  Кожевников А.А.
#include "mainwin.h"
#include "function.h"

typedef qreal TFunc (qreal);
typedef TFunc* PFunc;
qreal a, b, h;                                                               //параметры табулирования
int n;
QPolygonF node;
QRectF rectW;
//========================================
MainWin::MainWin(QWidget *parent)  : QMainWindow(parent),  MyPainter()
{
    wid=new QWidget(this);
    setCentralWidget(wid);
    setGeometry(100, 100, 600, 600);
    obj=new Function(lstFunc[0]);
    a=obj->getA(), b=obj->getB(), h=obj->getH();
    n=obj->getN();
    createWidgets();
    createLayouts();
    createConnections();
    slotComboExp(0);
    node=obj->createVector();
    rectW=obj->rectWorld();
}
//-----
void MainWin::createWidgets()
{
    dock = new QDockWidget("dock (click me twice)", this);
    dock->setGeometry(x()+width(), y()-35, 300, 200);
    dock->setFloating(true);
    addDockWidget(Qt::RightDockWidgetArea, dock);
    group = new QGroupBox();
    group->setStyleSheet("background-color:silver; border:2px solid blue");
    dock->setWidget(group);

    sliderA = new QSlider(Qt::Horizontal, group);
    sliderA->setRange(0, 100);  sliderA->setValue((a+10)/0.2);
    sliderA->setSingleStep(1);   sliderA->setPageStep(1);
    labelA = new QLabel(group);
    labelA->setText(QString("A=%1").arg(a));
    sliderB = new QSlider(Qt::Horizontal, group);
    sliderB->setRange(0, 100);    sliderB->setValue((b+5)/0.2);
    sliderB->setSingleStep(1);     sliderB->setPageStep(1);
    labelB = new QLabel(group);
    labelB->setText(QString("B=%1").arg(b));

    sliderN = new QSlider(Qt::Horizontal, group);
    sliderN->setRange(1, 50);
    sliderN->setSingleStep(1); sliderN->setPageStep(5);
    sliderN->setValue(11);
    labelN = new QLabel(group);
    labelN->setText(QString("N=%1").arg(sliderN->value()));

    comboExp = new QComboBox(group) ;
    comboExp->resize(300, 500);
    readExpressions();
    comboExp->addItems(lstExp);
    comboExp->setMaxVisibleItems(15);
}
//-----
void MainWin::slotSlider(int k)
{   
   obj->setA(a=0.2*sliderA->value()-10);
   obj->setB(b=0.2*sliderB->value()-5);
   obj->setN(n=sliderN->value());
   obj->setH(h=(b-a)/(n-1));
   node=obj->createVector();
   rectW=obj->rectWorld();
   labelA->setText(QString("A=%1").arg(a));
   labelB->setText(QString("B=%1").arg(b));
   labelN->setText(QString("N=%1").arg(n));
   update();
}
//----
void MainWin::createLayouts()
{
    QGridLayout *gLay = new QGridLayout(group);
    gLay->addWidget(labelA, 0, 0); gLay->addWidget(sliderA, 0, 1, 1, 2);
    gLay->addWidget(labelB, 1, 0); gLay->addWidget(sliderB, 1, 1, 1, 3);
    gLay->addWidget(labelN, 2, 0); gLay->addWidget(sliderN, 2, 1, 1, 3);
    gLay->addWidget(comboExp, 6, 0, 1, 2);
}
//-----
void MainWin::createConnections()
{   
    connect(comboExp, SIGNAL(activated(int)), this, SLOT(slotComboExp(int)));
    connect(sliderA, SIGNAL(valueChanged(int)), this, SLOT(slotSlider(int)));
    connect(sliderB, SIGNAL(valueChanged(int)), this, SLOT(slotSlider(int)));
    connect(sliderN, SIGNAL(valueChanged(int)), this, SLOT(slotSlider(int)));
}
//-----
void MainWin::readExpressions()
{
    QFile file(":/filestr.txt");                                     //используется файл ресурсов
//    QFile file("../mainGraphs/filestr.txt");               //файл ресурсов не используется
    if (!file.exists())
    {
        qDebug()<<"File is not exist"; return;
    }
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug()<<"File is no open"; return;
    }
    //Читаются выражения из файла и
    //инициализируется список символьных выражений(функций)
    QString line;
    lstExp.clear();
/*    while (!file.atEnd())
    {
         line=file.readLine();
         lstExp<<line;
    }*/
     //Используется поток ввода-вывода QTextStream
     QTextStream in(&file);
     while (!in.atEnd())
    {
        line=in.readLine();
        lstExp<<line;
    }
    file.close();
}
//----
void MainWin::slotComboExp(int k)
{//Выполняется операция (пункт)
    obj->setPFunc(lstFunc[k]);     
    node=obj->createVector();
    rectW=obj->rectWorld();
    update();
}
//----
QRect &MainWin::rectScreen()
{
    int dx=20, dy=20;
    winS=QRect(dx, dy, width()-2*dx, height()-2*dy);
    return winS;
}
//-----
void MainWin::paintEvent(QPaintEvent *ev)
{
    begin(this);
    save();
    winS=rectScreen();
    setRenderHint(QPainter::Antialiasing, true);
    myScale(rectW, winS);
    setPen(QPen(Qt::black, 3));  setBrush(QColor(0xE0FFFF));  //lightcyan
    QPainter::drawRect(winS);
    drawParamRect(rectW, winS);                               //выводятся параметры rectW
    setClipRect(winS);
    drawAxis(winS);

    drawGrid(rectW, h, 11, QPen(Qt::gray, 1));
    drawPolyline(node, QPen(Qt::blue, 2));
    setPen(QPen(Qt::blue, 1)); setBrush(QBrush(Qt::green)); drawEllipse(sa, 5, 5);
    winS=this->rect();
    restore();
    end();
}
//-----
MainWin::~MainWin(){ }
//----

