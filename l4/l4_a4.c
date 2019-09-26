#include <stdio.h>

int main(void){
  int length = 4;
  int numbers[length];
  for (int i=0;i<length;i++){
    numbers[i]=i+1;
  }
  int sum = 0;
  for (int i=0;i<length;i++){
    sum+=numbers[i];
  }
  printf("%i\n",sum);
}
