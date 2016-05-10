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

  int index=-1, v=10;
  for (i=0; i<10; ++i){
    if (a[i]==v) index=i;
  }

  printf("index=%d\n", index);
    
  return 0;
}
