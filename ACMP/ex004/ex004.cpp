#include <stdio.h>
#include <cmath>

int main(){
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int a;
  scanf("%ld", &a);
  printf("%ld9%ld", a, 9-a);
  fclose(stdin);
  fclose(stdout);
  return 0;
}
