#include "derivees.h"

//int* fact;

/*
* Remplit le tableau de factorielles contenant 0!, 1!, ..., k!
* Paramètre : k (entier)
*/
/*void calculerFact(int k) {
    fact = malloc(sizeof(int) * (k + 1));

    fact[0] = 1;
    fact[1] = 1;

    for (int i = 2; i <= k; i++) {
        fact[i] = fact[i - 1] * i;
    }
}*/

/*
Libère les factorielles de la mémoire
*/
/*void libererFact() {
    free(fact);
}*/


// TODO: à optimiser, en stockant les valeurs de fact(n) dans un tableau de taille n+1 (de 0 à n), pour ne plus avoir à recalculer ces valeurs.
int fact(int k) {
    int res = 1;

    for(int i=2; i <= k; i++) res *= i;

    return res;
}


/*
* Calcule les dérivées de Pn évaluées en alpha
* Paramètres : p (polynome), alpha (double), b (tableau de taille p.deg + 1), deriv (tableau de taille p.deg + 1)
*/
void deriveesEnAlpha(polynome p, double alpha, double* b, double* deriv) {
    // Calcul des Rj
    double* r = calloc(p.deg+1, sizeof(double));

    int n = p.deg;

    r[n] = b[0];

    for(int j=n-1; j >= 0; j--) {
        for(int i=n-j; i <= n; i++) {
            r[j] += p.coeffs[j]*fact(i-n+j)/fact(n-j)*pow(alpha, i-n+j);
        }
    }
    
    // Calcul des dérivées de Pn en alpha
    for(int j=0; j <= n; j++) {
        deriv[j] = fact(j)*b[n-j];
    }
}
