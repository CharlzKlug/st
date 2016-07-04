#include <iostream>

const int n=10, zero=0, one=1, two=2;

void feelArray(int * A, int length){
  // Заполнение массива значениями
  for (int i=zero; i<length; ++i) A[i]=i;
}

void merge(int * A, int start, int q, int end){
  // Операция слияния
  int Llength = q-start+one;
  int * L = new int[Llength];
  for (int i=zero; i<Llength; ++i) L[i] = A[start+i];
  int Rlength = end-q;
  int * R = new int[Rlength];
  for (int i=zero; i<Rlength; ++i) R[i] = A[q+i+one];
  int Ri=zero, Li=zero, j=start;
  while (Li<Llength && Ri<Rlength){
    if (L[Li]<=R[Ri]) {A[j]=L[Li]; ++Li;}
    else {A[j]=R[Ri]; ++Ri;}
    ++j;
  }
  if (Li<Llength) for (; j<=end; ++j) {A[j]=L[Li]; ++Li;}
  if (Ri<Rlength) for (; j<=end; ++j) {A[j]=R[Ri]; ++Ri;}
  delete L;
  delete R;
}

void mergeSortRecursive(int * A, int start, int end){
  // Рекурсивная процедура сортирования слиянием
  if (start!=end){
    int q=(start+end)/two;
    mergeSortRecursive(A, start, q);
    mergeSortRecursive(A, q+one, end);
    merge(A, start, q, end);
  }
}

void mergeSort(int * A, int length){
  mergeSortRecursive(A, zero, length-one);
}

void sortArray(int * A, int length){ mergeSort(A, length);}

int binarySearchIndex(int * A, int val, int start, int end){
  if (start==end){
    if (val==A[start]) {return start;}
    else return -one;
  }
  int q = (start+end)/two;
  int temp = A[q];
  if (val < temp) return binarySearchIndex(A, val, start, q-one);
  if (val > temp) return binarySearchIndex(A, val, q+one, end);
  return q;
}

void findSum(int * A, int length, int sum, int & i1, int & i2){
  // Поиск двух слагаемых
  i1=-one;
  i2=-one;
  int decLen = length-one, temp, i=zero, maxValue=A[decLen];
  while (i1==-one && i<decLen){
    temp=sum-A[i];
    if (temp >= A[i] && temp <= maxValue) {i1=binarySearchIndex(A, temp, i, decLen); i2=i;}
    ++i;
  }
}

void printArray(int * A, int length){
  for (int i=zero; i<length; ++i) std::cout<<"A["<<i<<"]="<<A[i]<<std::endl;
}

int main(){
  int * A = new int[n];
  feelArray(A, n);
  sortArray(A, n);
  printArray(A, n);
  std::cout<<"Enter sum: ";
  int x;
  std::cin>>x;
  int i1=-one, i2=-one; // Индексы искомых чисел
  findSum(A, n, x, i1, i2);
  if (i1 != -one || i2 != -one) std::cout << "I1 = " << i1 << " I2 = " << i2 << std::endl;
  delete A;
  return zero;
}
