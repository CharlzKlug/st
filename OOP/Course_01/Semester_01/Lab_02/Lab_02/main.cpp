#include "polynom.h"
#include <iomanip>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    TCoef myCoefs = {1, 1, -1, 0, 1, 2, 3, -1.8, 3, 3.5, 4};

    int order = 2;  // Степень полинома.

    qreal ax = -2, bx = 4; // ax - начальная граница, bx - конечная граница.

    int dotCount = 5;   // Количество точек на прямой.

    TVect *polyValue = new qreal [dotCount + 2];

    //    TPoly myPoly;   // Массив с результатами полинома.

    //TDPoly myDPoly; // Массив с результатами производной полинома.

    TVect *polyDValue = new qreal [dotCount + 2];    // Массив, содержащий значения полинома.

    string fileName = "/home/ametovii/Temp/1.txt";    // Название файла из которого будет считываться коэффициенты

    char selectedMenu;

    while ((selectedMenu = menu()) != 'X')
    {
        switch (selectedMenu) {
        case 'A':   // Вывод начальных значений
            cout<<"Степень полинома: "<<order<<endl;
            cout<<"ax = "<<ax<<" bx = "<<bx<<" dots = "<<dotCount<<endl;
            //            cout<<"Коэффициенты: ";
            outputCoefs(myCoefs, order);
            cout<<"Имя файла с коэффициентами: "<<fileName<<endl;
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
            polyValue = new qreal [dotCount + 2];
            delete [] polyDValue;
            polyDValue = new qreal [dotCount + 2];
            cout<<"Имя файла с коэффициентами: ";
            cin>>fileName;
            break;

        case 'C':   // Загрузка коэффициентов с клавиатуры
            cout<<"Загрузка новых коэффициентов с клавиатуры"<<endl;
            loadCoefKeyboard(myCoefs, order);
            break;
        case 'D':   // Генерация случайных коэффициентов
            cout<<"Генерация случайных коэффициентов"<<endl;
            loadRandomCoefs(myCoefs, order);
            cout<<"Получившиеся коэффициенты:"<<endl;
            outputCoefs(myCoefs, order);
            break;
        case 'E':   // Ввод коэффициентов с файла
            cout<<"Считывание коэффициентов из файла"<<endl;
            //cout<<fileName.length();
            //std::string str = "string";
        {
            char *cstr = new char[fileName.length() + 1];
            strcpy(cstr, fileName.c_str());
            // do stuff
            loadCoefsFile(myCoefs, order, cstr);
            delete [] cstr;

        }
            //loadCoefsFile(myCoefs, order, cstr);
            //delete [] cstr;
            cout<<"Получившиеся коэффициенты:"<<endl;
            outputCoefs(myCoefs, order);

            break;
        case 'F':   // Вычисление значений полинома на некотором отрезке, занесение их в массив и вывод значений массива на экран
            cout<<"Вычисление значений полинома на некотором отрезке, занесение их в массив и вывод значений массива на экран"<<endl;
            calculateEdgePoly(myCoefs, order, polyValue, polyDValue, ax, bx, dotCount);
            break;
        case 'G':   // Упорядочение массива значений полинома методом выбора
            cout<< "До упорядочения:"<<endl;
            outputCoefs(polyValue, dotCount + 1);
            cout<< "После упорядочения:"<<endl;
            selectionSort(polyValue, dotCount + 2);
            outputCoefs(polyValue, dotCount + 1);
            break;
        case 'H':
            cout<< "До упорядочения:"<<endl;
            outputCoefs(polyValue, dotCount + 1);
            cout<< "После упорядочения:"<<endl;
            bubbleSort(polyValue, dotCount + 2);
            outputCoefs(polyValue, dotCount + 1);
            break;
        case 'K':
            cout<< "До упорядочения:"<<endl;
            outputCoefs(polyValue, dotCount + 1);
            cout<< "После упорядочения:"<<endl;
            insertionSort(polyValue, dotCount + 2);
            outputCoefs(polyValue, dotCount + 1);
            break;
        case 'L':
            cout<< "До инвертирования:"<<endl;
            outputCoefs(polyValue, dotCount + 1);
            cout<< "После инвертирования:"<<endl;
            inverseArray(polyValue, dotCount + 2);
            outputCoefs(polyValue, dotCount + 1);
            break;
        default:
            break;
        }
    }
    delete [] polyValue;    // Очищаем место массива значений полинома
    delete [] polyDValue;   // Очищаем место массива значений полинома

    return 0;
}
