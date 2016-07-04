#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

const int zero=0, one=1, two=2, notFound=-1, arraySize=10;

int binarySearch(int * A, int l, int r, int v){
  // Бинарный поиск
  int mid=(l+r)/two;
  if (v == A[mid]) return mid;
  if (l==r) return notFound;
  if (v < A[mid]) return binarySearch(A, l, mid-one, v);
  return binarySearch(A, mid+one, r, v);
}

void printArray(int * someArray, int count){
  int i;
  for (i=0; i<count; ++i)
    printf("[%d]: %d\n", i, someArray[i]);
}

void feelArray (int * someArray, int count){
  // Заполнение элементов массива
  int i;
  for (i=0; i<count; ++i){
    someArray[i]=i;
  }
}

int main(){
  int * A = (int *) malloc (arraySize * sizeof (int));
  feelArray (A, arraySize);
  printf("Enter need number: ");
  int someNumber;
  scanf("%d", &someNumber);
  printf("Found index: %d\n", binarySearch (A, zero, arraySize-one, someNumber));
  printArray(A, arraySize);
  return zero;
}
