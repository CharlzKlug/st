#ifndef MYTHREAD_H
#define MYTHREAD_H
#include <QThread>
//#include <QtGui/>

class WorkerThread : public QThread
{
    Q_OBJECT
public:
    WorkerThread();
    //void run();
private:
    int k;
};
#endif // MYTHREAD_H

