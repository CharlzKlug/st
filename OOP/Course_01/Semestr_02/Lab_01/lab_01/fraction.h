#ifndef FRACTION_H
#define FRACTION_H
#include <cmath>

class Fraction {
private:
    int numerator; // числитель
    int denominator; // знаменатель
    void simplify(); // упрощение дроби
    int gcd (int, int); // наибольший общий делитель
    int lcm (int, int); // наименьшее общее кратное
    static int addition (int, int); // сложение двух чисел
    static int subtraction (int, int); // вычитание двух чисел

    // высокоуровневая линейная операция
    void lOperation (int (int, int), const Fraction&);


public:
    Fraction(); // конструктор
    Fraction(int, int); // конструктор
    Fraction(const Fraction& q); // конструктор на основе конструктора
    int getNumerator(); // возврат числителя
    int getDenominator(); // возврат знаменателя
    void setValue(int, int); // присваивание новых значений
    void operator = (const Fraction&); // перегрузка оператора =
    void operator *= (const int); /* перегрузка оператора *= (деструктивная!)*/
    void operator /= (const int); // перегрузка /= (деструктивная!)
    void operator += (const Fraction&); // перегрузка += (деструктивная!)
    void operator -= (const Fraction&); // перегрузка -= (деструктивная!)
    void operator *=(const Fraction&); // перегрузка *= для аргумента дроби!
    void operator /= (const Fraction&); // перегрузка /= для аргумента-дроби!
};

int foo();
Fraction operator + (Fraction, Fraction);
Fraction operator - (Fraction, Fraction);
Fraction operator * (const Fraction&, const Fraction&);
Fraction operator / (Fraction, Fraction);

// высокоуровневая для неразрушающих *, /, -, +
Fraction aOper (void (Fraction&, const Fraction&), const Fraction&, const Fraction&);

// действия над дробями
void multiple (Fraction&, const Fraction&);
#endif // FRACTION_H
