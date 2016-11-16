#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    tabWidget = new QTabWidget;
    //QWidget * newTab = new QWidget(tabWidget);
    tabWidget -> addTab(new Page(), tr("name"));
    tabWidget ->addTab(new Page(), tr("Second Layout"));
    tabWidget ->addTab(new Page(), tr("Thir&d Layout"));
    QVBoxLayout * layout = new QVBoxLayout();
    layout->setMargin(0);
    layout ->addWidget(tabWidget);

    setLayout(layout);
    //tabWidget -> show();
}

Widget::~Widget()
{

}
