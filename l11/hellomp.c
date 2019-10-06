#include <stdio.h>
#include <omp.h> // for epic stuff

//NOTE: compile with -fopenmp

int main(void){
  #pragma omp parallel
  printf("Hello World!\n"); // prints hello world times the number of cores your pc has
  return 0;
}
