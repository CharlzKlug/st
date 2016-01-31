#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

const int zero=0;
const int three=3;
const int myLowBound=-100;
const int myHighBound=100;

string NumberToString ( int Number )
{
  ostringstream ss;
  ss << Number;
  return ss.str();
}

string findRoots (int a, int b, int c, int d, int lowBound, int highBound){
  string myString="";
  int rootCount=zero;
  for (int i=lowBound; i<=highBound && rootCount<three; i++){
    if (i==zero && d==zero) myString=myString+"0 ";
    if (i!=zero){
      if (d%i==zero && a*i*i+b*i==-d/i-c) {
	myString=myString+NumberToString(i)+" ";
	rootCount++;
      }
    }
  }
  return myString;
}

int main(){
  ifstream infile("input.txt");
  ofstream outfile("output.txt");
  int a, b, c, d;
  infile>>a;
  infile>>b;
  infile>>c;
  infile>>d;
  outfile<<findRoots(a, b, c, d, myLowBound, myHighBound);
  return zero;
}
