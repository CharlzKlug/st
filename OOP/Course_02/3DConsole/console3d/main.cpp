#include <QCoreApplication>
#include "Object3D.h"
#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qreal dots[2][3]={{0, 0, 0}, {0, 0, 1}};
    int myLink[] = {0, 1};
    //qreal * temp = &dots[0][0];
    Object3D myObject(&dots[0][0], 2, &myLink[0], 2);
    myObject.setZAngle(0);
    myObject.setXAngle(0);
    myObject.setYAngle(0);
    std::cout << "Dots count: " << myObject.getDotsCount() << "\n";
    std::cout << "Links count: " << myObject.getLinksCount() << "\n";
    std::cout << "First link dot: " << myObject.getLinkFirstDot(0) << "\n";
    std::cout << "Second link dot: " << myObject.getLinkSecondDot(0) << "\n";
    std::cout << "X coord: " << myObject.getX(1) << "\n";
    std::cout << "Y coord: " << myObject.getY(1) << "\n";
    std::cout << "Z coord: " << myObject.getZ(1) << "\n\n";
    for (int i = 0; i < 9; i++){
        myObject.setYAngle(3.14 * (qreal)i / 4);
        std::cout << "X coord: " << myObject.getX(1) << "\n";
        std::cout << "Y coord: " << myObject.getY(1) << "\n";
        std::cout << "Z coord: " << myObject.getZ(1) << "\n";
        std::cout << "cos(" << (3.14/4) * i << ")=" << cos((3.14/4) * i ) << "\n";
        std::cout << "\n";
    }
    std::cout << "Max distance: " << myObject.getMaxDistance() << "\n";
    return 0;
}
