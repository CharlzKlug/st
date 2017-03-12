#include "mathlib.h"

double rnd(){
    return rand()/static_cast <double> (RAND_MAX);
}

void initGen(){
    srand(1241 * time(0));
}

double rnd(double a, double b){
    return (b-a)*rnd() + a;
}
