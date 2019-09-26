#include <stdio.h>
//#include <string.h>
#include <math.h>

int main(void){
  int c = 100;
  //double sqrt_c = sqrt(100);
  int n = 2;
  while(1){
    if(n >  sqrt( (double) c) ){
      printf("true!");
      break;
    };
    if((c%n) == 0){
      printf("false!");
      break;
    };
    n++;
    printf("n: %i\n",n);
  }
  printf("\n");
  return 0;
}
