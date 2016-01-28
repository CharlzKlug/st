#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
using namespace std;

string maxNumber (string a, string b){
    if (a.size()>b.size()) return a;
    if (b.size()>a.size()) return b;
    int i=0;
    while (i<a.size() && a[i]==b[i]) i++;
    if (i==a.size()) return a;
    if (a[i]>b[i]) return a;
    if (b[i]>a[i]) return b;
}

string biggestNumber (string a, string b, string c){
  return maxNumber(b, maxNumber(a,c));
}

int main(){
  ifstream infile("input.txt");
  ofstream outfile("output.txt");
  string a,b,c;
  infile>>a;
  infile>>b;
  infile>>c;
  outfile<<biggestNumber(a, b, c);
  return 0;
}
