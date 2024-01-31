#ifndef POLY_H

#define POLY_H


typedef struct polynome {
    int deg;
    double* coeffs;
} polynome;

polynome creerPolynome(int deg);

void remplirPolynome(polynome p);

void afficherPolynome(polynome p);

#endif
