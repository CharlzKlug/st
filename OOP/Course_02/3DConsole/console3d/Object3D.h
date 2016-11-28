#ifndef OBJECT3D_H
#define OBJECT3D_H
#include <QtGlobal>
const int three = 3, two = 2, zero = 0;
class Object3D{
private:
    qreal ** objectDots; // Координаты (x, y, z)
    int dotsCount; // Количество точек
    int *dotsLinks; // Взаимосвязи точек (1 соединяется с 2 и т.д.)
    int linksCount; // Количество связей
public:
    // Конструктор, dots - массив точек, r - количество точек
    // links - связи между точками, linksCount - количество связей
    Object3D(qreal *dots, int r, int * links, int totalLinksCount);

    // Возврат координаты X какой-либо точки. Отсчёт от 0.
    qreal getX(int dotNumber);

    // Возврат координаты Y какой-либо точки. Отсчёт от 0.
    qreal getY(int dotNumber);

    // Возврат координаты Z какой-либо точки. Отсчёт от 0.
    qreal getZ(int dotNumber);

    // Вернуть количество связей. Отсчёт от 0.
    int getLinksCount();

    // Вернуть количество точек. Отсчёт от 0.
    int getDotsCount();

    // Вернуть номер первой точки из связи
    int getLinkFirstDot(int linkNumber);

    // Вернуть номер второй точки из связи
    int getLinkSecondDot(int linkNumber);
};

#endif // OBJECT3D_H
