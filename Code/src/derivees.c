#include "derivees.h"

// TODO: à optimiser, en stockant les valeurs de fact(n) dans un tableau de taille n+1 (de 0 à n), pour ne plus avoir à recalculer ces valeurs.
int fact(int k) {
    int res = 1;

    for(int i=2; i <= k; i++) res *= i;

    return res;
}

// TODO: corriger cette fonction qui est incorrecte
void deriveesEnAlpha(polynome p, double* b, double* deriv) {
    for(int i=0; i <= p.deg; i++) {
        deriv[i] = fact(i)*b[p.deg-i];
    }
}
