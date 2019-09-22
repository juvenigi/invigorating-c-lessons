#include <stdio.h>

/* Lesson one: incrementation is actually voodoo magic */

int main () {
  int lies = 1;
  printf("lies is equal to: %i\n",lies);

  // boolean operations don't compute incrementations, apparently
  if (lies-- == 1)
    printf("you are not supposed to see this!\n");

  // but the value is actually decremented!
  if (lies == 1)
    printf("you will not see this message!\n");

  lies++; // this is because lies++ is equivalent to lies = lies + 1 or lies += 1

  if (lies == 1)
    printf("now you see me!\n");

  if (lies-1 == 1) // note that this does not modify the value of lies
    printf("now you don't\n");

  if (lies == 1)
    printf("lies is still equal to: %i\n",lies);
  return 0;
}
