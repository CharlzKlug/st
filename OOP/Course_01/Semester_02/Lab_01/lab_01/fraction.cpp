#include "fraction.h"
#include <stdexcept>

// Генерация исключения
class zeroDenominator
{
  virtual const char* what() const throw()
  {
    return "The denominator can not be equal zero!";
  }
} zeroDenom;


Fraction :: Fraction (int an, int ad){
    // конструктор с аргументами
    if (ad == 0) throw zeroDenom;
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

Fraction :: Fraction (const Fraction & q ){
    // конструктор на основе конструктора
    numerator = q.numerator;
    denominator = q.denominator;
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
    if (d == 0) throw zeroDenom;
    numerator = n;
    denominator = d;
    simplify();
}

Fraction& Fraction :: operator = (const Fraction& q){
    // перегрузка оператора =
    if (this != &q){
    numerator = q.numerator;
    denominator = q.denominator;}

    return * this;
}

Fraction& Fraction :: operator += (const Fraction& q){
    // перегрузка += (деструктивная!)
    return lOperation(addition, q);
}

Fraction& Fraction :: operator -= (const Fraction& q){
    // перегрузка -= (деструктивная!)
    return lOperation(subtraction, q);
}

Fraction& Fraction :: operator *= (const Fraction& q){
    // перегрузка *= для аргумента-дроби
    numerator *= q.numerator;
    denominator *= q.denominator;
    simplify();
    return * this;
}

Fraction& Fraction :: operator /= (const Fraction& q){
    // перегрузка /= для аргумента-дроби

    // для корректного обрабатывания деления самого на себя
    int tn = q.numerator;
    int td = q.denominator;

    this->numerator *= td;
    this->denominator *= tn;
    simplify();
    return * this;
}

Fraction& Fraction :: operator += (const int& a){
    // сложение дроби с числом
    Fraction temp (a, 1);
    return *this += temp;
}

Fraction& Fraction :: operator -= (const int& a){
    // вычитание числа от дроби
    Fraction temp (a, 1);
    return *this -= temp;
}

Fraction& Fraction :: operator *= (const int& a){
    // вычитание числа от дроби
    numerator *= a;
    simplify();
    return * this;
}

Fraction& Fraction :: operator /= (const int& a){
    // вычитание числа от дроби
    denominator *= a;
    simplify();
    return *this;
}

Fraction operator + (const Fraction& a, const Fraction& b){
    return (Fraction)a += b;
}

Fraction operator - (const Fraction& a, const Fraction& b){
    return (Fraction)a -= b;
}

Fraction operator * (const Fraction& a, const Fraction& b){
    return (Fraction)a *= b;
}

Fraction operator / (const Fraction& a, const Fraction& b){
    return (Fraction)a /= b;
}

// недеструктивные операции с дробью и числом
Fraction operator + (const Fraction& a, const int& b){
    Fraction temp (b, 1);
    return (Fraction)a += temp;
}

Fraction operator - (const Fraction& a, const int& b){
    Fraction temp (b, 1);
    return (Fraction)a -= temp;
}

Fraction operator * (const Fraction& a, const int& b){
    Fraction temp (b, 1);
    return (Fraction)a *= temp;
}

Fraction operator / (const Fraction& a, const int& b){
    Fraction temp (b, 1);
    return (Fraction)a /= temp;
}

Fraction operator + (const int& a, const Fraction& b){
    return b + a;
}

Fraction operator - (const int& a, const Fraction& b){
    return b - a;
}

Fraction operator * (const int& a, const Fraction& b){
    return b * a;
}

Fraction operator / (const int& a, const Fraction& b){
    Fraction temp (a, 1);
    return temp / b;
}

// недеструктивные операции с возведением в степень
Fraction operator ^ (const Fraction& anyFrac, const int& m){
    int num = anyFrac.numerator;
    int denom = anyFrac.denominator;
    Fraction tempFrac(pow(num, m), pow(denom, m));
    return tempFrac;
}

Fraction operator ^ (const Fraction& anyFrac, const double& m){
    int num = anyFrac.numerator;
    int denom = anyFrac.denominator;
    Fraction temp((int)exp(log(num)*m), (int)exp(log(denom)*m));
    return temp;
}

int Fraction :: lcm (int a, int b){
    // наибольшее общее кратное
    return a * b / gcd(a, b);
}

int Fraction :: addition(int a, int b){
    // сложение двух чисел
    return a + b;
}

int Fraction :: subtraction(int a, int b){
    // вычитание одного числа из другого
    return a - b;
}

Fraction & Fraction :: lOperation(int func (int, int), const Fraction & q){
    // высокоуровневая операция (для сложения и вычитания)
    int c_lcm = lcm (denominator, q.denominator);
    numerator *= (c_lcm / denominator);
    denominator = c_lcm;
    int tempNumerator = q.numerator * (c_lcm / q.denominator);
    numerator = func(numerator, tempNumerator);
    simplify();
    return * this;
}
