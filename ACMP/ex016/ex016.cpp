#include <iostream>
#include <fstream>

int pyrRecur (int start, int base, int blocks, int count)
{
  if (start + base == blocks) ++count;
  if (start + base >= blocks) return count;
  int current = start + 1;
  while (start + current + base <= blocks)
    {
      count = pyrRecur (current, base+start, blocks, count);
      ++current;
    }
  return count;
}

int pyr (int blocks) {
  return pyrRecur (0, 0, blocks, 0);
}

int main ( ) {
  //std::cout << pyr(100) << std::endl;

  std::ifstream inputFile ( "input.txt" ) ;
  if ( !inputFile.bad ( ) ) {
    int a, counts ;
    inputFile >> a ;
    counts = pyr (a) ;
    std::ofstream outputFile ( "output.txt" ) ;
    if ( !outputFile.bad ( ) ) {
      outputFile << counts ;
      outputFile.close ( ) ;
    }
    inputFile.close ( ) ;
  }
  return 0;
}
