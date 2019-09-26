#include <stdio.h>

int main(void){
  int n = 10;
  int i = 1; // probably not 0
  int sum;

  while (i <= n){ // leq not l
    sum +=i; // forgot semicolon
    i++;} // forgot incrementation, could use a for loop
  printf("Result: %i\n", sum); // we're using integers, not floats
  return 0;}
