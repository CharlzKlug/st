#include <iostream>

int someFunc ( ) {
  std::cout << "Some text." << std::endl;
  return 3;
}

int merge ( int * A, int start, int middle, int end, int count ) {
  int maxDim = std::max ( middle + 1 - start, end - middle );
  int * r = new int [ end + 1 ];
  int lc = start, rc = middle + 1;
  for ( int i = 0; i < maxDim; ++i ) {
    if ( lc <= middle && rc <= end ) {
      if ( A[lc] < A[rc] ) {
	r[i] = A[lc];
	++lc;
      }
      else {
	r[i] = A[rc];
	++rc;
	count = count + middle - lc + 1;
      }
    }
    else
      if (lc > middle) {
	r[i] = A[rc];
	++rc;
      }
      else
	if (rc > end) {
	  r[i] = A[lc];
	  ++lc;
	}
  }
  for (int i = 0; i < end + 1; ++i) A[i + start] = r[i];
  delete r;
  return count;
}

int mergeCountRecur ( int * a, int start, int end, int count ) {
  if (start != end) {
    int mid = (start + end) / 2;
    count = mergeCountRecur (a, start, mid, count);
    count = mergeCountRecur (a, mid+1, end, count);
    count = merge (a, start, mid, end, count);
  }
  return count;
}

int mergeCount (int * a, int arrayLength) {
  return mergeCountRecur (a, 0, arrayLength - 1, 0);
}

int main ( ) {
  int a[5] = {5, 4, 3, 2, 1};
  std::cout << mergeCount(a, 5) << std::endl;
  return 0;
}
