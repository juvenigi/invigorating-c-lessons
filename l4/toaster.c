#include <stdio.h>
#include "toaster.h"

int toaster(int i){
  return ++i;
}

int main(void){
  printf("%i",toaster(1));}
