#include <stdio.h>
//#include <string.h>
#include <stdlib.h>


int comparenums(int a,int b){
  while (a!=0&&b!=0){
    if (a>b){a = a-b;}
    else{b = b-a;};
    printf("%i, %i\n",a,b);
  };
  printf("result: ");
  if(a==0){printf("%i\n",b);}
  else{printf("%i\n",a);};
  return 0;
}
int main(int count,char *args[]){
  char *a = args[1];
  char *b = args[2];
  int num_a = atoi(a);
  int num_b = atoi(b);
  //int num_a = 2;
  //int num_b = 5;
  printf("Iterating using: %i %i\n",num_a,num_b);
  comparenums(num_a,num_b);
  printf("\n");
  return 0;
}
