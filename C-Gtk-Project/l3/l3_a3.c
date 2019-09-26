#include <stdio.h>
#include <math.h>


double m_power(double x, int n){ // x^n

  if(x==0&&n==0){
    return 0.;}
  if(n==0){
    return 1.;
  }
  if(n%2==0){
      return m_power(x*x,n/2);}
  else {
      return x * m_power(x*x,(n-1)/2);}
}

double naive_pow(double x, double n){
  double result = 1;
  for(double i=1.;i<=n;i++){
    result *= x;}
  return result;
}

int main(void){
  double a = 1.0 - 10.e-10;
  double  n = 2 * 10e9;
  printf("%f\n",naive_pow(a, n));

  return 0;
}
