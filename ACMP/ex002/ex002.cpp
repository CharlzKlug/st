// Sum between 1 and N (N may be negative, e.g., N=-1000)
#include <stdio.h>
#include <cmath>
using namespace std;

// Using sum of arythmetic progression
int sumN (int n){
  return ((1+n)*(abs(n-1)+1))/2;
}

int main(){
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  // n hold N's value
  long n;
  scanf("%ld", &n);
  printf("%ld", sumN(n));
  fclose(stdin);
  fclose(stdout);
  return 0;
}
