#include "derivees.h"


/*
* Remplit le tableau de factorielles contenant 0!, 1!, ..., k!
* Paramètre : k (entier)
*/
int *calculerFact(int k) {
    int *fact = (int *) malloc(sizeof(int) * (k + 1));

    fact[0] = 1;
    fact[1] = 1;
    for (int i = 2; i <= k; i++) {
        fact[i] = fact[i - 1] * i;
    }
    return fact;
    
}

/*
Libère les factorielles de la mémoire
*/
void libererFact(int *fact) {
    free(fact);
}


/*
* Calcule les dérivées de Pn évaluées en alpha
* Paramètres : p (polynome), alpha (double), b (tableau de taille p.deg + 1), deriv (tableau de taille p.deg + 1)
*/
void deriveesEnAlpha(polynome p, double alpha, double* b, double* deriv) {
    // Calcul des Rj
    int n = p.deg;
    double* r = calloc(n+1, sizeof(double));
   
    int * fact;
    fact=calculerFact(n);

    r[n] = b[0];
    
    for(int j=n-1; j >= 0; j--) {
        for(int i=n-j; i <= n; i++) {
            r[j] += p.coeffs[i]*(fact[i]/(fact[n-j]*fact[i-n+j]))* pow(alpha,i-n+j);
        }
    }
    
    // Calcul des dérivées de Pn en alpha
    for(int j=0; j <= n; j++) {
        deriv[n-j] = fact[n-j]*r[j];
    }
}
