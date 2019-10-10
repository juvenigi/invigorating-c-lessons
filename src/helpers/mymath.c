#include <stdio.h>
#include <math.h>

#ifndef EULER
#define EULER
#define E 2.71828182845904523536
#endif /* EULER */

#ifndef BOOL
#define BOOL
typedef _Bool bool;
static const bool true = 1;
static const bool false = 0;
#endif /* BOOL */

#ifndef PI
#define PI 3.141592653
#endif /* PI */

int my_abs(int a){ // just use abs provided by math.h
  if(a<0){return 0-a;}
  else{return a;}
}

int gauss_up(double number){ // gauss_down is just normal typecasting
  if( (double) ((int) number) - number != 0 ){
   return (int) number + 1;
  }else{
    return (int) number;
  }
}

bool isprimep(int number){
  for(int n=2;n<sqrt((double) number);n++){
    if(number%n==0){return false;}
  }
  return true;
}

double logbase(double a_base, double value){
  return log(value)/log(a_base);
}

int commondiv(int a,int b){
  while (a!=0&&b!=0){
    if (a>b){a = a-b;}
    else{b = b-a;}
  }
  printf("result: ");
  if(a==0){return b;}
  else{return a;}
}

double rootbase(int wop, double value){
  double power = 1. / (double) wop;
  return pow(base,power);
}

/* double my_pow(double power, double value){} */

/* double naive_pow(){} */

/* double e_pow(){} */

/* unsigned int fac(unsigned int value){ */

/* } */

/* unsigned int naive_fac(unsigned int value){} */



/* double tricosinelaw(double tri_len_a, double tri_len_b){ */

/* } */


double * binomialsolve(double sq_coeff, double lin_coeff, double third_coeff){
  static double r_vals[2];
    for(int i=0;i<=1;i++){
      r_vals[i] = (-1.*lin_coeff + (2.*i-1)* sqrt(lin_coeff*lin_coeff-4.*sq_coeff*third_coeff))/(2.*sq_coeff);
    }
  return r_vals;
}

double ree_man(double s){
  double sum;
  int MAX_I= 10e5;
  for(int i=1;i<=MAX_I;i++){
    sum += pow(i,-1*s);
  }
  return sum;
}

int main(void){
  printf("%i\n",isprimep(2));
  printf("%i\n",isprimep(3));
  printf("%i\n",isprimep(15));
  printf("%i\n",isprimep(17));
  printf("%i\n",commondiv(20,10));
  printf("%i\n",commondiv(20,3));
  printf("%i\n",commondiv(18,24));
  return 0;
}
