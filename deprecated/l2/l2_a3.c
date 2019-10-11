#include <stdio.h>
//#include <string.h>
#include <math.h>

//TODO: implement a proper function for determining a prime number that comes after n

int main(int number){
  int c = number;
  int n = 2;
  while(1){
    if(n > sqrt( (double) c ) ){
      //printf("true!");
      return 1;
      break;
    };
    if((c%n) == 0){
      //printf("false!");
      return 0;
      break;
    };
    n++;
    //printf("n: %i\n",n);
  }
  printf("\n");
  return 0;
}
