#include <stdio.h>
//#include <string.h>
#include <math.h>

double absol(double a, double b){
  if(a>b){
    return a-b;}
  else{
    return b-a;};
}

int main(void){
  double a = 2.;
  //double x = 2;
  double x,y = 1;
  while(absol(x,y)>10e-8){
    printf("debug: abs: %f\n",absol(x,y));
    x = y;
    y = (x+(a/x))/2;
    printf("debug: a=%f x=%f y=%f\n",a,x,y);
  };
  printf("%f\n",x);
  return 0;
}
