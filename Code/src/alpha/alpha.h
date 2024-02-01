#ifndef ALPHA_H

#define ALPHA_H

#include <math.h>

#include "../poly/poly.h"

double enAlphaNaif(polynome p, double alpha);

double enAlpha(polynome p, double alpha, double* b);

double lireAlpha();

void afficherAlpha(double alpha);

#endif
