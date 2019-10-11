#include<stdio.h>
#include<stdlib.h>
#include"array_helpers.h"

#define _intarray_init(ex,elen) int * (ex) = malloc(sizeof(int) * (elen))

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
  for(int i=0+!(!(mode));i<arr_len;i++){
    printf("%i",array[i]);
    if(mode){printf(", ");}else{printf("\n");}
  }
  if(mode){printf("%i,\n",array[arr_len-1]);}
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
  for(int i = 0; i<array_length;i++){
    arr_ind = i;
    if(array[i]==array_seq[0]){
      for(int i = 0; i<array_seq_length; i++){
        if(array[i+arr_ind] != array_seq[i]){return -1;}
      }
      return arr_ind;
    }
  }

  return -1;

}
int main(void){
  //int toast[3] = {1,2,3};
  int * arrpointer;
  int * arr2 = initarray2(6);
  initarray(&arrpointer,3);
  //arrpointer = {1,2,3};
  arrpointer[0] = 2;
  printf("%i\n",arrpointer[0]);
  //printarr(0,3,arrpointer);


  int nums[5] = {1,2,3,4,5};
  int nums2[2] = {2,3};
  printarr(1,5,nums);
  printarr(1,2,nums2);
  //arrot_k(nums,5,1);
  //printarr(1,5,nums);
  //arrot_k(nums,5,-2);
  //printarr(1,5,nums);
  //arflip(nums,5);
  //printarr(1,5,nums);
  printf("%i\n",locate_seq(nums,5,nums2,2));
  return 0;
}
