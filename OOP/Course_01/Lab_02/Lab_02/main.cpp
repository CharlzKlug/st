#include "polynom.h"
#include <iomanip>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    TCoef myCoefs = {-2, -1.5, -0.9, 0, 1, 2, 3, -1.8, 3, 3.5, 4};

    int order = 10;  // Степень полинома.

    qreal ax = -5, bx = 5, step = 0.5; // ax - начальная граница, bx - конечная граница, step - шаг приращения.

    char selectedMenu;

    while ((selectedMenu = menu()) != 'X')
    {
        switch (selectedMenu) {
        case 'A':   // Вывод начальных значений
            cout<<"Степень полинома: "<<order<<endl;
            cout<<"ax = "<<ax<<" bx = "<<bx<<" step = "<<step<<endl;
            outputCoefs(myCoefs, order);
            break;
        case 'B':   // Ввод параметров табулирования
            cout<<"ax = ";
            cin>>ax;
            cout<<"bx = ";
            cin>>bx;
            cout<<"step = ";
            cin>>step;
            break;

        default:
            break;
        }
    }
    return 0;
}
