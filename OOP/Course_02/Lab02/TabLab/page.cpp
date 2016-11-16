#include "page.h"

Page::Page(QWidget *parent) :
    QWidget(parent)
{
    QLabel * label;
    label = new QLabel("First Label");
    QVBoxLayout * mainLayout = new QVBoxLayout;
    mainLayout -> addWidget(label);
    setLayout(mainLayout);
}
