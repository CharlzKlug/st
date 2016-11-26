#include "widget.h"
#include <QApplication>
#include <QTextCodec>

int main(int argc, char *argv[])
{
    //qApp->setStyleSheet("QLineEdit { background-color: yellow }");
    QApplication a(argc, argv);

    // Русификация для Linux
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8")); //изменения
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8")); //изменения
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8")); //изменения

    Widget w;
    QObject::connect(&w, SIGNAL(tabCloseRequest()), &a, SLOT(quit()));

    w.show();

    return a.exec();
}
