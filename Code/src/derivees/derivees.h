#ifndef DERIVEES_H

#define DERIVEES_H

#include <stdlib.h>
#include <math.h>

#include "../poly/poly.h"

int *calculerFact(int k);

void libererFact(int *fact);

int fact(int k);

void deriveesEnAlpha(polynome p, double alpha, double* b, double* deriv);


#endif
