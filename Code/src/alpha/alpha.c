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


/*
Evaluation de Pn en alpha par la méthode de Clenshaw
Paramètres: alpha (double), b (tableau de taille n), n (int)
*/
double enAlphaC(double alpha, double* b, int n) {
	double c2,c3;
	c3 = b[n-1];
	c2 = b[n-2] + 2*alpha*c3;
	for (int i = n-1;i>=4;i--){
		c3=c2;
		c2=b[i-2]+2*alpha*c2-b[i];
	}
	return b[0] - c2 + (b[1]+2*alpha*c2-c3)*alpha;
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
