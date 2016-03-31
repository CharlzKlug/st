#include "opervector.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    srand(time(0));
    qreal ax = -10, bx = 10;
    TVect myVect;
    TVect myNegVect;    // Для отрицательных значений.
    char selectedMenu;
    bool EvenOrOdd; // Чётный или нечётный элемент массива.

    while ((selectedMenu = menu()) != 'X')
    {
        switch (selectedMenu) {
        case 'A':   // Перемещение чётных и нечётных индексов.
            cout<<"0 - сдвигать нечётные элементы массива, 1 - сдвигать чётные элементы: ";
            cin>>EvenOrOdd;
            fillVect(myVect, ax, bx);
            cout<<"До перемещения"<<endl;
            outputArray(myVect);
            moveItemOddorEven(myVect, EvenOrOdd);
            cout<<"После перемещения"<<endl;
            outputArray(myVect);
            break;
        case 'B':   // Нахождение наибольшего отрицательного элемента массива.
            fillVect(myVect, ax, bx);
            outputArray(myVect);
            cout<<"Индекс наибольшего отрицательного элемента: "<<maxNegative(myVect)<<endl;
            break;
        case 'C':   // Нахождение наибольшего элемента массива.
            fillVect(myVect, ax, bx);
            outputArray(myVect);
            cout<<"Индекс наибольшего элемента: "<<maxElement(myVect)<<endl;
            break;
        case 'D':   // Нахождение двух наибольших значений
            fillVect(myVect, ax, bx);
            cout<<"До нахождения"<<endl;
            outputArray(myVect);
            twoBiggest(myVect);
            cout<<"После нахождения"<<endl;
            outputArray(myVect);
            break;
        case 'E':   // Нахождение двух наибольших значений
            fillVect(myVect, ax, bx);
            fillZero(myNegVect);
            cout<<"До формирования"<<endl;
            outputArray(myVect);
            outputArray(myNegVect);
            cout<<"Отрицательных элементов: "<<negativeCount(myVect, myNegVect)<<endl;
            cout<<"После нахождения"<<endl;
            outputArray(myVect);
            outputArray(myNegVect);
            break;
        case 'F':
            fillVect(myVect, ax, bx);
            cout<<"Содержимое массива"<<endl;
            outputArray(myVect);
            cout<<"Смен знаков:"<<countChange(myVect)<<"\n";
            break;
        case 'G':
            fillVect(myVect, ax, bx);
            cout<<"Содержимое массива до инверсии"<<endl;
            outputArray(myVect);
            cout<<"Содержимое массива после инверсии"<<endl;
            inverse(myVect);
            outputArray(myVect);
            break;
        case 'H':
            fillVect(myVect, ax, bx);
            cout<<"Содержимое массива до сдвига отрицательных элементов"<<endl;
            outputArray(myVect);
            cout<<"Содержимое массива после сдвига отрицательных элементов"<<endl;
            moveNegItem(myVect);
            outputArray(myVect);
            break;
        default:
            break;
        }
    }

    return 0;
}
