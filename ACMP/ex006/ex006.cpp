#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <cmath>
using namespace std;

bool isCorrect (string inputLine){
  bool resultCode=true;
  if (inputLine.size()!=5) resultCode=false;
  if (resultCode && (inputLine[0]<'A' || inputLine[0]>'H')) resultCode=false;
  if (resultCode && (inputLine[1]<'1' || inputLine[1]>'8')) resultCode=false;
  if (resultCode && inputLine[2]!='-') resultCode=false;
  if (resultCode && (inputLine[3]<'A' || inputLine[3]>'H')) resultCode=false;
  if (resultCode && (inputLine[4]<'1' || inputLine[4]>'8')) resultCode=false;
  return resultCode;
}

int xCoord(char someChar){
  return someChar-64;
}

int yCoord(char someChar){
  return someChar-48;
}

void loadData (string inputLine, int &x1, int &y1, int &x2, int &y2){
  x1=xCoord(inputLine[0]);
  y1=yCoord(inputLine[1]);
  x2=xCoord(inputLine[3]);
  y2=yCoord(inputLine[4]);
}

int main(){
  ifstream infile("input.txt");
  ofstream outfile("output.txt");
  string inputLine;
  infile>>inputLine;
  if (isCorrect(inputLine)){
    int x1, y1, x2, y2;
    loadData(inputLine, x1, y1, x2, y2);
    int xv, yv;
    xv=abs(x1-x2);
    yv=abs(y2-y1);
    if ((xv==2 && yv==1)|(xv==1 && yv==2)){
      outfile<<"YES";
    }
    else{
      outfile<<"NO";
    }
  }
  else {
    outfile<<"ERROR";
  }
  return 0;
}
