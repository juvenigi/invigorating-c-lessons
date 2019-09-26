#include <stdio.h>
#include <math.h>

int MAX = 1000;

double cosine(int i, double x){
  if( i > MAX )
    return 1;
  return 1-x*x/( (2*i-1)*2*i ) * cosine(i+1, x);
}
int main(void){
  double in = 4.*3.141592653;
  printf("cosine of: %f is %f\n",in,cosine(1,in));
  return 0;}
