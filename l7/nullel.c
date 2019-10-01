#include<stdio.h>
#include<stdlib.h>
#include"../modules/arrayhelpers.h"

int findmax(int * array,int length){
  int max = 0;
  for(int i=0;i<length;i++){
    if(max<array[i]){max=array[i];}
  }
  return max;
}

int * magicarr(int * array,int arr_len){
  int * o_array = (int *) malloc(sizeof(int) * (arr_len+1));
  
  for(int i=1; i<arr_len;i++){
    val = array[i];
    o_array[val]=val;
  }
}

int main(void){
  int arr[4] = {3, 5, 6};
  
  return 0;
}
