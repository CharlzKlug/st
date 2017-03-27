#include "mainwindow.h"
#include <QApplication>
#include <top.h>
#include <QTextCodec>

int main(int argc, char *argv[])
{
    QTextCodec* codec = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForTr(codec);
    QTextCodec::setCodecForCStrings(codec);
    QTextCodec::setCodecForLocale(codec);
    QApplication a(argc, argv);
    MainWindow w;
    //Top* t = new Top();
    //w.setCentralWidget(t);
    w.show();

    return a.exec();
}
