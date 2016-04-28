#ifndef MENU_H
#define MENU_H
#include <string>
#include <iostream>

class Menu {
private:
    int n; // количество элементов меню
    std :: string* messages; // массив сообщений
public:
    Menu(const int&, std::string*);
    std :: string getN(int);
    void printMessages();
    char getKey();
};

#endif // MENU_H
