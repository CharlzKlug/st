#include "controlwidget.h"

ControlWidget::ControlWidget(QWidget *parent) :
    QWidget(parent)
{
    QLabel* myLabel = new QLabel("Test label");
    QVBoxLayout* myLayout = new QVBoxLayout;
    myLayout->addWidget(myLabel);
    this->setLayout(myLayout);
}
