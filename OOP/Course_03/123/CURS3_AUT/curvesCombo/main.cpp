//..\curvesCombo\main.cpp           22.09.2015  Кожевников А.А.
//Проект для изображения  одного из n графиков  функций.
//Выражения для функций задаются в файле filstr.txt,
//функции определяются в файле filefunc.cpp (filefunc.h)
#include "mainwin.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWin w;
    w.setWindowTitle(QObject::tr("Построение графиков функций"));
    w.show();
    
    return a.exec();
}
