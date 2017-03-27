#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QDockWidget* dock = new QDockWidget("Control panel", this);
    //DockWidget* myDockWidget = new DockWidget();
    //dock->setWidget(modes);
    drawWidget = new Top();
    addDockWidget(Qt::LeftDockWidgetArea, dock);
    ControlWidget* someWidget = new ControlWidget();
    dock->setWidget(someWidget);
    setCentralWidget(drawWidget);

}

MainWindow::~MainWindow()
{

}

//void MainWindow::paintEvent(QEvent *)
//{
//    QPainter painter(this);
//    painter.setPen(Qt::blue);
//    painter.setFont(QFont("Arial", 30));
//    painter.drawText(rect(), Qt::AlignCenter, "Qt");
//    this->setWindowTitle("dkdjf");
//}
