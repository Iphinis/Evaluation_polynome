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
definirEntree : rediriger le flux stdin vers un fichier de données
Paramètre: nom_fonction (chaine de caractères)
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
definirSortie : rediriger le flux stdout vers un fichier de résultat
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
    definirEntree("naif");
    definirSortie("naif", machine);

    polynome p = lirePolynome(1);
    afficherPolynome(p);
    //tracerPolynome(p);

    double alpha = lireAlpha(1);

    printf("Naif : P_n(%.16lf) = %.16lf\n", alpha, enAlphaNaif(p, alpha));


    // Méthode de Horner et dérivées
    definirEntree("hd_5_3.2");
    definirSortie("hd_5_3.2", machine);

    p = lirePolynome(1);
    afficherPolynome(p);

    // Calcul de Pn(alpha) par Horner
    double* b = (double*) malloc(sizeof(double) * (p.deg+1));
    printf("Horner : P_n(%.16lf) = %.16lf\n", alpha, enAlpha(p, alpha, b));
    printf("b : ");
    afficherVecteur(b, p.deg+1);

    // Calcul des dérivées successives
    double* deriv = (double*) malloc(sizeof(double) * (p.deg+1));
    deriveesEnAlpha(p, alpha, b, deriv);
    printf("Dérivées : ");
    afficherVecteur(deriv, p.deg+1);


    // Méthode de Horner et dérivées
    definirEntree("hd_6_-5.1");
    definirSortie("hd_6_-5.1", machine);

    p = lirePolynome(1);
    afficherPolynome(p);
    //tracerPolynome(p);

    // Calcul de Pn(alpha) par Horner
    double* b2 = (double*) malloc(sizeof(double) * (p.deg+1));
    printf("Horner : P_n(%.16lf) = %.16lf\n", alpha, enAlpha(p, alpha, b2));
    printf("b : ");
    afficherVecteur(b2, p.deg+1);

    // Calcul des dérivées successives
    double* deriv2 = (double*) malloc(sizeof(double) * (p.deg+1));
    deriveesEnAlpha(p, alpha, b2, deriv2);
    printf("Dérivées : ");
    afficherVecteur(deriv2, p.deg+1);


    // AN : Méthode descente
    definirEntree("AN_P6_2_d");
    definirSortie("AN_P6_2_d", machine);

    p = lirePolynome(1);
    afficherPolynome(p);
    //tracerPolynome(p);

    alpha = lireAlpha(1);
    
    double **A=creerMatrice(alpha,p.deg-1);
    double *bc2 = creerVecteur(p.deg-1, 1);
    double *c=methodeDescente(A,bc2,p.deg-1);
    double *bcr=creerVecteur(2,1);
    printf("res = %.16lf\n", bcr[1]-c[p.deg-2]+(bcr[0]+2*alpha*c[p.deg-2]-c[p.deg-3])*alpha);


    // AN : Méthode de Clenshaw
    definirEntree("AN_P6_2_c");
    definirSortie("AN_P6_2_c", machine);

    p = lirePolynome(1);
    afficherPolynome(p);
    //tracerPolynome(p);

    alpha = lireAlpha(1);

    double *bc = creerVecteur(p.deg+1, 1);
    printf("res = %.16lf\n", enAlphaC(alpha, bc, p.deg+1));


    // Calcul de ln(10+6x)
    definirEntree("ln_0.2");
    definirSortie("ln_0.2", machine);

    alpha = lireAlpha(1);

    double b6[7]={log(9),2./3,-1./9,2./81,-1./162,2./1215,-1./2187};
    double res6 = enAlphaC(alpha,b6,7);
    printf("La valeur de ln(10+6*%.16lf) = %.16lf\n", alpha, res6);


    definirEntree("ln_0.1");
    definirSortie("ln_0.1", machine);

    alpha = lireAlpha(1);

    res6 = enAlphaC(alpha,b6,7);
    printf("La valeur de ln(10+6*%.16lf) = %.16lf\n", alpha, res6);


    definirEntree("ln_1");
    definirSortie("ln_1", machine);

    alpha = lireAlpha(1);

    res6 = enAlphaC(alpha,b6,7);
    printf("La valeur de ln(10+6*%.16lf) = %.16lf\n", alpha, res6);


    // Calcul de (10+x)/(101+20x)
    definirEntree("10x_-0.7");
    definirSortie("10x_-0.7", machine);

    alpha = lireAlpha(1);

    double b4[5] = {1./10,-1./100,1./1000,-1./10000,1./100000};
    double res4 = enAlphaC(alpha,b4,5);
    printf("La valeur de (10+6*%.16lf)/(101+20*%.16lf) = %.16lf\n", alpha, alpha, res4);


    definirEntree("10x_0.2");
    definirSortie("10x_0.2", machine);

    alpha = lireAlpha(1);

    res4 = enAlphaC(alpha,b4,5);
    printf("La valeur de (10+6*%.16lf)/(101+20*%.16lf) = %.16lf\n", alpha, alpha, res4);
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
            
            case 'c':
                int n3;
                printf("Entrez le degré dans la base de Tchebychev :\n");
                scanf("%d",&n3);
                double *bc;
                double resc;
                bc=creerVecteur(n3, 2);
                resc = enAlphaC(alpha,bc,n3);
                printf("res = %.16lf\n",resc);
                break;
            
            case '6':
                double b6[7]={log(9),2/3,-1/9,2/81,-1/162,2/1215,-1/2187};
                double res6;
                res6 = enAlphaC(alpha,b6,7);
                printf("La valeur de ln(10+6*%.16lf) = %.16lf\n",alpha,res6);
                break;
            
            case '7':
                double b7[8] = {1/10,-1/100,1/1000,-1/10000,1/100000,-1/1000000,1/10000000,-1/100000000};
                double res7;
                res7 = enAlphaC(alpha,b7,8);
                printf("La valeur de (10+6*%.16lf)/(101+20%.16lf) = %.16lf\n",alpha,alpha,res7);
                break;

            default:
                printf("La commande '%c' est inconnue, veuillez réessayer\n", choix);
                break;
        }
    } while(choix != 'q');
}


/*
Fonction main : point d'entrée du programme.
Description : Le programme peut fonctionner en deux modes distincts : automatique ou manuel.
    - En mode automatique, l'utilisateur doit fournir uniquement le numéro de la machine (k). Le programme va lire les données depuis le dossier "input/" et écrire les résultats des instructions dans le dossier "output/mk/", où mk est le numéro de la machine spécifiée.
    - En mode manuel, l'utilisateur peut interagir avec le programme en temps réel via une interface en ligne de commande. Aucune lecture ni écriture de fichiers n'est effectuée. Ce mode est principalement utilisé pour tester les fonctionnalités du programme.
Entrées : Aucune entrée requise.
Sorties : Le programme renvoie 0 en cas de succès.
*/
int main() {
    int mode;
    printf("Veuillez lire le README pour comprendre les cas d'utilisation des différents modes\n");
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
