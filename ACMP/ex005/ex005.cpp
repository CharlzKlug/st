#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
using namespace std;

string NumberToString ( int Number )
{
  ostringstream ss;
  ss << Number;
  return ss.str();
}

int main(){
  ifstream infile("input.txt");
  ofstream outfile("output.txt");

  // Количество чисел
  int n;
  infile >> n;
  string odds="", evens="";
  int fours=0, currentNumber;
  for (int i=1; i<=n; i++){
    infile>>currentNumber;
    if ((currentNumber%2)==0){
      evens=evens+NumberToString(currentNumber)+" ";
      fours++;
    }
    else{
      odds=odds+NumberToString(currentNumber)+" ";
    }
  }
  outfile<<odds<<"\n";
  outfile<<evens<<"\n";
  if (fours>=(n-fours)) outfile<<"YES";
  else outfile<<"NO";
  return 0;
}
