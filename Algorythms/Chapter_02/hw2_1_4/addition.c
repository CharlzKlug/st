#include <stdio.h>
#include <time.h>
#include <stdlib.h>

const int zero=0;
const int one=1;
const int n=4; // Количество элементов в массиве

void resetArray(int * someArray, int count){
  // Обнуление массива
  int i;
  for (i=zero; i<count; ++i){
    someArray[i] = zero;
  }
}

void feelArray(int * someArray, int count){
  // Заполнить массив случайными нулями и единицами
  int i;
  for (i=zero; i<count; ++i)
    someArray[i]=rand()%2;
}

void printArray(int * someArray, int count){
  int i;
  for (i=0; i<count; ++i)
    printf("[%d]: %d\n", i, someArray[i]);
}

void addValue(int * someArray, int index, int value){
  // Сложение элемента массива с некоторым значением
  if (someArray[index]==one && value==one){
    someArray[index]=zero;
    addValue(someArray, index-one, value);
  }
  else {
    someArray[index]=someArray[index]+value;
  }
}

void sumArrays(int * recepient, int rCount, int * donor){
  // Сложение двух массивов
  int i;
  for (i=rCount-one; i>0; --i){
    addValue(recepient, i, donor[i-one]);
  }
}

int main(){
  srand(time(NULL));
  int A[n];
  feelArray(A, n);
  int B[n];
  feelArray(B, n);

  printf("Array A:\n");
  printArray(A, n);

  printf("Array B:\n");
  printArray(B, n);

  int CCount=n+one;
  int C[CCount];
  resetArray(C, CCount);

  printf("Array C:\n");
  printArray(C, CCount);

  sumArrays(C, CCount, A);
  sumArrays(C, CCount, B);
  printf("Array C:\n");
  printArray(C, CCount);
  int i;

  return zero;
}
