#include <stdio.h>
#include <stdlib.h>

/* finds the greatest common divisor (only feed 2 numbers or a segfault happens!) */

int comparenums(int a,int b){
  while (a!=0&&b!=0){
    if (a>b){a = a-b;}
    else{b = b-a;}
    printf("%i, %i\n",a,b);
  }
  printf("result: ");
  if(a==0){printf("%i\n",b);}
  else{printf("%i\n",a);}
  return 0;
}

int main(int count,char *args[]){ // look at these fancy command arguments!
  char *a = args[1];
  char *b = args[2];
  int num_a = atoi(a);
  int num_b = atoi(b);

  printf("Iterating using: %i %i\n",num_a,num_b);
  comparenums(num_a,num_b);
  printf("\n");
  return 0;
}
