#include "Object3D.h"

Object3D::Object3D(qreal *dots, int r, int * links, int dotsCount){
    // Загружаем координаты точек объекта
    objectDots = new qreal * [r];
    for (int j = zero; j < r; j++){
        objectDots[j] = new qreal [three];
        for (int i = zero; i < three; i++)
            objectDots[j][i] = dots[j*three + i];
    }

    // Загружаем связи точек
    dotsLinks = new int [dotsCount];
    for (int j = zero; j < dotsCount; j++){
        dotsLinks[j] = links[j];
    }

}

