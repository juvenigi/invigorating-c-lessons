#ifndef MY_COMPLEX_H
#define MY_COMPLEX_H

typedef struct _complex COMPLEX;

COMPLEX cplx_add(COMPLEX a, COMPLEX b);
COMPLEX cplx_mul(COMPLEX a, COMPLEX b);
COMPLEX cplx_pow(COMPLEX a, unsigned long b);
COMPLEX cplx_div(COMPLEX a, COMPLEX b);

#endif /* MY_COMPLEX_H */
