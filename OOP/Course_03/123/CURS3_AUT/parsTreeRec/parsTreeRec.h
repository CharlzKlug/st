//BAKALAVR\..\CURS3_AUT\parsTreeRec\parsTreeRec.h
//22.09.217  Кожевников А.А.
#ifndef PARSTREEREC_H
#define PARSTREEREC_H
#include<QtWidgets>

enum Token{OPER, NUMBER, FUNC, VAR, NOLEX};                             //типы лексем

class  Node
{//узел, соответствующий лексеме
public:
    Token tn;                               //тип лексемы(OPER, NUMBER, FUNC, VAR, NOLEX)
    qreal val;                                      //значение постоянной, переменной,функции
    QChar oper;                                                                           //символ операции
    int pos;                                                         //позиция имени функции в списке
    Node *pnodeL, *pnodeR;                            //указатели на левый и правый узлы
    //конструктор со значениями  полей по умолчанию
    Node(Token t=NOLEX, qreal d=0, QChar s=' ',  int i=-1,
                                   Node *pL=0, Node *pR=0)
      : tn(t), val(d),oper(s), pos(i), pnodeL(pL), pnodeR(pR) {}
    ~Node(){}
};
//---------
class ParsTreeRec
{
public:
    Node *root;                              //Указатель на корень дерева (на первый терм)
    qreal x;                                                                             //аргумент выражения
    int indchr;                                                            //индекс символа в выражении
    QString  fs;                                                              //анализируемое выражение
    QStringList lstFunc;                                //список имён распознаваемых функций
    QStack <Node *> stk;                            //стек для обхода дерева без рекурсии

    Node  *expr();
    Node  *term();
    Node  *factor();
    Node  *primary();
    qreal  realConst();
    int      posFunc();
    qreal  valueFunc(Node *p);
    qreal  postOrderTraverse(Node *p);    
    qreal  error();
    void   deleteTree(Node *p);
public:
    ParsTreeRec(QString &str);
    Node *generateTree(QString &str);  //выражение представляется в виде дерева

    qreal  evalf(qreal);                                  //функция для вычисления выражения
    void setX(qreal xx){x=xx;}
    qreal func(qreal x);
    QString &processingExpr(QString &str);
    QString &getExpr(){return fs;}
    ~ParsTreeRec();
};
#endif // PARSTREEREC_H
