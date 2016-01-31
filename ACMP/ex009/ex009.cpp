#include <iostream>
#include <fstream>
using namespace std;
const int zero=0;
const int one=1;

int minBetween(int a, int b){
  // Минимальное значение из двух чисел
  if (a>b) return b;
  return a;
}

int maxBetween(int a, int b){
  // Максимальное значение из двух чисел
  if (a>b) return a;
  return b;
}

int main(){
  int N;// Количество элементов
  int sum=zero;// Сумма положительных элементов
  int minIndex=zero;// Индекс минимального элемента
  int maxIndex=zero;// Индекс максимального элемента
  ifstream infile("input.txt");
  ofstream outfile("output.txt");
  infile>>N;
  int *myArray=new int[N];// Создали массив для N элементов
  int temp;// Временная переменная
  for (int i=zero; i<N; i++){
    infile>>temp;
    if (temp>0) sum=sum+temp;
    if (myArray[minIndex]>temp) minIndex=i;
    if (myArray[maxIndex]<temp) maxIndex=i;
    myArray[i]=temp;
  }
  int mulResult=1;// Результат перемножений
  for (int i=minBetween(minIndex, maxIndex)+one; i<maxBetween(minIndex, maxIndex); i++){
    mulResult=mulResult*myArray[i];
  }
  outfile<<sum<<" "<<mulResult;
  delete [] myArray;
  return zero;
}
