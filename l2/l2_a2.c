#include <stdio.h>

/* each comment = a "mistake", code taken from the exercise */

int main(void){
  int n = 10;
  int i = 1; // probably not 0 because "muh natural numbers don't have a zero"
  int sum;

  while (i <= n){ // leq not l
    sum +=i; // forgot semicolon and it's '+=' not '=+'
    i++;} // forgot incrementation, could use a for loop
  printf("Result: %i\n", sum); // we're using integers, not floats
  return 0;}
