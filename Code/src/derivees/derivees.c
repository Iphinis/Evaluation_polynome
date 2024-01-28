#include "derivees.h"

#include <stdlib.h>

/*
* Retourner un tableau contenant 0!, 1!, ..., k!
* Paramètre : k (entier)
*/
int *fact(int k) {
    int *res = (int *) malloc(sizeof(int) * k + 1);
    res[0] = 1;
    for (int i = 1; i < k + 1; i++) {
        res[i] = res[i - 1] * i;
    }
    return res;
}

// TODO: corriger cette fonction qui est incorrecte
void deriveesEnAlpha(polynome p, double* b, double* deriv) {
    for(int i=0; i <= p.deg; i++) {
        deriv[i] = fact(i)*b[p.deg-i];
    }
}
