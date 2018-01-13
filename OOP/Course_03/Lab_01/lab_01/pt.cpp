#include "pt.h"

PT::PT(std::string str){
parseAgain:    std::cout << str.data() << "\n";
    if (str == ""){evalOper = 0;}
    else{
        if (str == "x"){evalOper = 1;}
        else{
            parse(str);
            if (operation == "+"){
                evalOper = 2;
                leftSide = new PT(left);
                rightSide = new PT(rest);
            }
            if (operation == "-"){
                evalOper = 3;
                leftSide = new PT(left);
                rightSide = new PT(rest);
            }
            if (operation == ""){
                str = left;
                goto parseAgain;
            }
        }
    }
}

qreal PT::Eval(qreal x){
    if (evalOper == 0) return 0;
    if (evalOper == 1) return x;
    if (evalOper == 2) return leftSide->Eval(x) + rightSide->Eval(x);
    if (evalOper == 3) return leftSide->Eval(x) - rightSide->Eval(x);
    return 1;
}

void PT::parse(std::string x){
    left = "";
    operation = "";
    rest = "";
    int balance = 0; // Parenthes balance
    //bool isParenthes = false;
    if (x[0] == '('){
        x.erase(0, 1);
        balance = 1;
        while (balance > 0) {
            if (x[0] == '(') {balance++;}
            if (x[0] == ')') {balance--;}
            if (balance > 0) left +=x[0];
            x.erase(0, 1);
        }
        if (x != ""){
            operation += x[0];
            x.erase(0, 1);
        }
        rest.append(x);
    }
    else{
        for (unsigned int i = 0; i < x.length() && operation == ""; i++){
            if (x[0] == '+'){
                operation = "+";
            }
            if (x[0] == '-') operation = "-";
            if (x[0] != '+' && x[0] != '-'){
                left += x[0];
            }
            x.erase(0,1);
        }
        rest.append(x);
    }
}
