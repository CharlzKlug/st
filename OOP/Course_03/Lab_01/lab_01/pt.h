#ifndef PT_H
#define PT_H
//+, -, *, /,
#include <QtGlobal>
//#include <QString>
#include <iostream>
#include <string>

class PT
{
    int evalOper;
    // evalOper codes:
    // 0 - return 0;
    // 1 - return x;
    // 2 - +
    // 3 - -
    PT* leftSide;
    PT* rightSide;
    std::string left, operation, rest;
    void parse(std::string);
public:
    PT(std::string);
    qreal Eval(qreal);
};
#endif // PT_H
