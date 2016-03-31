#ifndef MYFUNCTIONS_H
#define MYFUNCTIONS_H
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int menu();

double f(double);

double d(double);

double math_deriv(double);

void choice1();

void choice2();

void choice3();

void choice4();

double dispx1(double,  double);

double dispx2(double,  double);


void choice5();

// Рекурсивное вычисление нуля методом дихотомии
double dixotomy_recursive(double, double, double);

// Рекурсивное вычисление нуля функции методом Ньютона
double Newton_recursive(double, double, double, double);

void choice6();


#endif // MYFUNCTIONS_H
