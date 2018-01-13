//..\curvesCombo\filefunc.cpp       22.09.2015 Кожевников А.А.
#include "filefunc.h"
//Создаётся пользователем проекта
//Глобальные определения функций
qreal f0 (qreal x)  {return x*x*sin(x)-1.4*x+2.1;}
qreal f1 (qreal x)  {return x*x*cos(x)+2*x*sin(x)-1.4;}
qreal f2 (qreal x)  {return (2-x*x)*sin(x)+4*x*cos(x);}
qreal f3 (qreal x)  {return (6-x*x)*cos(x) -6*x*sin(x);}
qreal f4 (qreal x)  {return pow(x, 2)*sin(x);}
qreal f5 (qreal x)  {return pow(x, 2)*cos(x);}
qreal f6 (qreal x)  {return sin(2*x)*cos(x);}
qreal f7 (qreal x)  {return cos(2*x)*sin(x);}
qreal f8 (qreal x)  {return x*sin(3*x);}
qreal f9 (qreal x)  {return x*cos(3*x);}
qreal f10 (qreal x)  {return pow(cos(x), 2)*x;}
qreal f11 (qreal x)  {return x;}
qreal f12 (qreal x)  {return x*x;}
//Инициализируется статический список указателей на функции
QList<PFunc>MainWin::lstFunc=
   QList<PFunc>()<<f0<<f1<<f2<<f3<<f4<<f5<<f6<<f7<<f8<<f9<<f10
                          <<f11<<f12;
