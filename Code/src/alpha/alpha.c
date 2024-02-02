#include "alpha.h"


/*
Evaluation naïve de Pn en alpha
Paramètres: p (polynome), alpha (double)
Sortie: Pn(alpha)
*/
double enAlphaNaif(polynome p, double alpha) {
    double resultat = 0.0;

    for (int i = 0; i <= p.deg; ++i) {
        resultat += p.coeffs[i] * pow(alpha,i);
    }

    return resultat;
}

/*
Evaluation de Pn en alpha par la méthode de Horner
Paramètres: p (polynome), alpha (double), b (tableau de taille p.deg + 1)
*/
double enAlpha(polynome p, double alpha, double* b) {
    b[p.deg] = p.coeffs[p.deg];

    for(int j=p.deg - 1; j >= 0; j--) {
        b[j] = p.coeffs[j] + alpha*b[j+1];
    }

    return b[0];
}

double lireAlpha(int mode) {
    double alpha;
    if(mode == 2) printf("Entrez alpha: ");
    scanf("%lf", &alpha);

    return alpha;
}

void afficherAlpha(double alpha) {
    printf("alpha: %.16lf\n", alpha);
}

double* horner(polynome p, double alpha) {    
    // Calcul naïf de Pn en alpha
    // printf("Naif : P_n(%.16lf)=%.16lf\n", alpha, enAlphaNaif(p, alpha));

    // Calculer de Pn en alpha avec Horner
    double* b = malloc(sizeof(double)*(p.deg+1));
    printf("Horner : P_n(%.16lf)=%.16lf\n", alpha, enAlpha(p, alpha, b));

    return b;
}
