//BAKALAVR\CURS3\parserInhe\parserInhe.cpp          16.08.2017 Кожевников А.А.
#include "parserInhe.h"
ParserInhe::ParserInhe(QString &str): x(-2), ind(0)
{  
    QString strFunc="pi acos asin atan cos exp fabs log pow sin sqrt func";
    lstFunc=strFunc.split(' ');                        //список  имён распознаваемых функций
    fs=processingExpr(str);                                                    //готовится выражение
}
//----
QString &ParserInhe::processingExpr(QString &str)
{//Формируется строка-выражение для анализатора  str->fs (редактируется):
 //исключаются пробелы и вычисляется разница в количестве скобок '('  и ')'
    int bracket=str.count(')')-str.count('(');
    if (bracket)
    {
        qDebug()<<"bracket="<<bracket<<str<<"---ERROR---"; return str;
    }
    fs=str.remove(QChar(' '));                                                   //удаляются пробелы
    qDebug()<<"fs="<<fs;
    fs+="#";                                                          //добавляется граничный символ
    return fs;
}
//-----
qreal ParserInhe::evalf(QString &str)
{//Начинается синтаксический анализ выражения
    if (fs!=str)   fs=processingExpr(str);      //исключается повторное редактирование
    ind=0;                                                                                  //счётчик символов
    return expr();
}
//-----
qreal ParserInhe::expr()
{//Вычисляется выражение
    qreal u=0, sum=0;
    QChar sgn=fs.at (ind);                                            //для хранения знака + или -
    if (sgn=='-' || sgn=='+')  sum=0;    else sum=term() ;
    while (sgn=fs.at (ind),  sgn=='+'  || sgn=='-' )
    {        
        ++ind;
        u=term();
        (sgn=='-')? sum-=u: sum+=u;
    }    
    return sum;
}
//----
qreal ParserInhe::term()
{//Анализируется и вычисляется слагаемое
    qreal u, v;
    QChar sgn;
    u=factor();
    while(sgn=fs.at(ind), sgn=='*' || sgn=='/' )
    {
        ++ind;
        v=factor();
        (sgn=='*')? u*=v: u/=v;
    }           
    return u;                                       //ind указывает на следующий символ строки
}
//----
qreal ParserInhe::factor()
{//анализируется и вычисляется множитель
    qreal u;
    u=primary();
    if (fs.at (ind)== '^')
    {
        ++ind;                                                                                 //пропускается '^'
        qreal w=primary (); u= power(u, w);
    }
    return u;                                        //ind указывает на следующий символ строки
}
//----
qreal ParserInhe::primary()
{//Вычисляется первичное выражение: постоянная , переменная,
 //функция, выражение в скобках
    qreal u=0;
    QChar chr=fs.at (ind).unicode ();
    if (chr==QChar('('))
    {
        ++ind; u=expr();               //пропускается скобка '(' и вычисляется выражение
        ++ind;                                                                      //пропускается скобка ')'
    }
    else
        if (chr.isDigit() || chr.isPunct()) u=realConst();
        else
           if (chr==QChar('x')) {++ind;  u=x;}
           else
              if (QString("aceflps").contains(chr))  u=valueFunc();
    return u;
}
//----
qreal ParserInhe::realConst()
{//анализируется строка-число и вычисляется число (>=0)
    QString  s="0123456789.",  snum="";
    while (s.contains (fs.at (ind)))    snum+=fs.at (ind++);
    return snum.toDouble ();               //ind указывает на следующий символ строки
}
//----
int ParserInhe::posFunc()
{//Определяется позиция имени функции в списке
    QString name="";
    //читается имя функции в строке (кандидат )
    while (fs.at(ind).isLetter ())  name+=fs.at(ind++);
    int pos=lstFunc.indexOf (name);
    if (pos<0) error();                                                               //если=-1, нет имени
    return  pos;                                                   //ind указывает на символ за name
}
//----
qreal ParserInhe::valueFunc()
{//Вычисляется значение функции
    qreal u, v=0;
    int pos=posFunc();
    if (!pos) return 3.14159265;                                                        //число pi(pos=0)
    ++ind;                                           //пропускается скобка '(' аргумента функции
    //вычисляется аргумент-выражение функции (возможно, 1-ый из двух)
    u=expr();
    if (fs.at (ind)==',') ++ind, v=expr();                  //вычисляется 2-ой аргумент v
    ++ind;                                           //пропускается скобка ')' аргумента функции

    switch (pos)
    {//Вызываются функции библиотеки Qt  и функции пользователя
     //(можно вызывать функции cmath: acos, asin, atan ...)
    case 1:   u=qAcos(u);                       break;
    case 2:   u= qAsin(u);                       break;
    case 3:   u= qAtan(u);                      break;
    case 4:   u= qCos(u);                       break;
    case 5:   u= qExp(u);                        break;
    case 6:   u= qFabs(u);                      break;
    case 7:   u= (u<=0)? error():qLn(u);break;
    case 8:   u= qPow(u, v);                   break;
    case 9:   u= qSin(u);                         break;
    case 10: u= (u<0)? error():qSqrt(u);break;
    case 11: u= func(u);                         break;                   //функция пользователя
    }
    return u;
}
//----
qreal ParserInhe::error()
{//выводится сообщение об ошибке в записи выражения
    qDebug()<<"ERROR ---- ";
    return qInf();
}
//----
qreal ParserInhe::power(qreal x, int m)
{//Вычисляется целая степень m числа x --->x^m
    if (fabs(x)<1E-9) return 0;
    if (!m) return 1;
    int k=m<0?-m:m;
    qreal z=power(x, k/2),  y=(k%2)? z*z*x : z*z;
    return m<0? 1/y:y;
}
//----
qreal ParserInhe::func(qreal x)
{
    if (x<0) return -qExp(qLn(-x)/3);
    else
        if (x>0) return qExp(qLn(x)/3);
    return 0;
}
