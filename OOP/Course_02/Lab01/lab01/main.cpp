#include "widget.h"
#include <QApplication>
#include <QLabel>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    //QLabel * lbl = new QLabel ("0");

    w.show();

    return a.exec();
}
