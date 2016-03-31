#include <QCoreApplication>
#include "fraction.h"
#include "menu.h"
#include <iostream>
#include <string>
#include <ctime>
using namespace std;

int randomInt(int a, int b){
    return (int)((((qreal)rand())/RAND_MAX)*(b-a))+a;
}

void printFraction(Fraction& anyFrac, string header){
    cout << header << anyFrac.getNumerator() << "/" << anyFrac.getDenominator() << endl;
}

void setFVal (Fraction& anyFrac, int lb, int lh){
    int denom;
    while ((denom = randomInt(lb, lh)) == 0){}
    anyFrac.setValue(randomInt(lb, lh), denom);
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    srand(time(0));
    int lb = -5; // Нижняя граница
    int hb = 5; // Верхняя граница
    Fraction fa (1, 2);
    Fraction fb (-1, 4);
    Fraction fc (1, 1);
    string bb[] = {"A - задать дроби a, b и c с помощью ДСЧ",
                   "B - напечатать значения a, b и c",
                   "C - Результат a += b",
                   "D - Результат a -= b",
                   "E - Результат a *= b",
                   "F - Результат a /= b",
                  "G - Результат a = b + c",
                  "H - Результат a = b - c",
                  "I - Результат a = b * c",
                  "J - Результат a = b / c",
                  "K - Результат a = b ^ [целое число]",
                  "L - Результат a = b ^ [вещественное число]",
                  "X - Выход из программы"};
    Menu myMenu(13, bb);
    char selectedItem;
    while ((selectedItem = myMenu.getKey()) != 'X') {
        switch (selectedItem) {
        case 'A':
            setFVal(fa, lb, hb);
            setFVal(fb, lb, hb);
            setFVal(fc, lb, hb);
            break;
        case 'B':
            printFraction(fa, "a = ");
            printFraction(fb, "b = ");
            printFraction(fc, "c = ");
            break;
        case 'C':
            fa += fb;
            printFraction(fa, "a = ");
            break;
        case 'D':
            fa -= fb;
            printFraction(fa, "a = ");
            break;
        case 'E':
            fa *= fb;
            printFraction(fa, "a = ");
            break;
        case 'F':
            fa /= fb;
            printFraction(fa, "a = ");
            break;
        case 'G':
            fa = fb + fc;
            printFraction(fa, "a = ");
            break;
        case 'H':
            fa = fb - fc;
            printFraction(fa, "a = ");
            break;
        case 'I':
            fa = fb * fc;
            printFraction(fa, "a = ");
            break;
        case 'J':
            fa = fb / fc;
            printFraction(fa, "a = ");
            break;
        case 'K':
        {
            int n;
            cout << "Введите целое число: ";
            cin >> n;
            fa = fb ^ n;
            printFraction(fa, "a = ");
        }
            break;
        case 'L':
        {
            double m;
            cout << "Введите вещественное число: ";
            cin >> m;
            fa = fb ^ m;
            printFraction(fa, "a = ");
        }
            break;

        default:
            break;
        }
    }

    return 0;
}
