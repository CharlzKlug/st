#include "lesson_10.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qreal ax = -5, bx = 5;
    TVect b;
    TVect testVector = {-10, -9, -8, -7, -6, -5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5, 6, 7, 9};
    char *itemMenu[] =
    {
        "A - Загрузить тестовый вектор",
        "B - Загрузить вектор с помощью генератора случайных чисел",
        "C - Сортировать вектор с помощью метода выбора",
        "D - Сортировать вектор с помощью метода пузырька",
        "E - Сортировать вектор с помощью метода вставки",
        "F - Сохранить вектор в файле",
        "G - Считать вектор из файла",
        "X - Выйти из программы"
    };
    char *hotKeys = "ABCDEFG";
    char selectedBranch;
    initRandom();
    while (true)
    {
        selectedBranch = menu(itemMenu, hotKeys);
        switch (selectedBranch) {
        case 'A':
            cout << "Загрузка тестового вектора" << endl;
            loadTestVector(b, testVector);
            printArray(b);
            break;
        case 'B':
            cout << "Загрузка вектора с помощью генератора случайных чисел" << endl;
            fillArrayRand(b, ax, bx);
            printArray(b);
            break;
        case 'C':
            cout << "Сортировать вектор с помощью метода выбора" << endl;
            cout << "Вектор до сортировки" << endl;
            printArray(b);
            selectionSort(b);
            cout << "Вектор после сортировки" << endl;
            printArray(b);
            break;
        case 'D':
            cout << "Сортировать вектор с помощью метода пузырька" << endl;
            cout << "Вектор до сортировки" << endl;
            printArray(b);
            bubbleSort(b);
            cout << "Вектор после сортировки" << endl;
            printArray(b);

            break;
        case 'E':
            cout << "Сортировать вектор с помощью метода вставки" << endl;
            cout << "Вектор до сортировки" << endl;
            printArray(b);
            insertionSort(b, N);
            cout << "Вектор после сортировки" << endl;
            printArray(b);
            break;
        case 'F':
            cout << "Сохранить вектор в файле" << endl;
            cout << "Введите имя файла:";
        {
            string fileName = "";
            cin >> fileName;
            char *cstr = new char[fileName.length() + 1];
            strcpy(cstr, fileName.c_str());
            if (writeVectFile(cstr, b))
            {
                cout << "Вектор сохранён в файле"<< "\n";
            }
            else
            {
                cout << "При сохранении произошла ошибка\n";
            }
            delete [] cstr;
        }
            break;
        case 'G':
            cout << "Считать вектор из файла" << endl;
            cout << "Введите имя файла:";
        {
            string fileName = "";
            cin >> fileName;
            if (readVectFile(fileName,b))
            {
                cout << "Вектор прочитан из файла"<< "\n";
            }
            else
            {
                cout << "При считывании произошла ошибка\n";
            }
        }

            break;
        default:
            break;
        }
    }
    initRandom();
    fillArrayRand(b, ax, bx);
    printArray(b);
    //selectionSort(b);
    bubbleSort(b);
    cout<<"After selection sorting"<<endl;
    printArray(b);
    cout<<"Insertion sorting"<<endl;
    fillArrayRand(b, ax, bx);
    cout<<"Before:"<<endl;
    printArray(b);
    cout<<"After:"<<endl;
    insertionSort(b, N);
    printArray(b);
    writeVectFile("/home/ametovii/Temp/vect.txt", b);
    return 0;
}
