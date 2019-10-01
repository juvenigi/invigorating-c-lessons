#include<stdio.h>
#include<stdlib.h>
#include"arrayhelpers.h"

// #define _intarray_init(ex,elen) int * (ex) = malloc(sizeof(int) * (elen))

/*
  Array helpers
*/


//for freeing arrays, just use free(array)
void setarr(int * array, int array_length, int value);

void initarray(int ** pointer,int length){ // FIXME: something is cheesy here
  *pointer = (int *) malloc(sizeof(int) * length);
  return;
}

int * mylloc(int length){
  return (int *) malloc (sizeof(int)*length);
}

void print_int_arr(int mode, int arr_len, int * array){
  for(int i=0;i<arr_len;i++){
    printf("%i",array[i]);
    if(mode){printf(", ");}else{printf("\n");}
  }
  if(mode){printf("\n");}
}

void setintarr(int * array, int array_length, int value){
  for(int i=0; i<array_length; i++){
    array[i]=value;
  }
}

int iwrap(int n, int array_length){
  if(n>array_length-1){
    return n-array_length;
  }
  else if(n<0) {
    return n+array_length;
  }
  else{
    return n;
  }
}

//TODO: implement properly for all kinds of shitfts
void shiftarr_swapper_pos(int * array, int array_length, int rot_k){
  int * rot_temp = (int *) malloc(sizeof(int)*rot_k);

  for(int i = array_length-1,j=rot_k-1;i>array_length-1-rot_k;i--,j--){
    rot_temp[j]=array[i];
  }

  for(int i = array_length-1-rot_k; i>=0; i--){
    array[iwrap(i+rot_k,array_length)]=array[iwrap(i,array_length)];
  }

  for(int i = rot_k-1; i>=0; i--){
    array[i]=rot_temp[i];
  }
  return;
}

void shiftarr(int * array, int array_length, int rot_k){
  int * rot_arr = (int *) malloc(sizeof(int)*array_length);
  int iw=0;
  for(int i=0; i<array_length; ++i){
    iw = iwrap(i+rot_k,array_length);
    rot_arr[iw] = array[i];
  }
  for(int i=0; i<array_length;i++){
    array[i]=rot_arr[i];
  }
  return;
}

void fliparr(int * array, int array_length){
  int t=0; // temporary
  int fli=0;
  for(int i = 0; i<(array_length)/2;i++){
    t = array[i];
    fli = array_length-1 -i;
    array[i] = array[fli];
    array[fli] = t;
  }
  return;
}

int locate_seq(int * array, int array_length, int * array_seq, int array_seq_length){
  int arr_ind = 0;
  for(int i = 0; i<array_length;i++){ // ищем первый элемент
    arr_ind = i; // это типо индекс
    if(array[i]==array_seq[0]){ // оппа нашли (может быть)
      if(arr_ind+1 + array_seq_length > array_length){return -1;} // может у нас не будет больше элементов в первом списке, тогда обрывай
      for(int i = 1; i<array_seq_length; i++){ // итерируем, проверяем что остальные элементы также есть
        if(array[i+arr_ind] != array_seq[i]){return -1;} // оппа нет
      }
      return arr_ind; // оппа да, это типа индекс первого элемета второго в первом
    }
  }
  return -1;
}



/* int main(void){ */
/*   int nums[5] = {1,2,3,4,5}; */
/*   int nums2[2] = {3,4}; */
/*   print_int_arr(1,5,nums); */
/*   print_int_arr(1,2,nums2); */
/*   printf("%i\n",locate_seq(nums,5,nums2,2)); */
/*   return 0; */
/* } */
