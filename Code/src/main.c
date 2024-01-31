#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "poly/poly.h"
#include "alpha/alpha.h"
#include "matrices/matrice.h"
#include "derivees/derivees.h"
#include "renderer/renderer.h"

// TODO: bouger ces fonctions dans les fichiers c et h respectifs.

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


double lireAlpha() {
    double alpha;
    printf("Entrez alpha: ");
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


// Calcul des n dérivées de Pn en alpha
double* derivees(polynome p, double alpha, double* b) {
    double* deriv = malloc(sizeof(double)*(p.deg+1));
    deriveesEnAlpha(p, alpha, b, deriv);

    return deriv;
}


void AN1() {
    // Calcul de P6(2) avec algo de descente
    double **A;
    double *x;
    double *b2;

    A=creerMatrice(5);
    b2=creerVecteur(5);
    x=methodeDescente(A,b2,5);

    for (int i=0;i<5;i++){
    	printf("x[%d] = %lf\n",i,x[i]);
    }
}


int main() {
    /* TODO : selon le numéro de machine, lire les fichiers d'entrée, et écrire dans les fichiers de sortie

    // Numero de la machine (pour les fichiers d'entrée et de sortie)
    int machine;
    printf("Numéro de machine: ");
    scanf("%i", &machine);

    char output_file[100];
    snprintf(output_file, sizeof(output_file), "output/res_m%d.txt", machine);
    freopen(output_file, "w", stdout);
    */

    // Lire polynôme
    polynome p = lirePolynome();
    afficherPolynome(p);
    
    // Lire alpha
    double alpha = lireAlpha();
    double* b = NULL;

    double* deriv = NULL;

    char choix = 'q';

    do {
        printf("\n--- Choisissez une action ---\n");
        printf("r : afficher Pn\n");
        printf("p : entrer un autre polynôme Pn\n");
        printf("a : entrer un autre alpha\n");
        printf("h : calculer Pn(alpha) par la méthode de Horner\n");
        printf("d : calculer les dérivées de Pn en alpha\n");
        printf("6 : calculer P_6(2)\n");
        // ...
        printf("q : quitter\n");

        printf("Votre choix: ");
        scanf(" %c",&choix);
        getchar(); // Pour ne pas lire '\n'

        switch(choix) {
            case 'q':
                break;
            case 'p':
                p = lirePolynome();
                afficherPolynome(p);
                break;

            case 'r':
                /*
                TODO: corriger bug affichage intersection grille
                */
                tracerPolynome(p);
                break;

            case 'a':
                alpha = lireAlpha();
                break;

            case 'h':
                b = horner(p, alpha);
                printf("b : ");
                afficherVecteur(b, p.deg+1);
                break;

            case 'd':
                if(b != NULL) {
                    deriv = derivees(p, alpha, b);
                    printf("Dérivées : ");
                    afficherVecteur(deriv, p.deg+1);
                }
                else {
                    printf("Erreur: Il faut calculer les bj avec la commande 'a' avant de pouvoir calculer les dérivées de Pn en alpha\n");
                }
                break;
            
            case '6':
                AN1();
                break;

            default:
                printf("La commande '%c' est inconnue, veuillez réessayer\n", choix);
                break;
        }
    } while(choix != 'q');
    
    
    return 0;
}
