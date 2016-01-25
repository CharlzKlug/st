//Реализация задачи №1 "A+B" на C
#include <stdio.h>

long a,b;

int main(){
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  scanf("%ld%ld",&a,&b);
  printf("%ld",a+b);
  return 0;
}
