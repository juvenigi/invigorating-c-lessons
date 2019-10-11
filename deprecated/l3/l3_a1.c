#include <stdio.h>
//#include <string.h>
#include <math.h>

//missing: wurzel primtest ggt


int sgn(double value){
  if(value<0){
    return -1.;
  }
  if(value>0){
    return 1;
  }
  else {
    return 0;}}

double betrag(double val){
  if (0.>val){val=0.-val;}
  return val;
}

int main(void){
  double a = 2.;
  double b = -3.;
  double n = 0.;

  printf("%f %i\n",a,sgn(a));
  printf("%f %i\n",b,sgn(b));
  printf("%f %i\n",n,sgn(n));
  printf("%f %f\n",b,betrag(b));
  printf("%f %f\n",n,betrag(n));
  return 0;
}
