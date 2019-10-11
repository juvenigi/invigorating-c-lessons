#include <stdio.h>
//#include <string.h>
#include <math.h>


unsigned int facult (unsigned int n){
  if (n == 0){return 1;}
  return n * facult(n-1);
}


int main(void){
  int f = 3;
  //int f = 0;
  //int f = -1;
  printf("%i! = %i\n",f, facult(f));
  return 0;
}
