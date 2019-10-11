#include <stdio.h>
#include "mymath.h"


int main(){
  double *bin;
  bin = binomialsolve(1.,5.,-6.);
  //  printf("%f",ree_man(2));
  printf("%f %f\n",bin[0],bin[1]);
  return 0;
}
