#ifndef OBJECT3D_H
#define OBJECT3D_H
#include <QtGlobal>
class Object3D{
private:
    qreal ** objectDots; // Координаты (x, y, z)
    qreal ** dotsLinks; // Взаимосвязи точек (1 соединяется с 2 и т.д.)
public:
    Object3D(qreal ** dots, int r, int c);
};

#endif // OBJECT3D_H
