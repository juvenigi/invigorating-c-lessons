#include <stdio.h>
#include <stdlib.h>

//FIXME: this won't compile, need to fix local variables
int * merge(int *list1, int l_1, int *list2, int l_2){
  int * result = (int *) malloc(sizeof(int)*(l_1+l_2));
  for(int i,j,k = 0; i<l_1 && j<l_2;k++){
    if(list1[i]<list2[j]){
      result[k]=list1[i];
      i++;
      }
    else{
      result[k]=list2[j];
      j++;
    }
    if(i<l_1 -1){
      for(;i<l_1;i++){
        result[k]=list1[i];
        k++;
      }
    }
    else if(;j<l_2 -1){
      for(;j<l_1;i++){
        result[k]=list1[j];
        k++;
      }
    }
    return result;
  }
  return result;
}

int mergesort(int *list, int length){
  // creates up to 3 lists and calls itself recursively
}

int main(void){


  return 0;
}
