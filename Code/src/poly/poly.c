#include "poly.h"

#include <stdio.h>
#include <stdlib.h>

polynome creerPolynome(int deg) {
    polynome p;

    p.deg = deg;
    p.coeffs = malloc(sizeof(double)*(deg+1));

    return p;
}

void remplirPolynome(polynome p) {
    for(int i=0; i <= p.deg; i++) {
        printf("Coefficient du degré %d : ",i);
        scanf("%lf", &p.coeffs[i]);
    }
}

void afficherPolynome(polynome p) {
    printf("Pn : ");
    for(int i=0; i <= p.deg; i++) {
        if(i == 0) printf("%.16lf", p.coeffs[0]);
        else if (i == 1) printf("%.16lf*X", p.coeffs[1]);
        else printf("%.16lf*X^{%d}", p.coeffs[i], i);

        if(i < p.deg) printf(" + ");
    }
    printf("\n");
}

polynome lirePolynome() {
    // Creation du polynome Pn
    int deg;
    printf("Degré de Pn: ");
    scanf("%u", &deg);
    assert(deg >= 0);

    polynome p = creerPolynome(deg);
    remplirPolynome(p);

    return p;
}

double* horner(polynome p, double alpha) {    
    // Calcul naïf de Pn en alpha
    // printf("Naif : P_n(%.16lf)=%.16lf\n", alpha, enAlphaNaif(p, alpha));

    // Calculer de Pn en alpha avec Horner
    double* b = malloc(sizeof(double)*(p.deg+1));
    printf("Horner : P_n(%.16lf)=%.16lf\n", alpha, enAlpha(p, alpha, b));

    return b;
}
