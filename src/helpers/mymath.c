#include <stdio.h>
#include <math.h>

#ifndef EULER
#define EULER
#define E 2.71828182845904523536
#endif /* EULER */

#ifndef PI
#define PI 3.141592653
#endif /* PI */

#ifndef BOOL
#define BOOL
typedef _Bool bool;
static const bool true = 1;
static const bool false = 0;
#endif /* BOOL */

#ifndef M_PRECISION
#define M_PRECISION 10e-8
#endif /* M_PRECISION */

#ifndef M_I_MAX
#define M_I_MAX 10e6
#endif /* I_MAX */

int my_abs(int a){ // just use abs provided by math.h
  if(a<0){return 0-a;}
  else   {return a;}
}

int sgn(double value){
  if(value<0){
    return -1.;
  }if(value>0){
    return 1;
  }else{
    return 0;
  }
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
    else    {b = b-a;}
  }
  if(a==0){return b;}
  else    {return a;}
}

double rootbase(int wop, double value){
  double power = 1. / (double) wop;
  return pow(value,power);
}

double mag(double a, double b){ //magnitude
  if(a>b){
    return a-b;
  }else{
    return b-a;
  }
}

double m_sqrt(double value){
  double x,y = 1.;
  while(mag(x,y)>M_PRECISION){
    x = y;
    y = (x+(value/x))/2;
  }
  return x;
}

long double recur_pow(long double x, long unsigned int n){
  // Format the ouput using "%.Le"
  if(x==0 && n==0){
    return 0.;
  }if(n==0){
    return 1.;
  }if(n%2 == 0){
    return recur_pow(x*x,n/2);
  }else{
    return x * recur_pow(x*x,(n-1)/2);}
}

long double naive_pow(long double x, long unsigned int power){
  if(x==0||power==0){
    return 0.;
  }
  for(int i = 1; i<power;i++){
    x *= x;
  }
  return x;
}

double m_exp(double x){
  double prev = 1.;
  double result = 1.;
  for(int i=1;i<=M_I_MAX;i++){
    prev = (prev*x)/(i);
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

double e_pow(double value, double power){
  return exp(power * log(value)); // e^ln(x) = x -> e^2*ln(x) = x^2
}

unsigned int naive_fac(unsigned int value){
  unsigned int result = 1;
  for(int i = value; i>1; i--){
    result *= i;
  }
  return result;
}

unsigned int naive_rec_fac(unsigned int value){
  if(value==0){return 1;}
  return value * naive_rec_fac(value-1);
}

double tricosinelaw(double tri_len_a, double tri_len_b, double cg_angle){
  return sqrt( pow(tri_len_a,2) + pow(tri_len_b,2) - 2*tri_len_b*tri_len_a*cos(cg_angle) );
}


double * binomialsolve(double a, double b, double c){
  static double r_vals[2];
    for(int i=0;i<=1;i++){
      r_vals[i] = ((-1. * b
                    + (2. * i - 1)  // plus-minus sign
                    * sqrt(b * b - 4. * a * c)) // determinant
                   / (2. * a));
    }
  return r_vals;
}

double cosine(double x){
  int i_max = M_I_MAX;
  double summand,result = 1.;
  for(int i=1;i<i_max;i++){
    summand = (-1.*x*x)/((2.*i)*((2.*i)-1.)) * summand; // done explicitly to avoid integer overflow
    result += summand;
  }
  return result;
}

double ree_man(double s){
  double sum;
  int MAX_I= 10e5;
  for(int i=1;i<=MAX_I;i++){
    sum += pow(i,-1*s);
  }
  return sum;
}

void swap(int * a, int * b){
  int t = *a;
  *a = *b;
  *b = t;
}

int count_range(int s, int f){ //NOTE: bugtest
  if(f-s<0){swap(&s,&f);} //FIXME: implement value swapper
  int len = f - s + 1;
  int i = len/2; // integer division important
  if(len % 2 == 1){
    return (f+s)*i+(i+s);
  }else{
    return (f+s)*i;
  }
}

double newton_method(double (*fun)(double), double (*der_fun)(double), double x_value){
  // determine error size
  double newton_it = x_value - fun(x_value) / der_fun(x_value);
  double error = fabs(fun(x_value));
  //printf( "\033[31m debug: error:%f x:%f\033[0m\n",error,x_value); // debug
  fflush(stdout);
  if(error < M_PRECISION){
    return newton_it;
  }
  x_value = newton_it;
  return newton_method(fun, der_fun, x_value);
}

int main(void){ //FIXME: should not exist!
  printf("%i\n",isprimep(2));
  printf("%i\n",isprimep(20));
  printf("%i\n",isprimep(7));
  printf("%f\n",tricosinelaw(3.,4.,PI/2.));
  printf("%Lf\n",recur_pow(4.0,2));
  printf("%Lf\n",naive_pow(4.0,2));
  long double extreme = 1.-10e-10;
  printf("%.Le\n",extreme);
  printf("%.Le\n",recur_pow(1.-10e-10,2e10));
  printf("%.Le\n",naive_pow(1.-10e-10,2e10));
  return 0;
}
