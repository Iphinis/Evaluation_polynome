#ifndef POLY_H

#define POLY_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct polynome {
    int deg;
    double* coeffs;
} polynome;

polynome creerPolynome(int deg);

void remplirPolynome(polynome p, int mode);

void afficherPolynome(polynome p);

polynome lirePolynome(int mode);

double* horner(polynome p, double alpha);

#endif
