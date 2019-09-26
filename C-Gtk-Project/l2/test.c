#include <stdio.h>
#include <math.h>

int MAX = 100;

double cosine(int i, double x){
  if( i > MAX )
    return 1;
  return 1-x*x/( (2*i-1)*2*i ) * cosine(i+1, x);
}
int main(void){
  double in = 0.2;
  printf("cosine of: %f is %f\n",in,cosine(1,in));
  printf("cosine of: %f is %f\n",in,cosine(1,0));
  printf("cosine of: %f is %f\n",in,cosine(1,3.14));
  printf("cosine of: %f is %f\n",in,cosine(1,6.29));
  return 0;}
