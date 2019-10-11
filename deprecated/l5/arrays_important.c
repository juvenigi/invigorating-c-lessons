#include <stdio.h>
#define MY_ARRAY_LENGTH 10 //the virgin way
#define ARR_LEN(x) (sizeof((x)) / sizeof((x)[0])) // the alpha chad way

/* TLDR: You cannot have a function like: array_length(int * array){...}

   In C, a pointer to an array cannot be used to
   determine array size. You either need to put the array
   size into the array itself, or always define array size as
   a variable somewhere in your code, the latter happens quite often.
 */

void arr_printarr(int * in_array, int length){
  for(int i=0;i<length;i++){
    printf("%i ",in_array[i]);
  }
  printf("\n");
}

int main(){
  int myray[10] = { 5, 7, 10, 20, -2, -4, 5, 0, -20, 42};
  int myray_length = ARR_LEN(myray); // WON'T WORK with pointer-pointers

  int * myray4 = myray; // will be used for a demonstration

  arr_printarr(myray,myray_length);
  printf("%i\n\n",myray_length);

  printf("%i\n",(int) sizeof(myray)/sizeof(myray[0])); // basically what the macro does
  printf("%i\n",(int) sizeof(myray[0])); // size of the first element
  printf("%i\n\n",(int) sizeof(myray));  // size of element * number of elements = array size

  /* we can simulate the effect of a shitty function by defining a pointer to an array pointer
     as you can see from the return values, it's wrong (but it gets the element size right!)
   */
  printf("%i\n",(int) sizeof(myray4)/sizeof(myray4[0]));
  printf("%i\n",(int) sizeof(myray4[0])); // it's the same, huh?
  printf("%i\n\n",(int) sizeof(myray4));

  /* TLDR: Java is better and FORTRAN is the best */

  return 0;
}
