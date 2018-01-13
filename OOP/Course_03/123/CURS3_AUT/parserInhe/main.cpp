//BAKALAVR\CURS3\parserInhe\main.cpp          16.08.2017 Кожевников А.А.
#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;   
    w.show();
    return a.exec();
}
