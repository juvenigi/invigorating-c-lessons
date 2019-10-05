#include <stdio.h>
#include<math.h>

/* advanced code written by an expert mathematician */


int main(){

double x,y;
x = 2;
y = 1;
double a;

scanf("%lf", &a);

YO:/*if(x-y<= 10e-10)
{printf("%f", x);
return 0;}
*/
if(fabs(y-x) <= 10e-10){
printf("%f", x);
return 0;
}

x = y;
y = (x + a/x)/2;

goto YO;

return 0;

}
