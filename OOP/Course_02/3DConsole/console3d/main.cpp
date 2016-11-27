#include <QCoreApplication>
#include "Object3D.h"
#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qreal dots[2][3]={{0, 0, 0}, {1, 0, 0}};
    int myLink[] = {1, 2};
    //qreal * temp = &dots[0][0];
    Object3D myObject(&dots[0][0], 2, &myLink[0], 2);
/*    for (int i = 0; i < 6; i++)
        std::cout << temp[i] << "\n";
        */
    //Object3D myObject(&dots[0], 2, &myLink[0], 2);
    //qreal
    //Object3D myObject
    return 0;
}
