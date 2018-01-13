//BAKALAVR\CURS3\parserInhe\parserInhe.h          16.08.2017 Кожевников А.А.
//Анализируется, интерпретируется  и вычисляется
//символьное выражение,  которое содержит имя аргумента, числовые
//постоянные, знаки операций, круглые скобки  и имена функций;
//тип ошибки не определяется.
#ifndef PARSERINHE_H
#define PARSERINHE_H
#include <QtWidgets>

class ParserInhe
{
//public:
    qreal x;                                                                               //аргумент   функции
    int ind;                                                                 //индекс символа в выражении
    QString  fs;                                                                   //символьное выражение    
    QStringList lstFunc;                                                          //список имён функций
    qreal expr();
    qreal term();
    qreal factor();
    qreal primary();
    qreal realConst();
    qreal valueFunc();
    int    posFunc();                                   //позиция имени функции в списке lstFunc
    qreal power(qreal x, int m);
public:
    ParserInhe(QString &str);
    qreal getX(){return x;}
    void setX(qreal xx){x=xx;}
    //редактируется символьное выражение (ф-ия выполняет роль модификатора)
    QString &processingExpr(QString &str);
    QString &getStr(){return fs;}
    qreal evalf(QString &str);                                               //вычисляется выражение
    qreal error();
    qreal func(qreal x);                                     //определяется функция пользователя
    ~ParserInhe(){}
};
#endif // PARSERINHE_H
