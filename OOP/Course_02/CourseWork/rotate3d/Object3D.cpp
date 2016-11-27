#include "Object3D.h"

Object3D::Object3D(qreal **dots, int r, int c){
    objectDots = new qreal * [r];
    int current = 0;
    for (int j = 0; j < r; j++){
        objectDots[j] = new qreal [c];
        for (int i = 0; i < c; i++){
            objectDots[j][i] = dots[j][i];

        }

    }

}
