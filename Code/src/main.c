#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "utils/utils.h"
#include "poly/poly.h"
#include "alpha/alpha.h"
#include "derivees/derivees.h"
#include "renderer/renderer.h"


int main() {
    // numero de la machine (pour les fichiers d'entrée et de sortie)
    int machine;
    scanf("%i", &machine);

    char output_file[100];
    snprintf(output_file, sizeof(output_file), "output/res_machine%d.txt", machine);
    freopen(output_file, "w", stdout);
    
    // creation du polynome Pn
    int deg;
    scanf("%u", &deg);
    assert(deg >= 0);

    polynome p = creerPolynome(deg);
    remplirPolynome(p);
    afficherPolynome(p);

    // calculer Pn(alpha)
    double alpha;
    scanf("%lf", &alpha);

    double* b = malloc(sizeof(double)*(deg+1));
    enAlpha(p, alpha, b);
    printf("P_n(%.16lf)=%.16lf\n", alpha, b[0]);
    afficherTab(b, deg+1);

    // calculer les n dérivées de Pn en alpha
    double* deriv = malloc(sizeof(double)*(deg+1));
    deriveesEnAlpha(p, b, deriv);
    afficherTab(deriv, deg+1);
    
    // AN : calcul de P6(2) avec algo de descente
    double **A;
    double *x;
    double *b2;
    printf("\n");
    printf("Veuillez entrer les coefficients de la matrice A :\n");
    A=creerMatrice(5);
    printf("\n");
    printf("Veuillez entrer les coefficients du vecteur b2 :\n");
    b2=creerVecteur(5);
    x=methodeDescente(A,b2,5);
    printf("\n");
    printf("Voici les valeurs des Cj :\n");
    for (int i=0;i<5;i++){
    	printf("x[%d] = %lf\n",i,x[i]);
    }

    int tracer = 1;
    scanf("%d", &tracer);
    if(tracer != 0) tracerPolynome(p);

    return 0;
}
