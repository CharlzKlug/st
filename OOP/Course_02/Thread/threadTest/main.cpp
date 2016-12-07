#include <QCoreApplication>
#include "myThread.h"
#include <iostream>
#include "main.moc"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    std::cout << "Hi there!\n";
    WorkerThread mythre;
    //mythre.start();
    //yetAnother.start(QThread::IdlePriority);
    return a.exec();
}
