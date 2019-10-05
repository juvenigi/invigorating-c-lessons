#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define MPI 3.14156

typedef struct _complex{
  double real;
  double imag;
} COMPLEX;

COMPLEX cplx_add(COMPLEX a, COMPLEX b){
  double res_real = a.real + b.real;
  double res_im = a.imag + b.imag;
  COMPLEX result;
  result.real = res_real;
  result.imag = res_im;
  return result;
}

COMPLEX cplx_mul(COMPLEX a, COMPLEX b){
  double res_real = a.real * b.real - a.imag * b.imag;
  double res_im = a.real * b.imag + a.imag * b.real;
  COMPLEX result = {res_real, res_im};
  return result;
}
COMPLEX cplx_pow(COMPLEX a, unsigned long b){ //NOTE: probably doesn't work or isn't optimal
  double abssq = a.real*a.real + a.imag*a.imag;
  double res_real = a.real*a.real/abssq * cos(b)*cos(b);
  double res_im = a.imag*a.imag/abssq * sin(b)*sin(b);
  COMPLEX result = {sqrt(abssq)*sqrt(res_real),sqrt(abssq)*sqrt(res_im)};
  return result;
}
COMPLEX cplx_div(COMPLEX a, COMPLEX b){
  double realb;
  if(!b.real){realb = b.real;} // 0
  else {realb = 1./b.real;}
  double imb = -1.*b.imag;
  COMPLEX binv = {realb,imb};
  COMPLEX result = cplx_mul(a,binv);
  return result;
}

int main(void){
  COMPLEX this;
  this.real = 0.;
  this.imag = 1.;
  COMPLEX that;
  that.real = 0.;
  that.imag = 1.;
  unsigned long these = 3;
  COMPLEX add = cplx_add(this,that);
  COMPLEX mul = cplx_mul(this,that);
  COMPLEX div = cplx_div(this,that);
  printf("%f %f\n",add.real,add.imag);
  printf("%f %f\n",mul.real,mul.imag);
  printf("%f %f\n",div.real,div.imag);
  return 0;
}
