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

}

qreal Object3D::getX(int dotNumber){
    // Возврат координаты X какой-либо точки
    if (dotNumber <= dotsCount - 1)
        return objectDots[dotNumber][0];
    else
        return zero;
}

qreal Object3D::getY(int dotNumber){
    // Возврат координаты Y какой-либо точки
    if (dotNumber <= dotsCount - 1)
        return objectDots[dotNumber][1];
    else
        return zero;
}

qreal Object3D::getZ(int dotNumber){
    // Возврат координаты Z какой-либо точки
    if (dotNumber <= dotsCount - 1)
        return objectDots[dotNumber][2];
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
