#ifndef ALPHA_H

#define ALPHA_H

#include <math.h>
#include <stdio.h>

#include "../poly/poly.h"

double enAlphaNaif(polynome p, double alpha);

double enAlpha(polynome p, double alpha, double* b);

double enAlphaC(double alpha, double* b, int n);

double lireAlpha(int mode);

void afficherAlpha(double alpha);

#endif
