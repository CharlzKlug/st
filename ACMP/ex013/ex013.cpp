#include <iostream>
#include <fstream>
int getBulls ( int a, int b ) {
  int bulls = 0 ;
  while ( a > 0 ) {
    if ( a % 10 == b % 10 ) ++bulls ;
    a = a / 10 ;
    b = b / 10 ;
  }
  return bulls ;
}

int getCows ( int a, int b ) {
  int cows = 0, temp, c;
  bool foundCow;
  while ( b > 0 ) {
    c = b % 10;
    foundCow = false;
    temp = a ;
    while ( temp > 0 && !foundCow ) {
      if ( temp % 10 == c) {
	++cows;
	foundCow = true;
      }
      temp = temp / 10 ;
    }
    b = b / 10;
  }
  return cows ;
}

int main () {
  std::ifstream inputFile ( "input.txt" );
  if ( !inputFile.bad() ) {
    int a, b;
    inputFile >> a ;
    inputFile >> b ;
    std::ofstream outputFile ( "output.txt" );
    if ( !outputFile.bad() ) {
      int bulls = getBulls ( a, b );
      outputFile << bulls << " " << getCows ( a , b ) - bulls ;
      outputFile.close();
    }
    inputFile.close() ;
  }
  return 0 ;
}
