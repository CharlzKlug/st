#include "Object3D.h"

Object3D::Object3D(qreal *dots, int r, int * links, int totalLinksCount){
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

qreal Object3D::getX(int dotNumber){
    // Возврат координаты X какой-либо точки
    if (dotNumber <= dotsCount - 1)
        return objectDots[dotNumber][0] * cos (angleZ) +
                objectDots[dotNumber][1] * sin(angleZ);

        //return objectDots[dotNumber][0];
  else
        return zero;
}

qreal Object3D::getY(int dotNumber){
    // Возврат координаты Y какой-либо точки
    if (dotNumber <= dotsCount - 1)
//        return objectDots[dotNumber][1];
        return objectDots[dotNumber][1] * cos(angleZ) -
                objectDots[dotNumber][0] * sin(angleZ);

    else
        return zero;
}

qreal Object3D::getZ(int dotNumber){
    // Возврат координаты Z какой-либо точки
    if (dotNumber <= dotsCount - 1)
        return (objectDots[dotNumber][2] * cos(angleX) -
                objectDots[dotNumber][1] * sin(angleX)) * cos(angleY) +
                objectDots[dotNumber][0] * sin(angleY);

        //return objectDots[dotNumber][2];
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
    // Возврат номера первой точки из связи
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
    qreal distance = 0, temp;

    for (int i = 0; i < dotsCount; i++){
        temp = sqrt(getX(i)*getX(i) + getY(i)*getY(i) + getZ(i)*getZ(i));
        if (temp > distance) distance = temp;
    }
    return distance;
}

qreal Object3D::getMaxDistance()
{
    return maxD;
}
