#include "widget.h"
#include "Object3D.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Widget w;
    w.show();
    //qreal someDots[2][3] = {{1, 0, 0}, {0, 0, 0}};
    return a.exec();
}
