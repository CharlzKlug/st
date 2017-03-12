#include <QCoreApplication>
#include "mathlib.h"
#include <iostream>
const double p = 0.3, threshold = 0.1;
const int totalMembers=15;

double getNewMember(double A, double B){
    double res = (A + B)/2;
    if (p <= rnd()){
        res = res + rnd(-1,1);
    }
    return res;
}

double testFun(double x, double y){
    //return (x-1)*(x-1)+(y+2)*(y+2);
    return sin(x)*cos(2*y)+sqrt(abs(x*y))/20;
}

int selectMember(double arr[][2], int count,
bool compare(double, double, double, double)){
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
    for (int j = 1; j < 10; j++){
        for (int i = 1; i <= 5; i++){
            parentA = static_cast <int> (rnd(0, totalMembers-1));
            parentB = static_cast <int> (rnd(0, totalMembers-1));
            x = getNewMember(members [parentA][0], members [parentB][0]);
            y = getNewMember(members [parentA][1], members [parentB][1]);
            weakestMember = getWeakest(members, totalMembers);
            members[weakestMember][0] = x;
            members[weakestMember][1] = y;
        }}
    int strongID = getStrongest(members, totalMembers);

    // Определение решений подпадающих под порог
    for (int i=0; i<totalMembers; i++){
        if (fabs(testFun(members[strongID][0], members[strongID][1])-
                 testFun(members[i][0], members[i][1])) <= threshold){
            std::cout << "Index: " << i << "\n";
            std::cout << " X = " << members[i][0] << "\n";
            std::cout << " Y = " << members[i][1] << "\n";
            std::cout << " Value = " << testFun(members[i][0], members[i][1]) << "\n";

        }
    }
    return a.exec();
}
