#include <stdio.h>
#include <math.h>

//#include "mymath.h"



/* double m_log_a(double a_base, double value){ */

/* } */

/* unsigned int m_fac(unsigned int value){ */

/* } */

/* double m_inv_pot(double value, int power_m1){ */

/* } */

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
