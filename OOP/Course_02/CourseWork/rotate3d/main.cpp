#include "widget.h"
#include "Object3D.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qreal ** someDots=new qreal*[2];
    someDots[0] = new qreal[3];
    someDots[1] = new qreal[3];
    someDots[0][0] = 0;
    someDots[0][1] = 0;
    someDots[0][2] = 0;
    someDots[1][0] = 1;
    someDots[1][1] = 0;
    someDots[1][2] = 0;
    Object3D * myLine = new Object3D(someDots, 2, 3);

    Widget w;
    w.show();
    //qreal someDots[2][3] = {{1, 0, 0}, {0, 0, 0}};
    return a.exec();
}
