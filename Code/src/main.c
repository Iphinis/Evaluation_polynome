#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "poly/poly.h"
#include "alpha/alpha.h"
#include "matrices/matrice.h"
#include "derivees/derivees.h"
#include "renderer/renderer.h"


int main() {
    // numero de la machine (pour les fichiers d'entrée et de sortie)
    int machine;
    scanf("%i", &machine);

    char output_file[100];
    snprintf(output_file, sizeof(output_file), "output/res_m%d.txt", machine);
    freopen(output_file, "w", stdout);
     
     
    // creation du polynome Pn
    int deg;
    scanf("%u", &deg);
    assert(deg >= 0);

    polynome p = creerPolynome(deg);
    remplirPolynome(p);
    printf("Pn : ");
    afficherPolynome(p);

    // calculer Pn(alpha) avec Horner
    double alpha;
    scanf("%lf", &alpha);

    printf("Naif : P_n(%.16lf)=%.16lf\n", alpha, enAlphaNaif(p, alpha));

    double* b = malloc(sizeof(double)*(deg+1));
    printf("Horner : P_n(%.16lf)=%.16lf\n", alpha, enAlpha(p, alpha, b));
    printf("b : ");
    afficherVecteur(b, deg+1);

    // Tracer le polynome Pn
    int tracer = 1;
    scanf("%d", &tracer);
    if(tracer != 0) tracerPolynome(p);


    // calculer les n dérivées de Pn en alpha
    double* deriv = malloc(sizeof(double)*(deg+1));
    deriveesEnAlpha(p, alpha, b, deriv);
    printf("Dérivées : ");
    afficherVecteur(deriv, deg+1);
    
    // AN : calcul de P6(2) avec algo de descente
    /*double **A;
    double *x;
    double *b2;
    A=creerMatrice(5);
    b2=creerVecteur(5);
    x=methodeDescente(A,b2,5);
    for (int i=0;i<5;i++){
    	printf("x[%d] = %lf\n",i,x[i]);
    }*/

    //libererFact();

    return 0;
}
