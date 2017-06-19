#ifndef GEOMETRYFUNCTIONS_H
#define GEOMETRYFUNCTIONS_H
#include <QPoint>
#include <QVector>
#include <iostream>

// nf2 - возвращает положение третьей точки
// относительно прямой, проходящей через
// первые две точки.
// если результат nf2 больше нуля, то
// третья точка лежит справа от прямой,
// если результат nf2 меньше нуля, то
// третья точка лежит слева от прямой
// если результат nf2 равен нулю, то
// третья точка лежит на прямой
double nf2(QPoint, QPoint, QPoint);

// Возвращает true если третья точка
// находится впереди вектора из первой и
// второй точки
bool isForward(QPoint, QPoint, QPoint);

// Возвращает true если третья точка
// находится сзади вектора из первой и
// второй точки
bool isBackward(QPoint, QPoint, QPoint);

// Возвращает упрощённый полигон
QVector<QPoint> min_poly(QVector<QPoint> p);

// Возвращает октантую меру угла между
// векторами первая-вторая точки и
// первая третья точки
int oct_cor(QPoint, QPoint, QPoint);

// Возвращает октантный угол вектора
int oct(QPoint);

// Возвращает 1 при int>=0 и
// -1 при int<0
int sgn(int);

// Тест направления обхода полигона
// возвращает 1 при обходе против часовой
// стрелки, -1 при обходе по часовой
// стрелке
int dir_test(QVector<QPoint>);

// Тест полигона на выпуклость
// (возвращает 1), невыпуклость
// (возвращает 0), полигон с
// развёрнутым углом (возвращает
// -1)
int conv2(QVector<QPoint>);

// Сдвиг точек полигона влево
QVector<QPoint> LCShift(QVector<QPoint>);

// Проверка на пересечение отрезка первая-вторая точки и
// отрезка третья-четвёртая точки.
// -1 - отрезки параллельны и не совпадают,
// 0 - непараллельные отрезки не пересекаются,
// 1 - отрезки касаются или пересекаются.
// 2 - два лежащих друг на друге параллельных отрезка.
// В пятый QPoint& заносится точка пересечения
int cross_segm(QPoint, QPoint, QPoint, QPoint, QPoint&);

// Некоторая процедура обработаки полигона
void process_poly(QVector<QPoint>);

// Триангуляция полигона
QVector<QPoint> tri_poly(QVector<QPoint>);

// Возвращает true если отрезки 1-2 и 3-4 пересекаются
// возвращает false если отрезки не пересекаются
bool isCrossed(QPoint, QPoint, QPoint, QPoint);

// Возвращает true если полигон самопересекающийся,
// возвращает false если полигон несамопересекающийся
bool isCrossedPoly(QVector<QPoint>);

// Находится ли третья точка внутри отрезка 1-2.
// Возвращает отрицательное значение если находится внутри
// Возвращает положительное значение если находится снаружи
int inter_paral(QPoint, QPoint, QPoint);

// Поиск подходящей вершины для деления полигона
QVector<QPoint> find_poly_node(QVector<QPoint>, int, int, int);

// Разбиение полигона на два полигона по заданной
// вершине
QVector<QPoint> split_poly(QVector<QPoint> p, int k);
#endif // GEOMETRYFUNCTIONS_H
