#ifndef OBJECT3D_H
#define OBJECT3D_H
#include <QtGlobal>
#include <cmath>

const int three = 3, two = 2, zero = 0;
class Object3D{
private:
    qreal ** objectDots; // Координаты (x, y, z)
    int dotsCount; // Количество точек
    int *dotsLinks; // Взаимосвязи точек (1 соединяется с 2 и т.д.)
    int linksCount; // Количество связей
    qreal angleZ; // Поворот вокруг оси Z (радианы)
    qreal angleX; // Поворот вокруг оси X (радианы)
    qreal angleY; // Поворот вокруг оси Y (радианы)
    qreal maxD; // Дистанция от начала координат то самой удалённой точки

    // Расстояние от центра до самой удалённой точки 3Д объекта
    qreal maxDistance();

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

    // Вернуть количество связей. Отсчёт от 1.
    int getLinksCount();

    // Вернуть количество точек. Отсчёт от 1.
    int getDotsCount();

    // Вернуть номер первой точки из связи
    int getLinkFirstDot(int linkNumber);

    // Вернуть номер второй точки из связи
    int getLinkSecondDot(int linkNumber);

    // Установить поворот вокруг оси Z (в радианах)
    void setZAngle(qreal angle);

    // Установить поворот вокруг оси X (в радианах)
    void setXAngle(qreal angle);

    // Установить поворот вокруг оси Y (в радианах)
    void setYAngle(qreal angle);

    qreal getAngleZ();
    qreal getAngleX();
    qreal getAngleY();
    // Возвращает максимальную дистанцию
    qreal getMaxDistance();
};

#endif // OBJECT3D_H
