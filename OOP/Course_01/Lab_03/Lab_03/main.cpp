#include "lab_03.h"
const int ITEMSCOUNT = 13, ROWMAX = 9, COLUMNMAX = 9;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    string mainMenu [ITEMSCOUNT];
    int currentRowMax = ROWMAX - 6, currentColumnMax = COLUMNMAX - 6, lb = -9, hb = 9;
    qreal originMatrix[ROWMAX][COLUMNMAX];
    qreal workMatrix[ROWMAX][COLUMNMAX];
    qreal testMatrix[][9] =
    {
        {6, 5, 7, -1, -3, 0, -1, 8, 2},
        {-5, -7, -5, -5, -5, 8, 0, 2, 2},
        {0, -2, 0, 0, -2, 5, -6, 0, -4},
        {7, -6, 0, -3, 7, -3, -1, 0, 0},
        {0, 7, -2, 2, 3, 0, 5, -3, -1},
        {8, 2, 0, 0, 3, 0, 8, -5, 2},
        {2, 5, 0, -4, 1, -4, -6, 0, 8},
        {3, 4, -2, 1, -5, -5, -5, -6, -7},
        {-4, 5, 2, 2, -6, 0, -6, 0, 1}
    };
    srand(time(0) * 1023);
    string matrixFile = "myMatrix.txt";
    menuFromFile("menu.txt", mainMenu, ITEMSCOUNT);

    char selectedItem;  // Выбранный вариант
    while ((selectedItem = menu(mainMenu, ITEMSCOUNT)) != 'X')
    {
        switch (selectedItem) {
        case 'A':   // Смена размерности
            changeDimensions(currentRowMax, currentColumnMax);
            break;
        case 'B':   // Заполнение случайными числами
            fillMatrixRandom(originMatrix[0], currentRowMax, currentColumnMax, lb, hb);
            printMatrix(originMatrix[0], currentRowMax, currentColumnMax);
            break;
        case 'C':   // Загрузка тестовой матрицы
            copyMatrix(originMatrix[0], testMatrix[0], currentRowMax , currentColumnMax, COLUMNMAX);
            printMatrix(originMatrix[0], currentRowMax , currentColumnMax);
            break;
        case 'D':   // Ввод данных матрицы с клавиатуры
            loadMatrixKeyboard (originMatrix[0], currentRowMax, currentColumnMax);
            printMatrix(originMatrix[0], currentRowMax , currentColumnMax);
            break;
        case 'E':   // Сохранение данных в файл
            if (saveMatrix (matrixFile,
                            originMatrix[0],
                            currentRowMax,
                            currentColumnMax)) cout << "Данные сохранены в файл " << matrixFile << endl;
            else
                cout << "Возникла ошибка при сохранении данных!" << endl;
            break;
        case 'F':   // Загрузка матричных данных из файла
            if (!loadMatrixFile(matrixFile, originMatrix[0], currentRowMax, currentColumnMax))
                cout << "Ошибка при чтении данных" << endl;
            else
            {
                cout << "Данные успешно загружены" << endl;
                printMatrix(originMatrix[0], currentRowMax , currentColumnMax);
            }
            break;
        case 'G':   // Вывод матрицы на экран
            printMatrix(originMatrix[0], currentRowMax , currentColumnMax);
            break;
        case 'H':   // Вычисление норм матрицы
            cout << "Наибольшая сумма модулей элементов строк: "
                 << rowMaxNorm (originMatrix[0], currentRowMax, currentColumnMax) << endl;
            cout << "Наибольшая сумма модулей элементов столбцов: "
                 << columnMaxNorm (originMatrix[0], currentRowMax, currentColumnMax) << endl;
            cout << "Корень квадратный суммы квадратов элементов матрицы: "
                 << sumSqrt(originMatrix[0], currentRowMax, currentColumnMax) << endl;
            break;
        case 'I':   // Наибольший и наименьший элементы матрицы
        {
            int minR, minC;
            minR = minME(originMatrix[0], currentRowMax, currentColumnMax, minC);
            cout << "Наименьший элемент массива [" << minR << "][" << minC << "]: "
                 << getME(originMatrix[0], minR, minC, currentColumnMax)   << endl;
            int maxR, maxC;
            maxR = maxME (originMatrix[0], currentRowMax, currentColumnMax, maxC);
            cout << "Наибольший элемент массива [" << maxR << "][" << maxC << "]: "
                 << getME(originMatrix[0], maxR, maxC, currentColumnMax)   << endl;
            break;
        }
        case 'K':   // Перестановка строк с наибольшим и наименьшим элементами матрицы
        {
            int minR, minC;
            int maxR, maxC;
            linearCopyMatrix(workMatrix[0], originMatrix[0], currentRowMax , currentColumnMax);
            minR = minME(workMatrix[0], currentRowMax, currentColumnMax, minC);
            maxR = maxME (workMatrix[0], currentRowMax, currentColumnMax, maxC);
            cout << "До перестановки" << endl;
            printMatrix(workMatrix[0], currentRowMax , currentColumnMax);
            replaceRow (workMatrix[0], minR, currentColumnMax);
            replaceRow (workMatrix[0], maxR, currentColumnMax);
            cout << "После перестановки" << endl;
            printMatrix(workMatrix[0], currentRowMax , currentColumnMax);
            break;
        }
        case 'L':   // Сортировка строк по некоторому столбцу
        {
            linearCopyMatrix(workMatrix[0], originMatrix[0], currentRowMax , currentColumnMax);
            int columnNumber;
            cout << "Введите номер столбца: ";
            cin >> columnNumber;
            bool descendingP;
            cout << "Выберите метод сортировки [1 - по-убыванию, 0 - по-возрастанию]: ";
            cin >> descendingP;
            cout << "До упорядочивания" << endl;
            printMatrix(workMatrix[0], currentRowMax , currentColumnMax);
            sortMatrixByColumn(workMatrix[0], currentRowMax , currentColumnMax, columnNumber, descendingP);
            cout << "После упорядочивания" << endl;
            printMatrix(workMatrix[0], currentRowMax , currentColumnMax);
            break;
        }
        case 'M':   // Инвертирование строк матрицы
            linearCopyMatrix(workMatrix[0], originMatrix[0], currentRowMax , currentColumnMax);
            cout << "До инвертирования строк" << endl;
            printMatrix(workMatrix[0], currentRowMax , currentColumnMax);
            inverseMatrixRows (workMatrix[0], currentRowMax , currentColumnMax);
            cout << "После инвертирования" << endl;
            printMatrix(workMatrix[0], currentRowMax , currentColumnMax);
            break;
        default:
            break;
        }
    }
    return 0;
}
