#ifndef POLY_H

#define POLY_H

typedef struct polynome {
    int deg;
    double* coeffs;
} polynome;

polynome creerPoly(int deg);

void remplirPoly(polynome p);

void afficherPoly(polynome p);

#endif