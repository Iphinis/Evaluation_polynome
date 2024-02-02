#include "poly.h"

polynome creerPolynome(int deg) {
    polynome p;

    p.deg = deg;
    p.coeffs = malloc(sizeof(double)*(deg+1));

    return p;
}

void remplirPolynome(polynome p, int mode) {
    for(int i=0; i <= p.deg; i++) {
        printf("Coefficient du degré %d : ",i);
        scanf("%lf", &p.coeffs[i]);
        if(mode == 1) printf("%.16lf\n", p.coeffs[i]);
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

polynome lirePolynome(int mode) {
    // Creation du polynome Pn
    int deg;
    printf("Degré de Pn: ");
    scanf("%u", &deg);
    assert(deg >= 0);
    if(mode == 1) printf("%d\n", deg);

    polynome p = creerPolynome(deg);
    remplirPolynome(p, mode);

    return p;
}
