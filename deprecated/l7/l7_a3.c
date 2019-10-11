#include<stdio.h>
#include<stdlib.h>
#include<string.h>


//you can insert strings, which is pretty shitty
double fancy_cos(char * numba){
  int len = strlen(numba);
  double x = atof(numba);
  return (double) len;
}

int main(void){
  printf("%f",fancy_cos("12.12"));
  return 0;
}
