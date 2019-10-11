#include <stdio.h>
#define ARR_LEN 10


// FIXME: sizeof(array) weirdness
int arr_largest(int * array,int array_length){
  int result = array[0];
  for(int i=1;i<array_length;i++){
    if(array[i]>result){
      result = array[i];
    }
  }
  return result;
}

int arr_equalp(int * arr_1, int * arr_2){
  if(sizeof(*arr_1)!=sizeof(*arr_2)){
    return 0;
  }
  for(int i=0;i<sizeof(*arr_1);i++){
    if(arr_1[i]!=arr_2[i]){
      return 0;
    }
  }
  return 1;
}

void arr_seek_replace(int * array, int to_replace, int replacer){
  for(int i=0;i<10;i++){
    if(array[i]==to_replace){array[i]=replacer;}
  }
  // return void;
}

void arr_printarr(int * in_array){
  //  for(int i=0;i<sizeof(*in_array);i++){
  for(int i=0;i<10;i++){
    printf("%i ",in_array[i]);
  }
  printf("\n");
}


/* basic plan:
   implement recursive merge sort
   compare pairs
   compare pairs of pairs
   etc...
 */

int tensort_comparer(int a, int b){


  return largest;}

void optimized_tensort(int * lentenarr){
  if(sizeof(lentenarr)!=10){
    return 0;}
}
int main(){
  //static const int arr_len = 10;
  int myray[ARR_LEN] = { 5, 7, 10, 20, -2, -4, 5, 0, -20, 42};
  int myray2[9] = { 5, 7, 20, -2, -4, 5, 0, -20, -42};
  int myray3[ARR_LEN] = { 5, 0, 10, 20, -2, -4, 5, 0, -20, -42};
  printf("%i\n",arr_largest(myray,ARR_LEN));

  printf("%i\n",arr_equalp(myray,myray2));
  printf("%i\n",arr_equalp(myray,myray));
  printf("%i\n",arr_equalp(myray,myray3));

  arr_printarr(myray);
  arr_seek_replace(myray, 42, 0);
  arr_printarr(myray);
  return 0;
}
