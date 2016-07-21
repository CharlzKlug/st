#include <iostream>
#include <fstream>
#include <cmath>

int area(int ax, int ay, int bx, int by,
	 int cx, int cy) {
  return std::abs((by - ay) * (cx - ax) -
		  (bx - ax) * (cy - ay));
}

bool inArray(int a[]) { 
    int s = area(a[2], a[3], a[4], a[5], a[6], a[7]) * 2;
    int s1 = area(a[0], a[1], a[2], a[3], a[8], a[9]);
    int s2 = area(a[0], a[1], a[2], a[3], a[4], a[5]);
    int s3 = area(a[0], a[1], a[4], a[5], a[6], a[7]);
    int s4 = area(a[0], a[1], a[6], a[7], a[8], a[9]);
       
    if (s1 + s2 + s3 + s4 - s <= 0)
        return true;
            
    return false;
}

int main(){
  std::ifstream infile ( "input.txt" );
  if ( !infile.bad ( ) ) {
    int residentsCount; // Число дачников
    int coordinates[10];
    infile >> residentsCount;
    int accuracyResidents = 0 ; // Число точно приземлившихся
    for ( int i = 1; i <= residentsCount; i++ ) {
      for ( int j = 0 ; j < 10 ; ++j ) {
	infile >> coordinates [ j ] ;
      }
      if ( inArray ( coordinates ) )
	++accuracyResidents ;
    }
    infile.close();
    std::ofstream outfile("output.txt");
    if (!outfile.bad()) {
      outfile << accuracyResidents ;
      outfile.close();
    }
    std::cout << "Accuracy: " <<
      accuracyResidents << std::endl ;
  }
  return 0;
}
