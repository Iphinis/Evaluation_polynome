#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "poly/poly.h"
#include "alpha/alpha.h"
#include "matrices/matrice.h"
#include "derivees/derivees.h"
#include "renderer/renderer.h"


/*
Mode automatique : lire et écrire dans les fichiers d'input/output selon le numéro de la machine
Paramètre: machine (entier)
*/
int modeAutomatique(int machine) {
    // Définir l'entrée
    char input_file[100];
    snprintf(input_file, sizeof(input_file), "input/donnees_m%d.txt", machine);
    FILE *savedStdin = freopen(input_file, "r", stdin);

    if (savedStdin == NULL) {
        fprintf(stderr, "Erreur lors de la redirection de stdin vers %s\n", input_file);
        return EXIT_FAILURE;
    }

    // Définir la sortie
    char output_file[100];
    snprintf(output_file, sizeof(output_file), "output/res_m%d.txt", machine);
    FILE *savedStdout = freopen(output_file, "w", stdout);

    if (savedStdout == NULL) {
        fprintf(stderr, "Erreur lors de la redirection de stdout vers %s\n", input_file);
        return EXIT_FAILURE;
    }

    // Actions
    polynome p = lirePolynome(1);
    afficherPolynome(p);

    double alpha = lireAlpha(1);
    double* b = (double*) malloc(sizeof(double) * (p.deg+1));;
    double* deriv = (double*) malloc(sizeof(double) * (p.deg+1));;

    tracerPolynome(p);

    alpha = lireAlpha(1);

    double res;
    res = enAlphaNaif(p, alpha);
    printf("Naif : P_n(%.16lf) = %.16lf\n", alpha, res);

    printf("Horner : P_n(%.16lf) = %.16lf\n", alpha, enAlpha(p, alpha, b));
    printf("b : ");
    afficherVecteur(b, p.deg+1);

    deriveesEnAlpha(p, alpha, b, deriv);
    printf("Dérivées : ");
    afficherVecteur(deriv, p.deg+1);

    AN1();

    return EXIT_SUCCESS;
}

void modeManuel() {
    // Lire polynôme
    polynome p = lirePolynome(2);
    afficherPolynome(p);
    
    // Lire alpha
    double alpha = lireAlpha(2);
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
                p = lirePolynome(2);
                afficherPolynome(p);
                break;

            case 'r':
                tracerPolynome(p);
                break;

            case 'a':
                alpha = lireAlpha(2);
                break;

            case 'n':
                double res;
                res = enAlphaNaif(p, alpha);
                printf("Naif : P_n(%.16lf) = %.16lf\n",alpha,res);
                break;
            
            case 'h':
                if(b != NULL) {
                    free(b);
                    b = NULL;
                }
                else b = (double*) malloc(sizeof(double) * (p.deg+1));

                printf("Horner : P_n(%.16lf) = %.16lf\n", alpha, enAlpha(p, alpha, b));
                printf("b : ");
                afficherVecteur(b, p.deg+1);
                break;

            case 'd':
                if(b != NULL) {
                    if(deriv != NULL) {
                        free(deriv);
                        deriv = NULL;
                    }
                    else deriv = (double*) malloc(sizeof(double) * (p.deg+1));

                    deriveesEnAlpha(p, alpha, b, deriv);
                    printf("Dérivées : ");
                    afficherVecteur(deriv, p.deg+1);
                }
                else {
                    printf("Erreur: Il faut calculer b avec la méthode de Horner (commande 'h') avant de pouvoir calculer les dérivées de Pn en alpha\n");
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
}

int main() {
    int mode;
    printf("Veuillez lire la documentation pour comprendre les cas d'utilisation des différents modes\n");
    printf("Choisissez le mode d'utilisation (1 pour automatique, 2 pour manuel): ");
    scanf("%i", &mode);

    switch (mode)
    {
        case 1:
            int machine;
            printf("Numéro de machine: ");
            scanf("%i", &machine);
            modeAutomatique(machine);
            break;
        
        case 2:
            modeManuel();
            break;
        
        default:
            printf("Mode non reconnu. Fin du programme.\n");
            return 1;
            break;
    }    
    
    return 0;
}
