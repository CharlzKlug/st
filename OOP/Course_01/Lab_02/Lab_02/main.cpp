#include "polynom.h"
#include <iomanip>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    TCoef myCoefs = {-2, -1.5, -0.9, 0, 1, 2, 3, -1.8, 3, 3.5, 4};

    int order = 10;  // Степень полинома.

    qreal ax = -5, bx = 5; // ax - начальная граница, bx - конечная граница.

    int dotCount = 3;   // Количество точек на прямой.

    TVect *polyValue = new qreal [dotCount];

//    TPoly myPoly;   // Массив с результатами полинома.

    TDPoly myDPoly; // Массив с результатами производной полинома.

    char selectedMenu;

    while ((selectedMenu = menu()) != 'X')
    {
        switch (selectedMenu) {
        case 'A':   // Вывод начальных значений
            cout<<"Степень полинома: "<<order<<endl;
            cout<<"ax = "<<ax<<" bx = "<<bx<<" dots = "<<dotCount<<endl;
    //            cout<<"Коэффициенты: ";
            outputCoefs(myCoefs, order);
            break;
        case 'B':   // Ввод параметров табулирования
            cout<<"Степень полинома: ";
            cin>>order;
            cout<<"ax = ";
            cin>>ax;
            cout<<"bx = ";
            cin>>bx;
            cout<<"dots = ";
            cin>>dotCount;
            delete [] polyValue;
            polyValue = new qreal [dotCount];
            break;

        case 'C':   // Загрузка коэффициентов с клавиатуры
            cout<<"Загрузка новых коэффициентов с клавиатуры"<<endl;
            loadCoefKeyboard(myCoefs, order);
            break;
        default:
            break;
        }
    }
    delete [] polyValue;
    return 0;
}
