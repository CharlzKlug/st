#include <stdio.h>
#include <cmath>

unsigned long int shortSquare (int a){
  a=(a-5)/10;
  return a*(a+1);
}

int main(){
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  long a, result;
  scanf("%ld", &a);
  result=shortSquare(a);
  if (result==0) printf("25");
  else printf("%ld25",result);
  //  printf("%ld%ld", shortSquare(a), 25);
  fclose(stdin);
  fclose(stdout);
  return 0;
}
