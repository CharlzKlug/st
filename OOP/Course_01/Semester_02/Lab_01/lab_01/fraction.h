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
    Fraction & lOperation (int (int, int), const Fraction&);
    // высокоуровневая для неразрушающих *, /, -, +
    //Fraction& aOper (void (Fraction&, Fraction&), Fraction&, Fraction&);


public:
    Fraction(); // конструктор
    Fraction(int, int); // конструктор
    Fraction(const Fraction& q); // конструктор на основе конструктора
    int getNumerator(); // возврат числителя
    int getDenominator(); // возврат знаменателя
    void setValue(int, int); // присваивание новых значений
    Fraction& operator = (const Fraction&); // перегрузка оператора =

    Fraction& operator += (const Fraction&); // перегрузка += (деструктивная!)
    Fraction& operator -= (const Fraction&); // перегрузка -= (деструктивная!)
    Fraction& operator *= (const Fraction&); // перегрузка *= для аргумента дроби!
    Fraction& operator /= (const Fraction&); // перегрузка /= для аргумента-дроби!

    Fraction& operator += (const int&); // прибавление числа!
    Fraction& operator -= (const int&); // отнимание числа!
    Fraction& operator *= (const int&); // умножение на число!
    Fraction& operator /= (const int&); // деление на число!

    // недеструктивные операции с дробями
    friend Fraction operator + (const Fraction&, const Fraction&);
    friend Fraction operator - (const Fraction&, const Fraction&);
    friend Fraction operator * (const Fraction&, const Fraction&);
    friend Fraction operator / (const Fraction&, const Fraction&);

    // недеструктивные операции с дробью и целым числом
    friend Fraction operator + (const Fraction&, const int&);
    friend Fraction operator - (const Fraction&, const int&);
    friend Fraction operator * (const Fraction&, const int&);
    friend Fraction operator / (const Fraction&, const int&);

    friend Fraction operator + (const int&, const Fraction&);
    friend Fraction operator - (const int&, const Fraction&);
    friend Fraction operator * (const int&, const Fraction&);
    friend Fraction operator / (const int&, const Fraction&);
};


#endif // FRACTION_H
