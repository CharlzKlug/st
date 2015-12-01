#include "matrixOperation.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    srand(time(0)*1111);
    string itemMenu[] =
    {
        "A - Загрузка тестовй матрицы",
        "B - Использовать ДСЧ",
        "C - Сложить с транспонированной матрицей",
        "D - Вычесть транспонированную матрицу",
        "E - Умножить на транспонированную матрицу",
        "F - Сформировать вектор из наибольших модулей строк",
        "G - Сформировать вектор из наибольших модулей столбцов",
        "H - Вычислить сумму элементов диагоналей",
        "X - Выход из программы"
    };  // Меню программы
    int menuTotal = 9;   // Горячие клавиши
    int ac = -5, bc = 5;
    qreal test[RMAX][CMAX] = {{1, 2, 3, 4, 5, 6, 7, 9}, {-1, -2, -3, -4, -5, -6, -7, -9}};
    TMatr originalMatrix, workMatrix, thirdMatrix;
    TVect myVect;
    char selectedItem;  // Выбранный элемент меню
    while ((selectedItem = selectMenu(itemMenu, menuTotal)) != 'X')
    {
        switch (selectedItem) {
        case 'A':
            loadMatrix(originalMatrix, test, RMAX, CMAX);
            printMatrix(originalMatrix, RMAX, CMAX);
            break;
        case 'B':
            loadRandomMatrix(originalMatrix, RMAX, CMAX, ac, bc);
            printMatrix(originalMatrix, RMAX, CMAX);
            break;
        case 'C':
            loadMatrix(workMatrix, originalMatrix, RMAX, CMAX);
            transposeMatrix(workMatrix, RMAX, CMAX);
            sumMatrix(originalMatrix, workMatrix, RMAX, CMAX);
            printMatrix(originalMatrix, RMAX, CMAX);
            break;
        case 'D':
            loadMatrix(workMatrix, originalMatrix, RMAX, CMAX);
            transposeMatrix(workMatrix, RMAX, CMAX);
            subMatrix(originalMatrix, workMatrix, RMAX, CMAX);
            printMatrix(originalMatrix, RMAX, CMAX);
            break;
        case 'E':
            loadMatrix(workMatrix, originalMatrix, RMAX, CMAX);
            transposeMatrix(workMatrix, RMAX, CMAX);
            printMatrix(workMatrix, RMAX, CMAX);
            mulMatrix(originalMatrix, workMatrix, thirdMatrix, RMAX, CMAX);
            printMatrix(thirdMatrix, RMAX, CMAX);
            break;
        case 'F':
            makeVectMaxModRow(myVect, originalMatrix, RMAX, CMAX);
            printVect(myVect, RMAX, true);
            break;
        case 'G':
            makeVectMaxModCol(myVect, originalMatrix, RMAX, CMAX);
            printVect(myVect, RMAX, false);
            cout << endl;
            break;
        case 'H':
            for (int i = - (RMAX - 1); i < RMAX; i++)
            cout << diagSum(originalMatrix, RMAX, CMAX, i) << endl;
            break;

        default:
            break;
        }
    }
    return 0;
}
