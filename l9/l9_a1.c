#include <stdio.h>
#include <math.h>


// imperfect hacky solution, adds an unnecessary blank symbol just for a fancy color
#define RED     "\033[31m"      /* Red */
#define RESET   "\033[0m"

// simple quadtratic function

double f(double x){
  return (x-2.)*x;
}

// g(x) is the derivative of f(x)

double g(double x){
  return 2.*x; // mind the datatype
}



double newton_method(double (*fun)(double), double (*der_fun)(double), double x_value){

  // determine error size
  double newton_it = x_value - fun(x_value) / der_fun(x_value);
  double error = fabs(fun(x_value));
  printf( "\033[31m debug: error:%f x:%f\033[0m\n",error,x_value); // debug
  fflush(stdout);
  if(error < 10e-5){
    return newton_it;
  }
  x_value = newton_it;
  return newton_method(fun, der_fun, x_value);
}

int main(void){
  double newton = newton_method(&f,&g,4.);
  printf("the root of the equation is: %f",newton);

}
