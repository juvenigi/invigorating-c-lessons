#include <stdio.h>

int main(void){
  int a=2, b=5, *c=&a, *d = &b;
  a=*c * *d;
  *d -=3;
  b=a*b;
  c=d;
  b=7;
  a=*c+*d;
  printf("%i\n",a);
  return 0;
}
