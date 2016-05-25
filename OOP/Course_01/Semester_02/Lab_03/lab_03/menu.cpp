#include "menu.h"

Menu :: Menu(const int & a, std::string * items){
    n = a;
    messages = items;
}

std :: string Menu:: getN(int k){
    return messages[k];
}

void Menu :: printMessages(){
    for (int i = 0; i < n; ++i){
        std :: cout << messages[i] << std::endl;
    }
}

char Menu::getKey(){
    printMessages();
    char pressedKey;
    std::cin >> pressedKey;
    return toupper(pressedKey);
}
