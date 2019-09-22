#include <stdio.h>
#include <string.h>

int main(void){
  static char s1[] = "this is a string!";
  static char s2[] = " this is also a string!";
  printf("%s %s \n",s1,s2); // you don't need strcat to do that!
  return 0;
}
