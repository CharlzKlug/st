//BAKALAVR\..\CURS3_AUT\parsTreeRec\parsTreeRec.cpp
//22.09.217  Кожевников А.А.
//Выражение, которое содержит знаки арифметических операций, скобки,
//запятые, числовые постоянные, переменную с именем x, имена функций,
//представляется в виде двоичного дерева
//(каждая вершина имеет не более двух последователей).
//Построенное дерево используется для вычисления выражения по
//рекурсивному  алгоритму обхода в глубину.
//Вирт Н.Алгоритмы+структуры данных=программы. 1985г.
//Бакнелл Д. Фундаментальные алгоритмы и структуры данных в Delphi.
//DiaSoft, Питер, 2006г.
//Седжвик Р. Фундаментальные алгоритмы на C++. К., DiaSoft, 2001г.
#include "parsTreeRec.h"

ParsTreeRec::ParsTreeRec(QString &str):indchr(0), x(-2)
{
    QString strFunc="pi acos asin atan cos exp fabs log pow sin sqrt func";
    qDebug()<<strFunc;
    lstFunc=strFunc.split(' ');                                 //список распознавемых функций
    str="sin(x)*x";
    indchr=0;
    root=0;
    root=generateTree(str);                                         //указатель на корень дерева
}
//-----
QString &ParsTreeRec::processingExpr(QString &str)
{//Формируется строка для анализа - без пробельных символов;
  //вычисляется разница в количестве скобок '('  и ')'
    int bracket=str.count('(')-str.count(')');
    fs=str.remove(QChar(' '));                                                  //удаляются пробелы
    qDebug()<<"fs="<< fs<<"  bracket="<<bracket;
    return fs;
}
//----ВЫРАЖЕНИЕ ПРЕДСТАВЛЯЕТСЯ В ВИДЕ ДВОИЧНОГО ДЕРЕВА
//-------------------В таком виде хранится в памяти
Node *ParsTreeRec::generateTree(QString &str)
{//Выражение представляется в виде двоичного дерева
 //Определяется указатель на корень дерева
    if (root)  deleteTree(root);
    indchr=0;                                                                                  //индекс символа
    fs=processingExpr(str);
    return root=expr();                                                                                                                                        //root-корень дерева
}
//----
qreal ParsTreeRec::evalf(qreal arg)
{//Вызывается для получения значения выражения.
  //Выполняется обход дерева в глубину (путь по дереву через все вершины)
    x=arg;
    return postOrderTraverse(root);                              //рекурсивный обход дерева
}
//----Каждая функция возвращает указатель на созданный в ней узел
//Каждому полю узла (объекта класса Node) присваивается значение в
//соответствии с егo типом (OPER, NUMBER, FUNC, VAR)
Node *ParsTreeRec::expr()
{//Выражение представляется в виде дерева.
 //Определяется указатель на корень дерева (или под/дерева)
    QChar sgn;                                                             //для хранения знака + или -
     //создаётся указатель на узел со значениями полей по умолчанию
    Node *p = new Node;
    if (sgn=fs[indchr] , sgn=='-' || sgn=='+')
    {//если первый символ в строке  знак + или -, то  поле type=NUMBER,
      //остальные поля остаются со значениями по умолчанию
        p->tn=NUMBER;
    }
    else
   //если первый символ не знак + или -, то p присваивается значение указателя,
   //который возвращается методом term();
        p=term();
    while (sgn=fs[indchr],  sgn=='+'  || sgn=='-' )                          //цикл по термам
    {//создаётся узел
        ++indchr;                                                                         //пропускается знак
        Node *t=new Node(OPER, 0, sgn, -1, p, term());
        p=t;
    }
    return p;
}
//----
Node *ParsTreeRec::term()
{//Выполняется синтаксический разбор слагаемого
    QChar sgn;
    Node *p = factor();
    while (sgn=fs[indchr], sgn=='*' || sgn=='/')
    {//создаётся узел
        ++indchr;
        Node *t = new Node(OPER, 0, sgn, -1,  p, factor());
        p=t;
    }
    return p;
}
//----
Node *ParsTreeRec::factor()
{//Выполняется синтаксический разбор множителя
    Node *p=primary();
    QChar sgn;
    while (sgn=fs[indchr], sgn=='^')
    {//создаётся узел
        ++indchr;                                                                              //пропускается ^
        Node *t=new Node(OPER, 0, sgn, -1, p, primary());
        p=t;
    }
    return p;
}
//----
Node *ParsTreeRec::primary()
{//Создаётся дерево первичного выражения
    Node *p=new Node;                          //узел со значениями полей по умолчанию
    QChar chr=fs[indchr].unicode();    
    if (chr.isDigit() || chr.isPunct())
    {//создаётся узел для постоянной
         p->tn=NUMBER;     p->val=realConst(); return p;
    }
    switch (fs[indchr].unicode())                   //анализируется числовой код символа
    {
    case '(':
        ++indchr;                                                                 //пропускается скобка '('
        p=expr();                                                       //создаётся  дерево выражения
        ++indchr;                                                                 //пропускается скобка ')'
        break;
    case 'x':                                                           //создаётся узел для переменной
         p->tn=VAR;   p->val=x;
         ++indchr;
        break;   
    case 'a': case 'c':case 'e':case 'f': case 'l':case 'p': case 's':
        p->pos=posFunc();                            //определяется позиция имени в списке
        if (p->pos==0)                                                                                      //это pi
        {//создаётся узел для постоянной
             p->tn=NUMBER;     p->val=3.14159265; break;
        }
        p->tn=FUNC;
       ++indchr;                                                                              //пропускается '('
        p->pnodeL=expr();                         //корень п/дерева для первого аргумента
        if (fs[indchr]==',')
        {
           ++indchr;                                                                          //пропускается ','
           p->pnodeR=expr();                      //корень п/дерева для второго аргумента
        }
        ++indchr;                                                                             //пропускается ')'
        break;
    default: error();
    }                                                                                                              //switch
    return p;
}
//----
int ParsTreeRec::posFunc()
{//Определяется позиция имени функции в списке
    QString name="";
    //читается идентификатор (кандидат имени встроенной функции)
    while (fs[indchr].isLetter ())   name+=fs[indchr++];
    //определяется позиция  name в списке функций
    int pos=lstFunc.indexOf (name);
    if (pos<0) error();                                                               //если=-1, нет имени
     return pos;                                               //indchr указывает на символ за name
}
//----
qreal ParsTreeRec::valueFunc(Node *p)
{//Вычисляется значение функции; p-указатель на узел
    qreal u, v=0;
    //вычисляются аргументы-выражения функции
    u=postOrderTraverse(p->pnodeL);                      //значение аргумента функции
    //вычисляется 2-ой  аргумент  функции, если он есть
    if (p->pnodeR) v=postOrderTraverse(p->pnodeR);
    switch (p->pos)
    {//Вызываются функции библиотеки Qt  и функции пользователя
     //(можно вызывать функции cmath: acos, asin, atan ...)
    case 1:   u=qAcos(u);                       break;
    case 2:   u=qAsin(u);                        break;
    case 3:   u=qAtan(u);                       break;
    case 4:   u=qCos(u);                        break;
    case 5:   u=qExp(u);                        break;
    case 6:   u=qFabs(u);                       break;
    case 7:   u=(u<=0)? error():qLn(u); break;
    case 8:   u=qPow(u, v);                    break;
    case 9:   u=qSin(u);                          break;
    case 10: u=(u<0)? error():qSqrt(u); break;
    case 11: u=func(u);                          break;                   //функция пользователя
    }
    return p->val=u;
}
//----
qreal ParsTreeRec::realConst()
{//анализируется строка-число и вычисляется число (>=0)
    QString  s="0123456789.",  snum="";
    while (s.contains (fs[indchr]))    snum+=fs[indchr++];
    return snum.toDouble ();          //indchr указывает на следующий символ строки
}
//----РЕКУРСИВНЫЙ ОБХОД ДЕРЕВА
qreal ParsTreeRec::postOrderTraverse(Node *p)
{//Вычисляется значение выражения
  //Используется рекурсивный обход дерева в глубину; p=root при старте
    qreal u, v;
    if(p)
    {
        switch (p->tn)                                                                          //тип лексемы?
        {
    case NUMBER: return p->val;         //значение поля вычисляется при генерации
    case OPER:
        u=postOrderTraverse(p->pnodeL);
        v=postOrderTraverse(p->pnodeR);
        switch (p->oper.unicode ())
        {
        case '+':   u+=v;              break;
        case '-' :   u-=v;               break;
        case '*':   u*=v;               break;
        case '/' :   u/=v;                break;
        case '^':   u=qPow(u, v);  break;
        }                                                                                   //switch oper.unicode()
        break;
    case VAR      :  u=x;             break;
    case FUNC    :  u=valueFunc(p);break;
    case NOLEX  :  break;
        }                                                                                              //switch (p->tn)
    }                                                                                                                 //if(p)
    return p->val=u;
}
//-----
void ParsTreeRec::deleteTree(Node *p)
{//Освобождается память от узлов
    if (p)
    {
        deleteTree(p->pnodeL);        deleteTree(p->pnodeR);
        delete(p);
    }
}
//----
qreal ParsTreeRec::func(qreal x)
{//Пример функции пользователя
    if (x<0) return -qExp(qLn(-x)/3);
    else
        if (x>0) return qExp(qLn(x)/3);
    return 0;
}
//----
qreal ParsTreeRec::error()
{//выводится сообщение об ошибке в записи выражения
    qDebug()<<"ERROR ---- ";
    return qInf();
}
//----
ParsTreeRec::~ParsTreeRec(){}
