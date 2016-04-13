#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(){
  srand(time(NULL));
  int a[10];
  int i;
  printf("Array initialization:\n");
  for (i=0; i<10; ++i){
    a[i]=rand();
    printf("a[%d]= %d\n", i, a[i]);
  }
  int temp, t;
  for (i=1; i<10; ++i){
    temp=a[i];
    t=i-1;
    while (t>=0 && a[t]>temp){
      a[t+1]=a[t];
      t=t-1;
    }

    a[t+1]=temp;
  }

  printf("After insert sort:\n");
  for (i=0; i<10; ++i){
    printf("a[%d]= %d\n", i, a[i]);
  }
    
  return 0;
}
