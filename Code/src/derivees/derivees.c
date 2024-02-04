#include "derivees.h"


/*
* Remplit le tableau de factorielles contenant 0!, 1!, ..., n!
* Au premier appel de la fonction, le tableau statique 'calculated' est initialisé.
* Le tableau 'calculated' contiendra toutes les valeurs calculées.
* Paramètre : n (entier)
*/
int calculerFact(int n) {
    static int saved_fac = 1;
    static int first_call = 1;
    static int *calculated;

    if (first_call) {
        calculated = malloc(sizeof(int) * 2);
        calculated[0] = 1;
        calculated[1] = 1;
        first_call = 0;
    }

    if (n > saved_fac) {
        calculated = realloc(calculated, n + 1);
        for (int i = saved_fac + 1; i <= n; i++) {
            calculated[i] = i * calculated[i - 1];
        }
        saved_fac = n;
    }
    
    return calculated[n];
}


/*
* Calcule les dérivées de Pn évaluées en alpha
* Paramètres : p (polynome), alpha (double), b (tableau de taille p.deg + 1), deriv (tableau de taille p.deg + 1)
*/
void deriveesEnAlpha(polynome p, double alpha, double* b, double* deriv) {
    // Calcul des Rj
    int n = p.deg;
    double* r = calloc(n+1, sizeof(double));

    r[n] = b[0];
    
    for(int j=n-1; j >= 0; j--) {
        for(int i=n-j; i <= n; i++) {
            r[j] += p.coeffs[i]*(calculerFact(i)/(calculerFact(n-j)*calculerFact(i-n+j))) * pow(alpha,i-n+j);
        }
    }
    
    // Calcul des dérivées de Pn en alpha
    for(int j=0; j <= n; j++) {
        deriv[n-j] = calculerFact(n-j)*r[j];
    }
}

