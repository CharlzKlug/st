#include <QCoreApplication>
#include "pt.h"
#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    PT b("-x+x+x");
    std::cout << b.Eval(3) << "\n";
    return a.exec();
}
