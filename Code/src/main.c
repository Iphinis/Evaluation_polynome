// importation des librairies de gestion de fichiers
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>

// importation des autres librairies
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

// importation des fichiers d'en-tête du projet
#include "poly/poly.h"
#include "alpha/alpha.h"
#include "matrices/matrice.h"
#include "derivees/derivees.h"
#include "renderer/renderer.h"


/*
definirEntree : rediriger stdin vers un fichier de données
Paramètre: nom_fonction (string)
*/
void definirEntree(char* nom_fonction) {
    char input_file[200];
    snprintf(input_file, sizeof(input_file), "input/donnees_%s.txt", nom_fonction);

    // Rediriger stdin
    FILE *savedStdin = freopen(input_file, "r", stdin);

    if (savedStdin == NULL) {
        fprintf(stderr, "Erreur lors de la redirection de stdin vers %s\n", input_file);
        exit(EXIT_FAILURE);
    }
}


/*
definirSortie : rediriger stdout vers un fichier de résultat
Paramètres: nom_fonction (chaine de caractères), machine (entier)
*/
void definirSortie(char* nom_fonction, int machine) {
    char output_file[200];
    snprintf(output_file, sizeof(output_file), "output/m%d/res_%s_m%d.txt", machine, nom_fonction, machine);

    char directory[200];
    snprintf(directory, sizeof(directory), "output/m%d/", machine);

    // Vérifier si le répertoire existe, sinon le créer
    struct stat st;
    if (stat(directory, &st) != 0) {
        // Si le répertoire n'existe pas, le créer
        if (mkdir(directory, 0777) != 0) {
            fprintf(stderr, "Erreur lors de la création du répertoire %s\n", directory);
            exit(EXIT_FAILURE);
        }
    }

    // Rediriger stdout
    FILE *savedStdout = freopen(output_file, "w", stdout);

    if (savedStdout == NULL) {
        fprintf(stderr, "Erreur lors de la redirection de stdout vers %s\n", output_file);
        exit(EXIT_FAILURE);
    }
}


/*
Mode automatique : lire et écrire dans les fichiers d'input/output selon le numéro de la machine
Paramètre: machine (entier)
*/
void modeAutomatique(int machine) {
    // Approche naïve
    definirEntree("naives");
    definirSortie("naives", machine);

    polynome p = lirePolynome(1);
    afficherPolynome(p);

    tracerPolynome(p);

    double alpha = lireAlpha(1);

    printf("Naif : P_n(%.16lf) = %.16lf\n", alpha, enAlphaNaif(p, alpha));


    // Méthode de Horner
    double* b = (double*) malloc(sizeof(double) * (p.deg+1));
    printf("Horner : P_n(%.16lf) = %.16lf\n", alpha, enAlpha(p, alpha, b));
    printf("b : ");
    afficherVecteur(b, p.deg+1);


    // Calcul des dérivées successives
    definirEntree("deriv");
    definirSortie("deriv", machine);

    double* deriv = (double*) malloc(sizeof(double) * (p.deg+1));
    deriveesEnAlpha(p, alpha, b, deriv);
    printf("Dérivées : ");
    afficherVecteur(deriv, p.deg+1);

    // Méthode de Clenshaw
    definirEntree("AN_P6_2");
    definirSortie("AN_P6_2", machine);

    AN1(alpha,p.deg+1);


    // Calcul de ln(10+6x)
    definirEntree("res6");
    definirSortie("res6", machine);

    double b6[7]={log(9),2/3,-1/9,2/81,-1/162,2/1215,-1/2187};
    double res6 = enAlphaC(alpha,b6,7);
    printf("La valeur de ln(10+6*%lf) = %.16lf\n", alpha, res6);


    // Calcul de (10+x)/(101+20x)
    definirEntree("res7");
    definirSortie("res7", machine);

    double b7[8] = {1/10,-1/100,1/1000,-1/10000,1/100000,-1/1000000,1/10000000,-1/100000000};
    double res7 = enAlphaC(alpha,b7, 8);
    printf("La valeur de (10+6*%lf)/(101+20%lf) = %.16lf\n", alpha, alpha, res7);
}


/*
Mode manuel : interaction homme-machine pour manipuler les fonctions mises en places en direct
*/
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

        printf("t : calculer Pn(alpha) par la méthode de descente\n");
        printf("c : calculer Pn(alpha) par la méthode de Clenshaw\n");

        printf("6 : calculer ln(10+6x) par la méthode de Clenshaw\n");
        printf("7 : calculer 10+6x par la méthode de Clenshaw\n");

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
                //tracerPolynome(p);
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
            
            case 't':
                int n2;
                printf("Entrez le degré dans la base de Tchebychev :\n");
                scanf("%d",&n2);
                AN1(alpha, n2);
                break;
            
            case 'c':
                int n3;
                printf("Entrez le degrédans la base de Tchebychev :\n");
                scanf("%d",&n3);
                double *bc;
                double resc;
                bc=creerVecteur(n3);
                resc = enAlphaC(alpha,bc,n3);
                printf("res = %.16lf\n",resc);
                break;
            
            case '6':
                double b6[7]={log(9),2/3,-1/9,2/81,-1/162,2/1215,-1/2187};
                double res6;
                res6 = enAlphaC(alpha,b6,7);
                printf("La valeur de ln(10+6*%lf) = %.16lf\n",alpha,res6);
                break;
            
            case '7':
                double b7[8] = {1/10,-1/100,1/1000,-1/10000,1/100000,-1/1000000,1/10000000,-1/100000000};
                double res7;
                res7 = enAlphaC(alpha,b7,8);
                printf("La valeur de (10+6*%lf)/(101+20%lf) = %.16lf\n",alpha,alpha,res7);
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
    
    return EXIT_SUCCESS;
}
