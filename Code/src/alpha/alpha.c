#include "alpha.h"

void enAlpha(polynome p, double alpha, double* b) {
    b[p.deg] = p.coeffs[p.deg];

    for(int j=p.deg - 1; j >= 0; j--) {
        b[j] = p.coeffs[j] + alpha*b[j+1];
    }
}

