#include <stdio.h>

double quickmaffs (double i){
  return i + 2 - 1;
}

int main () {
  double truth = 6;
  double juge = 2.0e3;
  truth *= truth;
  printf("opposite of truth: %i\n",!truth);
  printf("truth: %f\n",truth);
  printf("juge: %f\n",juge);
  printf("quickmaffs: %f\n",quickmaffs(2));
  return 0;
}

