#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "poly/poly.h"
#include "alpha/alpha.h"
#include "matrices/matrice.h"
#include "derivees/derivees.h"
//#include "renderer/renderer.h"

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
        printf("n : calculer Pn(alpha) de manière naïve\n");
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
                //tracerPolynome(p);
                break;

            case 'a':
                alpha = lireAlpha();
                break;

            case 'n':
                double res;
                res = enAlphaNaif(p, alpha);
                printf("P_n(%.16lf) = %.16lf de manière naïve",alpha,res);
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
