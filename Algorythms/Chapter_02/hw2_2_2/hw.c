#include <stdio.h>
#include <time.h>
#include <stdlib.h>

const int zero=0, one=1;
const int n=4; // Количество элементов в массиве

void feelArray (int * someArray, int count){
  // Заполнение элементов массива
  int i;
  for (i=0; i<count; ++i){
    someArray[i]=rand();
  }
}

void printArray(int * someArray, int count){
  int i;
  for (i=0; i<count; ++i)
    printf("[%d]: %d\n", i, someArray[i]);
}

void selectionSort (int * someArray, int count){
  // Сортировка выбором
  int i, j, minIndex, temp;
  for (i=zero; i<count-one; ++i){
    minIndex=i;
    for (j=i+one; j<count; ++j)
      if (someArray[j]<someArray[minIndex]) minIndex=j;
    if (minIndex!=i){
      temp=someArray[i];
      someArray[i]=someArray[minIndex];
      someArray[minIndex]=temp;
    }
  }
}

int main(){
  srand(time(NULL));
  int A[n];
  feelArray(A, n);
  printf("Array A before sorting:\n");
  printArray(A, n);
  selectionSort(A, n);
  printf("\n");
  printf("Array A after sorting:\n");
  printArray(A, n);
  return 0;
}
