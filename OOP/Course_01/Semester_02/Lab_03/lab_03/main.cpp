#include <QCoreApplication>
//#include "tvector.h"
#include "tvectsolve.h"
#include "menu.h"
#include <string>

//#include <iostream>
//#include <iomanip>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    T sampleArray[]={1, 2, 3, -5.67, 10, 12.5};
    TVectSolve * sampleVectorSolve = new TVectSolve(6, sampleArray);
    TVectSolve * myVectorSolve = new TVectSolve();
    std::cout<<"Стандартный вектор:"<<std::endl;
    sampleVectorSolve->printVector();
    std::cout<<"Рабочий вектор:"<<std::endl;
    myVectorSolve->printVector();
    std::string bb[] = {"A - задать значения по-умолчанию",
                        "B - инициализация через массив",
                        "C - конструктор с копированием",
                        "D - сортировка выбором",
                        "E - сортировка пузырьком",
                        "F - сортировка вставкой",
                        "G - перестановка элементов",
                        "H - инвертирование элементов массива",
                        "I - наибольший элемент массива",
                        "J - среднее арифметическое значение элементов вектора",
                        "K - среднее геометрическое положительных элементов",
                        "X - Выход из программы"};
    Menu myMenu(12, bb);
    char selectedItem;
    while ((selectedItem = myMenu.getKey()) != 'X') {
        switch (selectedItem) {
        case 'A':
            delete myVectorSolve;
            myVectorSolve = new TVectSolve();
            myVectorSolve->printVector();
            break;
        case 'B':
            delete myVectorSolve;
            myVectorSolve = new TVectSolve(6, sampleArray);
            myVectorSolve->printVector();
            break;
        case 'C':
            delete myVectorSolve;
            myVectorSolve = new TVectSolve();
            myVectorSolve->copyVectSolve(sampleVectorSolve);
            myVectorSolve->printVector();
            break;
        case 'D':
            myVectorSolve->chooseSort(0);
            myVectorSolve->printVector();
            break;
        case 'E':
            myVectorSolve->chooseSort(1);
            myVectorSolve->printVector();
            break;
        case 'F':
            myVectorSolve->chooseSort(2);
            myVectorSolve->printVector();
            break;
        case 'G':
            int i;
            std::cout<<"Введите индекс элемента №1: ";
            std::cin>>i;
            int j;
            std::cout<<"Введите индекс элемента №2: ";
            std::cin>>j;
            myVectorSolve->swapItems(i, j);
            myVectorSolve->printVector();
            break;
        case 'H':
            myVectorSolve->inverseItems();
            myVectorSolve->printVector();
            break;
        case 'I':
        {
            myVectorSolve->printVector();
            int maxInd=myVectorSolve->maxItemIndex();
            std::cout<<"Индекс максимального элемента: "<<maxInd<<std::endl;
            std::cout<<"Значение максимального элемента: "<<myVectorSolve->getItem(maxInd)<<std::endl;
        }
            break;
        case 'J':
            myVectorSolve->printVector();
            std::cout<<"Среднее арифметическое равно "<<myVectorSolve->midAr()<<
                       std::endl;
            break;
        case 'K':
            myVectorSolve->printVector();
            std::cout<<"Среднее геометрическое положительных чисел: "<<myVectorSolve->averGeom()<<
                       std::endl;
            break;

        default:
            break;
        }}





    //myVectorSolve.printVector();
    //myVectorSolve.setSize(20);
//    TVector myVector;
//    myVector.printVector();
    //myVectorSolve.copyVectSolve(sampleVectorSolve);
    //myVectorSolve.printVector();
    //myVectorSolve.selectionSort();
//    myVectorSolve.chooseSort(0);
//    myVectorSolve.printVector();
//    myVectorSolve.chooseSort(1);
//    myVectorSolve.printVector();
//    myVectorSolve.chooseSort(2);
//    myVectorSolve.printVector();
//    myVectorSolve.inverseItems();
//    myVectorSolve.printVector();
//    std::cout<<myVectorSolve.maxItemIndex()<<std::endl<<myVectorSolve.getItem(myVectorSolve.maxItemIndex())<<std::endl;
//    std::cout<<myVectorSolve.midAr()<<std::endl;
//    myVectorSolve=sampleVectorSolve;
//    myVectorSolve.printVector();
    return 0;
}
