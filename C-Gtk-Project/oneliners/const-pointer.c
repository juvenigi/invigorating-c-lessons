#include <stdio.h>
int main(void)
{
  int i = 10;
  int j = 20;
  /* ptr is pointer to constant */
  const int *ptr = &i;

  printf("ptr: %d\n", *ptr);
  /* error: object pointed cannot be modified
     using the pointer ptr */
  *ptr = 100;

  ptr = &j;		 /* valid */
  printf("ptr: %d\n", *ptr);

  return 0;
}
