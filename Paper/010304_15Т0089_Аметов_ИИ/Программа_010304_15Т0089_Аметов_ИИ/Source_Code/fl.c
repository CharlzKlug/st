#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "genann.h"

void readFromFile (const char *, double [][10], double []);

int main(int argc, char *argv[]){
  double input[20][10];
  double output[20];
  srand(time(0));
  
  readFromFile("learnSamples.txt", input, output);

  int l,n,k,i;
  double tmp;

  printf("Networks test result:\n");
  for (l = 1; l < 21; l++)
    for (n = 1; n < 21; n++) {
      genann * ann = genann_init(10, l, n, 1);

      // Training network
      for (i = 0; i < 500; ++i) {
	k = (double) rand() / RAND_MAX * 19;
	genann_train(ann, input[k], output + k, 3);
      }

      // Calculating sum from network
      for (i = 0; i < 20; i++) {
	tmp += abs (((* genann_run(ann, input[i])) - output[i]) * 3) ;
      }
      tmp /= 20;

      // Print results
      printf("Layers: %d, neurons: %d, absolute error: %4.2f\n", l, n, tmp);

      // Clear objects
      tmp = 0;
      genann_free(ann);
    }
  return 0;
}

// Load data from file
void readFromFile (const char * filename, double inArr[][10], double outArr[]) {
  FILE *fp;
  float waveHeight;
  
  fp=fopen(filename, "r");
  
  int i, j;
  for (i=0; i<20; i++) {
    for (j=0; j<10; j++) {
      fscanf(fp, "%f", &waveHeight);
      inArr[i][j] = waveHeight / 3;
    }
    fscanf(fp, "%f", &waveHeight);
    outArr[i] = waveHeight / 3;
  }
  fclose(fp);
}
