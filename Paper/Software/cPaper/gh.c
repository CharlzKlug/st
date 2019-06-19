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

  genann * ann = genann_init(10, 1, 15, 1);

  // Training network
  for (i = 0; i < 5000; ++i) {
    k = (double) rand() / RAND_MAX * 19;
    genann_train(ann, input[k], output + k, 3);
  }

  FILE *myFile;
  double inp[10];
  int j;
  float vvv;
  //  double tmp;

  //printf("Second fopen");
  myFile=fopen("real.txt", "r");

  for (i=1; i<100; i++) {
    fscanf(myFile, "%f", &vvv);
    for (j=0; j<8; j++) {
      inp[j] = inp[j+1];
    }
    inp[9] = vvv;
    if (i>10) {
      printf("Actual: %f, neural: %f\n", inp[9], (* genann_run(ann, inp)) * 3);
    }
    //printf("%f\n", vvv);
  }
  // Clear objects
  genann_free(ann);
  fclose(myFile);
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
    printf("%f\n", waveHeight);
    outArr[i] = waveHeight / 3;
  }
  fclose(fp);
}
