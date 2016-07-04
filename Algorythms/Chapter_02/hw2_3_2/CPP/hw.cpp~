#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

const int zero=0, one=1, arrayLength=40;

void merge (int * A, int p, int q, int r){
  // Слияние двух частей массива
  int n1 = q-p+one; // Количество элементов в первой половине [p,q]
  int n2 = r-q; // Количество элементов во второй половине ]q,r]
  int i, j, k;
  int * L = (int *) malloc (n1 * sizeof (int)); // Левый массив
  int * R = (int *) malloc (n2 * sizeof (int)); // Правый массив
  for (i=zero; i<n1; ++i) L[i]=A[p+i];
  for (j=zero; j<n2; ++j) R[j]=A[q+j+one];
  i=zero;
  j=zero;
  for (k=p; k<=r; ++k){
    if (i==n1) {A[k]=R[j]; ++j;}
    else if (j==n2) {A[k]=L[i]; ++i;}
    if (i!=n1 && j!=n2){
      if (L[i]<=R[j]){
	A[k]=L[i];
	++i;
      }
      else {
	A[k]=R[j];
	++j;
      }
    }
  }
  free (L);
  free (R);
}

void mergeSortPart (int * A, int p, int r){
  // Сортировка части массива
  if (p<r){
    int q=(p+r)/2;
    mergeSortPart (A, p, q);
    mergeSortPart (A, q+one, r);
    merge (A, p, q, r);
  }
}

void mergeSort (int * A, int length){
  // Сортировка всего массива методом слияния
  mergeSortPart (A, zero, length-one);
}

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

int main(){
  int * a;
  a = (int *) malloc (arrayLength * sizeof (int));
  feelArray (a, arrayLength);
  mergeSort (a, arrayLength);
  printArray (a, arrayLength);
  free (a);
  return zero;
}
