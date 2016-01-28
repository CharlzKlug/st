#include <iostream>
#include <fstream>
using namespace std;

int main(){
  ifstream infile("input.txt");
  ofstream outfile("output.txt");
  int a,b,c;
  infile>>a;
  infile>>b;
  infile>>c;
  if (a*b==c) outfile<<"YES";
  else outfile<<"NO";
  return 0;
}
