#include "fraction.h"

Fraction :: Fraction (int an, int ad){
    // конструктор с аргументами
    numerator = an;
    denominator = ad;
    simplify();
}

Fraction :: Fraction (){
    // конструктор без аргументов
    //Fraction (1, 1);
    numerator = 1;
    denominator = 1;
}

int Fraction :: gcd (int a, int b) {
    // нахождение Наибольшего Общего Делителя алгоритмом Евклида

    a = std::abs(a);
    b = std::abs(b);
    if (a == b || b == 0) return a;
    if (a == 0) return b;

    int smallest = a < b ? a : b;
    int biggest = a > b ? a : b;
    return gcd (smallest, biggest - smallest);
}

void Fraction :: simplify(){
    // упрощение дроби
    int calc_gcd = gcd(numerator, denominator);
    numerator = numerator / calc_gcd;
    denominator = denominator / calc_gcd;
    if (denominator < 0) {
        numerator *= -1;
        denominator *= -1;
    }
}

int Fraction :: getNumerator(){
    // возврат числителя
    return numerator;
}

int Fraction :: getDenominator(){
    // возврат знаменателя
    return denominator;
}

void Fraction :: setValue(int n, int d){
    // присваивание новых значений
    numerator = n;
    denominator = d;
    simplify();
}

void Fraction :: operator = (const Fraction& q){
    // перегрузка оператора =
    numerator = q.numerator;
    denominator = q.denominator;
}

Fraction :: Fraction (const Fraction & q ){
    // конструктор на основе конструктора
    numerator = q.numerator;
    denominator = q.denominator;
}

void Fraction :: operator *= (const int c){
    // перегрузка оператора * (деструктивная операция!)
    numerator *= c;
    simplify();
}

void Fraction :: operator *= (const Fraction& q){
    // перегрузка *= для аргумента-дроби
    numerator *= q.numerator;
    denominator *= q.denominator;
    simplify();
}

void Fraction :: operator /= (const int c){
    // перегрузка /= (деструктивная!)
    denominator *= c;
    simplify();
}

void Fraction :: operator /= (const Fraction& q){
    // перегрузка /= для аргумента-дроби
    numerator *= q.denominator;
    denominator *= q.numerator;
    simplify();
}

int Fraction :: lcm (int a, int b){
    // наибольшее общее кратное
    return a * b / gcd(a, b);
}

void Fraction :: operator += (const Fraction& q){
    // перегрузка += (деструктивная!)
    lOperation(addition, q);
}

void Fraction :: operator -= (const Fraction& q){
    // перегрузка -= (деструктивная!)
    lOperation(subtraction, q);
}

int foo (){return 3;}

Fraction operator + (Fraction fa, Fraction fb){
    // перегрузка оператора +
    Fraction temp;
    temp = fa;
    temp += fb;
    return temp;
}

Fraction operator -(Fraction fa, Fraction fb){
    // перегрузка оператора -
    Fraction temp;
    temp = fa;
    temp -= fb;
    return temp;
}

Fraction operator *(const Fraction& fa, const Fraction& fb){
    // перегрузка *
    return aOper(multiple, fa, fb);
}

Fraction operator /(Fraction fa, Fraction fb){
    // перегрузка /
    Fraction temp;
    temp = fa;
    temp /= fb;
    return temp;
}

Fraction aOper(void f (Fraction &, const Fraction &), const Fraction & fa, const Fraction& fb){
    // высокоуровневая для неразрушающих *, /, -, +
    Fraction temp;
    temp = fa;
    f (temp, fb);
    return temp;
}

void multiple(Fraction & fa, const Fraction & fb){
    // разрушающее умножение
    fa *= fb;
}

int Fraction :: addition(int a, int b){
    // сложение двух чисел
    return a + b;
}

int Fraction :: subtraction(int a, int b){
    // вычитание одного числа из другого
    return a - b;
}

void Fraction :: lOperation(int func (int, int), const Fraction & q){
    // высокоуровневая операция (для сложения и вычитания)
    int c_lcm = lcm (denominator, q.denominator);
    numerator *= (c_lcm / denominator);
    denominator = c_lcm;
    int tempNumerator = q.numerator * (c_lcm / q.denominator);
    numerator = func(numerator, tempNumerator);
    simplify();

}
