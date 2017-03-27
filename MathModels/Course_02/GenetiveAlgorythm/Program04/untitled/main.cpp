#include <QCoreApplication>
#include "mathlib.h"
#include <iostream>
const double p = 0.5, threshold = 0.1;
const int totalMembers=100;

double getNewMember(double A, double B){
    double res = (A + B)/2;
    if (p <= rnd()){
        res = res + rnd(-1,1);
    }
    return res;
}



double testFun(double x){
    return x*x-3*x+2;
}

int selectMember(double arr[], int count,
bool compare(double, double)){
    int chosenID=0;
    for (int i = 1; i<count; i++){
        if (compare(arr[i], arr[chosenID]))
            chosenID = i;
    }
    return chosenID;
}

bool greaterThan(double x1, double x2){
    return testFun(x1)<testFun(x2);
}

bool lowerThan(double x1, double x2){
    return testFun(x1)>testFun(x2);
}

int getWeakest(double arr[], int count){
    return selectMember(arr, count, lowerThan);
}

int getStrongest(double arr[], int count){
    return selectMember(arr, count, greaterThan);
}

double getNewMemberX(double arr[], int parentA, int parentB){
    return (arr[parentA] + arr[parentB]) / 2;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    initGen();
    double members [totalMembers];
    for (int i = 0; i < totalMembers; i++)
        members[i] = rnd(-5, 5);

    for (int i = 0; i<totalMembers; i++)
        std::cout << "Member[" << i << "] = " << members[i] << "\n";

    int parentA, parentB, weakestMember, x;
    for (int j = 1; j < 1000000; j++){
        for (int i = 1; i <= 5; i++){
            parentA = 0;
            parentB = 1;

            while (members[parentA] * members[parentB] > 0){
                parentA = static_cast <int> (rnd(0, totalMembers-1));
                parentB = static_cast <int> (rnd(0, totalMembers-1));
            }

            x=getNewMemberX(members, parentA, parentB);
            weakestMember = getWeakest(members, totalMembers);
            members[weakestMember] = x;
        }}
    int strongID = getStrongest(members, totalMembers);
    //int strongID = getWeakest(members, totalMembers);
    // Определение решений подпадающих под порог
    for (int i=0; i<totalMembers; i++){
        if (fabs(testFun(members[strongID])-
                 testFun(members[i])) <= threshold){
            std::cout << "Index: " << i << "\n";
            std::cout << " X = " << members[i] << "\n";
            std::cout << " Value = " << testFun(members[i]) << "\n";
        }
    }
    return a.exec();
}
