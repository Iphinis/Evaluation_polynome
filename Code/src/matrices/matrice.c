#include "matrice.h"

#include <stdio.h>
#include <stdlib.h>

/*
 * Créer une matrice carrée de taille n
 * Paramètre : n (entier)
 *
 * */
double **creerMatrice(int n) {
    // initialisation
    double **matrice = (double **) malloc(sizeof(double *) * n);
    for (int k = 0; k < n; k++) {
        *(matrice + k) = (double *) malloc(sizeof(double) * n);
    }

    // remplissage
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            double coeff;
            scanf("%lf", &coeff);
            matrice[i][j] = coeff;
        }
    }

    return matrice;
}

/*
 * Afficher une matrice de taille n
 * Paramètres : matrice, n (entier)
 *
 * */
void afficherMatrice(double **matrice, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%.16lf", matrice[i][j]);
        }
        printf("\n");
    }
}

/*
 * Creer un vecteur à n composantes
 * Paramètre : n (entier)
 *
 * */
double *creerVecteur(int n) {
    double *vecteur = (double *) malloc(sizeof(double) * n);
    for (int i = 0; i < n; i++) {
        printf("%d-ieme composante : \n", i);
        scanf("%lf", vecteur + i);
    }
    return vecteur;
}

/*
 * Afficher un vecteur de dimension n
 * Paramètres : vecteur (double *), n (entier)
 * */
void afficherVecteur(double *vecteur, int n) {
    printf("{ ");
    for(int i=0; i<n; i++) {
        printf("%.16lf", vecteur[i]);
        if(i != n-1) printf(", ");
    }
    printf(" }\n");
}

/*
 * Resoudre un système linéaire par la methode de descente
 * Paramètres : matrice (triangulaire inférieure), n (entier)
 *
 * */
double *methodeDescente(double **matrice, double *b, int n) {
    double *solution = (double *) malloc(sizeof(double) * n);
    for (int i = 0; i < n; i++) {
        *(solution + i) = *(b + i);
        for (int k = 0; k < i; k++) {
            *(solution + i) = *(solution + i) - *(*(matrice + i) + k) * *(solution + k);
        }
        *(solution + i) = *(solution + i) / *(*(matrice + i) + i);
    }
    return solution;
}

/*
 * Mutliplier une matrice par un vecteur
 * Paramètres : matrice, vecteur, n (entier)
 *
 * */
double *multiplicationMatriceVect(double **matrice, double *x, int n) {
    double *solution = (double *) malloc(sizeof(double) * n);
    double bi;
    for (int i = 0; i < n; i++) {
        bi = 0;
        for (int j = 0; j < n; j++) {
            bi = bi + *(*(matrice + i) + j) * *(x + j);
        }
        *(solution + i) = bi;
    }
    return solution;
}