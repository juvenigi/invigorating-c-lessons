#include <stdio.h>
#include <math.h>

const double pi = 3.141592653;

double cosine(double x){
  int i_max = 10e6;
  double cosine,sum = 1; // sum = result, cosine = summand bei k = 0
  //double sum = 1;
  //double cosine_prev;
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
