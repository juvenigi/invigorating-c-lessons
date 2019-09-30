#include <stdio.h>
#include <math.h>


//todo implement variable length
int mergepare(int * args){
  int arr_len = 10;
  int reg = 0;
  int reg_s = 0;
  int jumplen = 1;
  bool trailing = 0;
  int tmp = 0;
  while(reg*jumplen<arr_len){

    if(args[reg]>args[reg_s]){
      args[reg+1]=tmp;
      args[reg_s] = args[reg+1];
      args[reg+1]=reg[s];
    }
    else{
      a
    }
    a
    if((reg+1)*jumplen>arr_len){
      trailing = 1;
    }else{ trailing = 0;}
  }
  }
}

int main(void){

  int myray[10] = { 5, 7, 10, 20, -2, -4, 5, 0, -20, 42};

  printf("after sorting:")
