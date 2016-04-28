#include <QCoreApplication>
#include <tvect.h>
#include <menu.h>
#include <string>
#include <ctime>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    TVect* v1 = new TVect();
    //v1->outputToScreen();
    //delete v1;
    TVect* v2 = new TVect();
    Mytype a1[]={1, 2, 3, 4}, a2[]={5, 6, 7};
    qreal lb=-10, hb=10;
    srand(std::time(0));
    std::string bb[] = {"A - задать значения по-умолчанию",
                        "B - инициализация через массив",
                        "C - конструктор с копированием",
                        "D - сохранить в файл",
                        "E - чтение из файла",
                        "F - вывод на экран",
                        "G - добавление в массив нового элемента",
                        "H - удаление элемента массива",
                        "I - сложение двух векторов",
                        "J - вычитание двух векторов",
                        "K - умножение с присваиванием",
                        "L - операция присваивания",
                        "M - доступ по индексу",
                        "N - умножение на число",
                        "O - модуль вектора",
                        "P - длина вектора",
                        "Q - установить длину вектора",
                        "R - установить отдельный элемент",
                        "S - установить отдельный элемент",
                        "T - сгенерировать случайные значения (друг)",
                        "X - Выход из программы"};
    Menu myMenu(21, bb);
    char selectedItem;
    while ((selectedItem = myMenu.getKey()) != 'X') {
        switch (selectedItem) {
        case 'A':
            delete v1;
            v1 = new TVect();
            std::cout<<"v1:"<<std::endl;
            v1->outputToScreen();
            delete v2;
            v2 = new TVect();
            std::cout<<"v2:"<<std::endl;
            v2->outputToScreen();
            break;
        case 'B':
            delete v1;
            v1 = new TVect(4, a1);
            std::cout<<"v1:"<<std::endl;
            v1->outputToScreen();
            delete v2;
            v2 = new TVect(3, a2);
            std::cout<<"v2:"<<std::endl;
            v2->outputToScreen();
            break;
        case 'C':
            delete v1;
            v1 = new TVect(*v2);
            std::cout<<"v1:"<<std::endl;
            v1->outputToScreen();
            std::cout<<"v2:"<<std::endl;
            v2->outputToScreen();
            break;
        case 'D':
        {
            std::cout<<"Введите название файла: ";
            std::string userFileName;
            std::cin>>userFileName;
            if (v1->saveToFile(userFileName)){
                std::cout<<"Запись прошла успешно."<<std::endl;
            } else {
                std::cout<<"Запись завершилась с ошибкой."<<std::endl;
            }
        }
            break;
        case 'E':
        {
            std::cout<<"Введите название файла: ";
            std::string userFileName;
            std::cin>>userFileName;
            if (v1->loadFromFile(userFileName)){
                std::cout<<"Чтение прошло успешно."<<std::endl;
            } else {
                std::cout<<"Чтение завершилось с ошибкой."<<std::endl;
            }
            std::cout<<"v1:"<<std::endl;
            v1->outputToScreen();
            std::cout<<"v2:"<<std::endl;
            v2->outputToScreen();
        }
            break;
        case 'F':
            std::cout<<"v1:"<<std::endl;
            v1->outputToScreen();
            std::cout<<"v2:"<<std::endl;
            v2->outputToScreen();
            break;
        case 'G':
        {
            std::cout<<"Введите новый элемент: ";
            qreal temp;
            std::cin>>temp;
            v1->addElement(temp);
            std::cout<<"v1:"<<std::endl;
            v1->outputToScreen();
            std::cout<<"v2:"<<std::endl;
            v2->outputToScreen();
        }
            break;
        case 'H':
        {
            std::cout<<"Введите индекс удаляемого элемента: ";
            int index;
            std::cin>>index;
            v1->removeElement(index);
            std::cout<<"v1:"<<std::endl;
            v1->outputToScreen();
            std::cout<<"v2:"<<std::endl;
            v2->outputToScreen();
        }
            break;
        case 'I':
            (*v1+*v2).outputToScreen();
            break;
        case 'J':
            (*v1-*v2).outputToScreen();
            break;
        case 'K':
           *v1*=*v2;
            std::cout<<"v1:"<<std::endl;
            v1->outputToScreen();
            std::cout<<"v2:"<<std::endl;
            v2->outputToScreen();
            break;
        case 'L':
            *v1=*v2;
            std::cout<<"v1:"<<std::endl;
            v1->outputToScreen();
            std::cout<<"v2:"<<std::endl;
            v2->outputToScreen();
            break;
        case 'M':
            int index;
            std::cout<<"Введите индекс: ";
            std::cin>>index;
            std::cout<<"Значение по индексу: ";
            std::cout<<(*v1)[index]<<std::endl;
            break;
        case 'N':
        {
            Mytype myNumber;
            std::cout<<"Введите число: ";
            std::cin>>myNumber;
            std::cout<<"v1:"<<std::endl;
            v1->outputToScreen();
            std::cout<<"После умножения: "<<std::endl;
            (*v1*myNumber).outputToScreen();
        }
            break;
        case 'O':
            std::cout<<"Модуль вектора: "<<(*v1).module()<<std::endl;
            break;
        case 'P':
            std::cout<<v1->getLength()<<std::endl;
            break;
        case 'Q':
        {
            std::cout<<"До смены длины: "<<std::endl;
            v1->outputToScreen();
            int someLength;
            std::cout<<"Введите новую длину: ";
            std::cin>>someLength;
            v1->setLength(someLength);
            std::cout<<"После смены длины: "<<std::endl;
            v1->outputToScreen();
        }
            break;
        case 'R':
        {
            int index;
            Mytype someVal;
            std::cout<<"До смены элемента: "<<std::endl;
            v1->outputToScreen();
            std::cout<<"Введите индекс: ";
            std::cin>>index;
            std::cout<<"Введите значение: ";
            std::cin>>someVal;
            if (v1->setElement(index, someVal)){
                std::cout<<"Смена прошла удачно"<<std::endl;
            } else {
                std::cout<<"Смена прошла неудачно"<<std::endl;
            }
            std::cout<<"После смены элемента: "<<std::endl;
            v1->outputToScreen();

        }
            break;
        case 'T':
            setRandom(*v1, lb, hb);
            v1->outputToScreen();
            break;
        default:
            break;
        }
    }

    return 0;
}
