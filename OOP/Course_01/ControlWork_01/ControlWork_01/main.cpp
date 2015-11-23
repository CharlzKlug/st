#include "controlwork_01.h"
const int N = 3;    // Количество элементов в массиве.

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qreal someArray[N];
    string menuOptions[] =
    {
        "A - Номер максимального по модулю элемента массива",
        "B - Сумма элементов массива, расположенных после первого положительного элемента",
        "C - Преобразовать массив: в начале элементы целая часть лежит в интервале [a, b], потом остальные",
        "X - Выход из программы"
    };
    char hotKeys[] = {'A', 'B', 'C', 'X', '\0'};
    char selectedMenu;
    while ((selectedMenu = selectMenu(menuOptions, hotKeys)) != 'X')
    {
        cout << selectedMenu << endl;
        switch (selectedMenu)
        {
        case 'A':
            loadRandomCoefs(someArray, N);
            printArray(someArray, N);
            cout << "Номер максимального элемента " << indexMaxABS(someArray, N) << endl;
            break;
        case 'B':
            loadRandomCoefs(someArray, N);
            printArray(someArray, N);
            cout << "Сумма элементов массива после первого положительного элемента: " << sumAfterFirstPos(someArray, N) << endl;
            break;
        case 'C':
        {
            cout << "Введите a = ";
            qreal ac;
            cin >> ac;
            cout << "Введите b = ";
            qreal bc;
            cin >> bc;
            loadRandomCoefs(someArray, N);
            cout << "До сортировки" << endl;
            printArray(someArray, N);
            cout << "После сортировки" << endl;
            sortCaprice(someArray, N, ac, bc);
            printArray(someArray, N);
            break;
        }
        default:
            break;
        }
    }
    return 0;
}
