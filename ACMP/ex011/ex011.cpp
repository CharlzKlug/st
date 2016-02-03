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

string subtractStringsIter (string a, string b, bool extraOne, unsigned int currentPosition, string result){
  //a must be greater then b!
  if (currentPosition>a.size()){
    if (result=="") return "0";
    return result;}
  int extraMinus=extraOne? one:zero;
  extraOne=false;
  int aValue=a[a.size()-currentPosition]-zeroASCII;
  int bValue;
  if (currentPosition>b.size()) bValue=0;
  else bValue=b[b.size()-currentPosition]-zeroASCII;
  bValue=bValue+extraMinus;
  int resDigit;
  if (aValue>=bValue){
    resDigit=aValue-bValue;
  }
  else {
    resDigit=ten+aValue-bValue;
    extraOne=true;
  }
  if (resDigit==zero){
    if (currentPosition!=a.size()) result="0"+result;
  }
  else result=NumberToString(resDigit)+result;
  currentPosition=currentPosition+one;
  return subtractStringsIter(a, b, extraOne, currentPosition, result);
}

string subtractStrings(string a, string b){
  // a must be greater then b
  return subtractStringsIter(a, b, false, one, "");
}

string addStringsIter(string a, string b, bool extraOne, unsigned int currentPosition, string result){
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
  string workingSum=memoise[zero];
  for (int i=one; i<K; i++){
    memoise[i]=addStrings(memoise[i-one], memoise[i-one]);
    if (i<K-one) workingSum=addStrings(workingSum, memoise[i]);
  }
  for (int i=K; i<N; i++){
    temp=addStrings(memoise[K-one], workingSum);
    workingSum=addStrings(subtractStrings(workingSum, memoise[zero]), memoise[K-one]);
    for (int j=zero; j<K-one; j++){
      memoise[j]=memoise[j+one];
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
