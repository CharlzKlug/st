#include "lesson_11.h"

const int NMAX = 30;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    srand(1249 * time(0));
    qreal ac = -5, bc = 5;
    qreal test[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 11 + 2};
    int ntest = sizeof(test) / sizeof(qreal);
    int n, m;
    qreal sum = 0;
    string itemMenu[] =
    {
        "A - Загрузка тестового вектора",
        "B - Загрузка вектора с помощью генератора случайных чисел",
        "C - Сумма элементов больших нуля после первого отрицательного элемента",
        "D - сумма элементов после последнего положительного",
        "E - Сумма элементов между наибольшим и наименьшим значениями",
        "F - Сумма элементов между первыми двумя отрицательными элементами",
        "G - Сформировать вектор из положительных элементов",
        "H - Сформировать вектор из элементов с чётными индексами"
    };
    char *hot = "ABCDEFGH";
    qreal *pvect = new qreal [NMAX];
    qreal *pwork = new qreal [NMAX];
    while (true)
    {
        char code = menu (itemMenu, hot);
        switch (code) {
        case 'A':
            n = ntest;
            copyVector(pvect, test, n);
            showVector(pvect, n);
            break;
        case 'B':
            cout << "Количество элементов массива (не больше 30): ";
            cin >> n;
            inputVectRnd(pvect, ac, bc, n);
            showVector(pvect, n);
            break;
        case 'C':
            sum = sumItemAfterFirstMinus(pvect, n);
            cout << "sum = " << sum << endl;
            break;
        case 'D':
            sum = sumItemAfterLastPlus(pvect, n);
            cout << "sum = " << sum << endl;
            break;
        case 'E':
        {
            int imin = 0, imax = 0;
            //sum = sumItemBetweenMinMax(pvect, n, imin, imax);
            cout << "minV = " << pvect[imin] << " maxV = " << pvect[imax] << endl;
        }
            cout << "sum = " << sum << endl;
            break;
        case 'F':
        {
            int i1, i2;
            sum = sumItemBetweenMinus(pvect, n, &i1, &i2);
            cout << "i1 = " << i1 << " i2 = " << i2 << endl;
        }
            cout << "sum = " << sum << endl;
            break;
        case 'G':
            copyVector(pwork, pvect, n);
            m = n;
            createPositiveItem(pwork, &m);
            showVector(pwork, m);
            break;
        case 'X':
            delete [] pvect;
            delete [] pwork;
            exit(0);
            break;
        default:
            break;
        }
    }
    return 0;
}
