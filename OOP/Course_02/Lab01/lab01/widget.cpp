#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QLabel * someLabel = new QLabel ("<CENTER> <IMG BORDER=\"0\" SRC=\"Pictures/Small/Mirrors-Edge.jpg\"> </CENTER>");
    QVBoxLayout * myLayout = new QVBoxLayout;
    myLayout->addWidget(someLabel);
    this->setLayout(myLayout);
}

Widget::~Widget()
{

}
