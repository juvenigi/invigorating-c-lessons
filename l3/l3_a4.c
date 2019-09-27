#include <stdio.h>
#include <math.h>

const double ee = 2.71828182846;

double expo(double x){
  double prev = 1.;
  double result = 1.;
  for(int i=1;i<=10e5;i++){
    prev = (prev*x)/(i);
    //printf("%f\n",prev);
    result +=prev;
  }
  return result;
}
double m_ln(double x){
  double prev = ((x-1.)/(x+1.)); // not gonna work if x -1 = 0
  double result = prev;
  for(int i=1;i<=150;i++){
    prev = prev * ((x-1.)/(x+1.))*((x-1.)/(x+1.))*((2.*i-1)/(2.*i+1.));
    //printf("%f\n",prev);
    result += prev;
  }
  return 2.*result;
}
double superpow(double x, double y){
  return expo(y*m_ln(x));
}
int main(void){
  printf("%f\n",m_ln(expo(2.)));
  printf("%f\n",m_ln(expo(3.)));
  printf("%f\n",log(expo(2.)));
  printf("%f\n",superpow(2.,2.));
  return 0;
}
