#ifndef OBJECT3D_H
#define OBJECT3D_H
#include <QtGlobal>
const int three = 3, two = 2, zero = 0;
class Object3D{
private:
    qreal ** objectDots; // Координаты (x, y, z)
    int *dotsLinks; // Взаимосвязи точек (1 соединяется с 2 и т.д.)
public:
    Object3D(qreal *dots, int r, int * links, int dotsCount);
};

#endif // OBJECT3D_H
