#include <stdio.h>  /* for printf */
#include <string.h> /* for strchr */

/* inspired by: https://en.wikipedia.org/wiki/Function_pointer
 */

double meters_to_demeters(double m) {
	return m * 2;
}

int main(void) {
	double (*func1)(double) = meters_to_demeters;
	char * (*func2)(const char *, int) = strchr; // no need to declare strchr
	printf("%f %s", func1(15.0), func2("Waifupedia\n", 'i')); // prints "7.5" fupedia"
	return 0;
}
