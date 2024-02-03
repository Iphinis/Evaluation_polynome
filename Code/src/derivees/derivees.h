#ifndef DERIVEES_H

#define DERIVEES_H

#include <stdlib.h>
#include <math.h>

#include "../poly/poly.h"

int calculerFact(int n);

void libererFact(int *fact);

int fact(int k);

void deriveesEnAlpha(polynome p, double alpha, double* b, double* deriv);

double* derivees(polynome p, double alpha, double* b);


#endif
