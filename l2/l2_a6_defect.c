#include <stdio.h>
#include <math.h>

/* This code used to have a defect, hence the name */

const double pi = 3.141592653; // the real mathematician's way to define irrational numbers

double cosine(double x){
  int i_max = 10e6;
  double cosine,sum = 1.; // sum <=> result, cosine = summand
  for(int i=1;i<i_max;i++){
    cosine = (-1.*x*x)/((2.*i)*((2.*i)-1.)) * cosine;
    sum +=cosine;
  }
  return sum;
}

int main(void){
  double x = pi;
  printf("cosine of %f is %f\n",x,cosine(x));
  return 0;}
