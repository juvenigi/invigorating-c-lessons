#include <stdio.h>

int main(){
  int i;
  int *p;
  //  double euler = 2.71928; // some weird ass variable which was included for some reason

  i = 42;
  /* Spaghetti begins here */

  p = &i;

  printf("%i\n",*p);
  return 0;
}
