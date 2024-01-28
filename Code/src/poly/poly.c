#include "poly.h"

#include <stdio.h>
#include <stdlib.h>

polynome creerPoly(int deg) {
    polynome p;

    p.deg = deg;
    p.coeffs = malloc(sizeof(double)*(deg+1));

    return p;
}

void remplirPoly(polynome p) {
    for(int i=0; i <= p.deg; i++) {
        printf("Entrez le coefficient %d du polynôme: ", i);
        scanf("%lf", &p.coeffs[i]);
    }
}

void afficherPoly(polynome p) {
    printf("Polynome: ");
    for(int i=0; i <= p.deg; i++) {
        if(i == 0) printf("%.16lf", p.coeffs[i]);
        else printf("%.16lf*x^{%d}", p.coeffs[i], i);

        if(i < p.deg) printf(" + ");
    }
    printf("\n");
}