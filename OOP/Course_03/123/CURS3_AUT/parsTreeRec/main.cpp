//BAKALAVR\..\CURS3_AUT\parsTreeRec\main.cpp
//22.09.217  Кожевников А.А.
#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    
    return a.exec();
}
