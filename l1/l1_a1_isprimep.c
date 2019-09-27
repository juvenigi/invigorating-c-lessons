#include <stdio.h>
#include <math.h>

int main(void){
  int c = 100;
  int n = 2;
  while(1){ // don't write complicated code in an infinite loop, for your sanity's sake!
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
