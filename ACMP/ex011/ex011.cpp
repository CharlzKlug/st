#include <fstream>
#include <string>
#include <sstream>
using namespace std;

const int zero=0;
const int one=1;
const int zeroASCII=48;
const int doubleZeroASCII=2*zeroASCII;
const int nine=9;
const int ten=10;

string NumberToString ( int Number )
{
  ostringstream ss;
  ss << Number;
  return ss.str();
}

string addStringsIter(string a, string b, bool extraOne, int currentPosition, string result){
  int aPosition=a.size()-currentPosition;
  int bPosition=b.size()-currentPosition;
  int extraAdd=extraOne? one:zero;
  int sum;
  if (aPosition>-one && bPosition>-one){
    sum=a[aPosition]+b[bPosition]-doubleZeroASCII;
  }
  if (aPosition>-one && bPosition<zero){
    sum=a[aPosition]-zeroASCII;
  }
  if (aPosition<zero && bPosition>-one){
    sum=b[bPosition]-zeroASCII;
  }
  if (aPosition<zero && bPosition<zero){
    if (extraOne){
      return (string)"1"+result;}
    return result;
  }
  sum=sum+extraAdd;
  if (sum>nine) return addStringsIter(a, b, true, currentPosition+one, NumberToString(sum%ten)+result);
  return addStringsIter(a, b, false, currentPosition+one, NumberToString(sum)+result);
}

string addStrings(string a, string b){
  return addStringsIter(a, b, false, one, "");
}

string waysCount(int N, int K){
  if (K==one) return "1";
  string temp;
  if (N<=K){
    temp="1";
    for (int i=one; i<N; i++) temp=addStrings(temp, temp);
    return temp;
  }
  string *memoise=new string[K];
  memoise[zero]="1";
  for (int i=one; i<K; i++){
    memoise[i]=addStrings(memoise[i-one], memoise[i-one]);
  }
  for (int i=K; i<N; i++){
    temp="0";
    for (int j=zero; j<K; j++){
      temp=addStrings(memoise[j], temp);
      if (j!=K-one) memoise[j]=memoise[j+one];
    }
    memoise[K-one]=temp;
  }
  delete [] memoise;
  return temp;
}

int main(){
  ifstream infile("input.txt");
  ofstream outfile("output.txt");
  int K;
  infile>>K;
  int N;
  infile>>N;
  outfile<<waysCount(N, K);
  return zero;
}
