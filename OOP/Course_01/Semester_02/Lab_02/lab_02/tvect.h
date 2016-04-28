#ifndef TVECT_H
#define TVECT_H
#include <QtCore>
#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
typedef qreal Mytype;
const int startLength = 10, zero = 0, one = 1, two=2;
class TVect {
private:
    int length;
    Mytype * values;

public:
    TVect ();
    TVect (int);
    TVect (const TVect &);
    TVect (int, const Mytype *);
    ~TVect ();
    bool saveToFile (std::string);
    void outputToScreen();
    bool loadFromFile (std::string);
    void addElement(Mytype);
    void removeElement(int);
    TVect & operator += (TVect &);
    TVect & operator -= (TVect &);
    TVect operator + (TVect &);
    TVect operator - (TVect &);
    TVect & operator *= (TVect &);
    TVect & operator = (TVect &);
    Mytype & operator [] (int);
    TVect operator * (qreal);
    TVect & operator *= (qreal);
    qreal module ();
    int getLength();
    void setLength(int);
    bool getElement(int, Mytype &);
    bool setElement(int, Mytype );
    friend void setRandom(TVect &, qreal, qreal);
};

#endif // TVECT_H
