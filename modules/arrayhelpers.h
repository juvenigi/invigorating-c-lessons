#ifndef ARRAY_HELPERS
#define ARRAY_HELPERS



void initarray(int ** pointer,int length);

void print_int_arr(int mode, int arr_len, int * array);

void setintarr(int * array, int array_length, int value);

int iwrap(int n, int array_length);

void shiftarr_swapper_pos(int * array, int array_length, int rot_k);

void shiftarr(int * array, int array_length, int rot_k);

void fliparr(int * array, int array_length);

int locate_seq(int * array, int array_length, int * array_seq, int array_seq_length);

#endif /* ARRAYHELPERS_H*/

#ifndef _ARRAY_INIT
#define _array_init(_x,_len,_t) (_t) * (_x) =((_t) *) malloc(sizeof(_t) * (_len))
#endif /* ARRAY_INIT */
