#include <iostream>
#include <cstdlib>

const int zero=0, one=1, arrayLength=40;

void merge (int * A, int p, int q, int r){
  // Слияние двух частей массива
  int n1 = q-p+one; // Количество элементов в первой половине [p,q]
  int n2 = r-q; // Количество элементов во второй половине ]q,r]
  int i, j, k;
  int * L = new int[n1]; // Левый массив
  int * R = new int[n2]; // Правый массив
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
  delete L;
  delete R;
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
    someArray[i]=std::rand();
  }
}

void printArray(int * someArray, int count){
  int i;
  for (i=0; i<count; ++i)
    //printf("[%d]: %d\n", i, someArray[i]);
    std::cout<<"["<<i<<"]: "<< someArray[i]<<std::endl;
}

int main(){
  int * a;
  a = new int[arrayLength];
  feelArray (a, arrayLength);
  mergeSort (a, arrayLength);
  printArray (a, arrayLength);
  delete a;
  return zero;
}
