#include "lesson_10.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qreal ax = -5, bx = 5;
    TVect b;
    initRandom();
    fillArrayRand(b, ax, bx);
    printArray(b);
    //selectionSort(b);
    bubbleSort(b);
    cout<<"After selection sorting"<<endl;
    printArray(b);
    writeVectFile("/home/ametovii/Temp/vect.txt", b);
    return 0;
}
