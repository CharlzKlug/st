#ifndef SLEEPER_H
#define SLEEPER_H
#include <QThread>

// Объект паузы в процессе работы треда
class Sleeper : public QThread
{
public:
    static void usleep(unsigned long usecs){QThread::usleep(usecs);}
    static void msleep(unsigned long msecs){QThread::msleep(msecs);}
    static void sleep(unsigned long secs){QThread::sleep(secs);}
};
#endif // SLEEPER_H
