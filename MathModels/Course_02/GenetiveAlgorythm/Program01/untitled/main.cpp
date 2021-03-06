#include <QCoreApplication>
#include "mathlib.h"
#include <iostream>
const double p = 0.3;
const int totalMembers=15;

double getNewMember(double A, double B){
    double res = (A + B)/2;
    if (p <= rnd()){
        res = res + rnd(-1,1);
    }
    return res;
}

double testFun(double x, double y){
    return (x-1)*(x-1)+(y+2)*(y+2);
}

int selectMember(double arr[][2], int count, bool compare(double, double, double, double)){
    int chosenID=0;
    for (int i = 1; i<count; i++){
        if (compare(arr[i][0], arr[i][1], arr[chosenID][0], arr[chosenID][1]))
            chosenID = i;
    }
    return chosenID;
}

bool greaterThan(double x1, double y1, double x2, double y2){
    return testFun(x1, y1)>testFun(x2, y2);
}

bool lowerThan(double x1, double y1, double x2, double y2){
    return testFun(x1, y1)<testFun(x2, y2);
}

int getWeakest(double arr[][2], int count){
    return selectMember(arr, count, greaterThan);
}

int getStrongest(double arr[][2], int count){
    return selectMember(arr, count, lowerThan);
}


//int getWeakest(double arr[][2], int count, double fun(double, double) ){
//    int weakID=0;
//    for (int i = 1; i<count; i++){
//        if (fun(arr[i][0],arr[i][1]) > fun(arr[weakID][0],arr[weakID][1]))
//            weakID = i;
//    }
//    return weakID;
//}


//int getStrongest(double arr[][2], int count, double fun(double, double)){
//    int strongID=0;
//    for (int i = 1; i<count; i++){
//        if (fun(arr[i][0],arr[i][1]) < fun(arr[strongID][0],arr[strongID][1]))
//            strongID = i;
//    }
//    return strongID;
//}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    initGen();
    double members [totalMembers][2];
    for (int i = 0; i < totalMembers; i++){
        members[i][0] = rnd(-100, 100);
        members[i][1] = rnd(-100, 100);
    }

    for (int i = 0; i<totalMembers; i++){
        std::cout << "X[" << i << "] = " << members[i][0] << "\n";
        std::cout << "Y[" << i << "] = " << members[i][0] << "\n";
        //std::cout << rnd(-2,2) << "\n";
    }
    int parentA, parentB, weakestMember, x, y;
    for (int j = 1; j < 1000; j++){
        for (int i = 1; i <= 5; i++){
            parentA = static_cast <int> (rnd(0, 14));
            parentB = static_cast <int> (rnd(0, 14));
            x = getNewMember(members [parentA][0], members [parentB][0]);
            y = getNewMember(members [parentA][1], members [parentB][1]);
            weakestMember = getWeakest(members, 15);
            members[weakestMember][0] = x;
            members[weakestMember][1] = y;
        }}
    int strongID = getStrongest(members, 15);
    std::cout << "X = " << members[strongID][0] << "\n";
    std::cout << "Y = " << members[strongID][1] << "\n";
    return a.exec();
}
