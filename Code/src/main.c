#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "poly/poly.h"
#include "alpha/alpha.h"
#include "derivees/derivees.h"


void afficherTab(double* t, int n) {
    printf("{ ");
    for(int i=0; i<n; i++) {
        printf("%.16lf", t[i]);
        if(i != n-1) printf(", ");
    }
    printf(" }\n");
}


int main() {
    // creation du polynome Pn
    int deg;
    printf("Degré du polynôme: ");
    scanf("%u", &deg);
    assert(deg >= 0);

    polynome p = creerPoly(deg);
    remplirPoly(p);
    afficherPoly(p);

    // calculer Pn(alpha)
    double alpha;
    printf("alpha: ");
    scanf("%lf", &alpha);

    double* b = malloc(sizeof(double)*(deg+1));
    enAlpha(p, alpha, b);
    printf("P_n(%.16lf)=%.16lf\n", alpha, b[0]);
    afficherTab(b, deg+1);

    // calculer les n dérivées de Pn en alpha
    double* deriv = malloc(sizeof(double)*(deg+1));
    deriveesEnAlpha(p, b, deriv);
    afficherTab(deriv, deg+1);

    return 0;
}
