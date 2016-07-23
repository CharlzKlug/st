#include <iostream>
#include <fstream>

int gcd ( int a, int b ) {
  if ( a == 0 || b == 0 ) return 0 ;
  int least = a % b ;
  if ( least == 0 ) return b;
  return gcd ( b, least) ;
}

int main ( ) {
  std::ifstream inputFile ( "input.txt" ) ;
  if ( !inputFile.bad ( ) ) {
    int a, b ;
    inputFile >> a ;
    inputFile >> b ;
    int myGcd = gcd ( a, b ) ;
    std::ofstream outputFile ( "output.txt" ) ;
    if ( !outputFile.bad ( ) ) {
      outputFile << ( a / myGcd ) * b ;
      outputFile.close ( ) ;
    }
    inputFile.close ( ) ;
  }
  return 0 ;
}
