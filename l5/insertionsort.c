#include <stdio.h>
#include <math.h>


//todo implement variable length
void isort(int arr_len, int * arr){
  int i,j,t;
  for (i=1;i<arr_len;i++){
    for (j=i; j>0 && arr[j-1] > arr[j]; j--){
      t = arr[j];
      arr[j] = arr[j-1];
      arr[j-1]=t;
    }
  }
}

int main(void){

  int myray[10] = { 5, 7, 10, 20, -2, -4, 5, 0, -20, 42};
  printarr(10,myray);
  printf("after sorting:\n");
  isort(10,myray);
  printarr(10,myray);
}
