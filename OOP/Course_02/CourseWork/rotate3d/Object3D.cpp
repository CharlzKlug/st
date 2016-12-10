#include "Object3D.h"

Object3D::Object3D(qreal *dots, int r, int * links,
                   int totalLinksCount){
    // Конструктор объекта
    // Загружаем координаты точек объекта
    objectDots = new qreal * [r];
    dotsCount = r;
    for (int j = zero; j < r; j++){
        objectDots[j] = new qreal [three];
        for (int i = zero; i < three; i++)
            objectDots[j][i] = dots[j*three + i];
    }

    // Загружаем связи точек
    dotsLinks = new int [totalLinksCount];
    linksCount = totalLinksCount / 2;
    for (int j = zero; j < totalLinksCount; j++){
        dotsLinks[j] = links[j];
    }

    // Выставление начальных углов
    setXAngle(0);
    setYAngle(0);
    setZAngle(0);

    // Дистанция от начала координат до дальней точки
    maxD = maxDistance();
}

qreal Object3D::getX(int dotNumber){
    // Возврат координаты X какой-либо точки
    if (dotNumber <= dotsCount - 1)
        return (objectDots[dotNumber][0] * cos (angleZ) -
                objectDots[dotNumber][1] * sin(angleZ)) * cos (angleY) +
                objectDots[dotNumber][2] * sin(angleY);
    else
        return zero;
}

qreal Object3D::getY(int dotNumber){
    // Возврат координаты Y какой-либо точки
    if (dotNumber <= dotsCount - 1)
        return (objectDots[dotNumber][1] * cos(angleZ) +
                objectDots[dotNumber][0] * sin(angleZ)) * cos(angleX) -
                objectDots[dotNumber][2] * sin(angleX);
    else
        return zero;
}

qreal Object3D::getZ(int dotNumber){
    // Возврат координаты Z какой-либо точки
    if (dotNumber <= dotsCount - 1)
        return (objectDots[dotNumber][2] * cos(angleX) +
                objectDots[dotNumber][1] * sin(angleX)) * cos(angleY) -
                objectDots[dotNumber][0] * sin(angleY);
    else
        return zero;
}

int Object3D::getLinksCount(){
    // Возврат количества связей
    return linksCount;
}

int Object3D::getDotsCount(){
    // Возврат количества точек
    return dotsCount;
}

int Object3D::getLinkFirstDot(int linkNumber){
    // Возврат номера первой точки из связи
    if (linkNumber <= linksCount - 1 && linkNumber >= 0)
        return dotsLinks[linkNumber * 2];
    else
        return -1;
}

int Object3D::getLinkSecondDot(int linkNumber){
    // Возврат номера второй точки из связи
    if (linkNumber <= linksCount - 1 && linkNumber >= 0)
        return dotsLinks[linkNumber * 2 + 1];
    else
        return -1;
}

void Object3D::setZAngle(qreal angle){
    // Установка угла поворота вокруг оси Z
    angleZ = angle;
}

void Object3D::setXAngle(qreal angle){
    // Установка угла поворота вокруг оси X
    angleX = angle;
}

void Object3D::setYAngle(qreal angle){
    // Установка угла поворота вокруг оси Y
    angleY = angle;
}

qreal Object3D::maxDistance()
{
    // Вычисление дистанции от начала координат до дальней точки
    qreal distance = 0, temp;

    for (int i = 0; i < dotsCount; i++){
        temp = sqrt(getX(i)*getX(i) + getY(i)*getY(i) + getZ(i)*getZ(i));
        if (temp > distance) distance = temp;
    }
    return distance;
}

qreal Object3D::getMaxDistance()
{
    // Возврат дистанции от начала координат до дальней точки
    return maxD;
}

qreal Object3D::getAngleX(){
    // Возврат угла поворота вокруг оси X
    return angleX;}

qreal Object3D::getAngleY(){
    // Возврат угла поворота вокруг оси Y
    return angleY;}

qreal Object3D::getAngleZ(){
    // Возврат угла поворота вокруг оси Z
    return angleZ;}

void Object3D::resetObject(){
    // Сброс данных объекта
    delete [] objectDots;
    dotsCount = 0;
    delete [] dotsLinks;
    linksCount = 0;
    maxD = 0;
}

void Object3D::setObject(qreal * dots, int r, int * links, int totalLinksCount){
    // Установка нового объекта
    // Загружаем координаты точек объекта
    objectDots = new qreal * [r];
    dotsCount = r;
    for (int j = zero; j < r; j++){
        objectDots[j] = new qreal [three];
        for (int i = zero; i < three; i++)
            objectDots[j][i] = dots[j*three + i];
    }

    // Загружаем связи точек
    dotsLinks = new int [totalLinksCount];
    linksCount = totalLinksCount / 2;
    for (int j = zero; j < totalLinksCount; j++){
        dotsLinks[j] = links[j];
    }
    maxD = maxDistance();
}
