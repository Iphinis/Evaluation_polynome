#include "matrice.h"

#include <stdio.h>
#include <stdlib.h>

/*
 * Créer une matrice carrée de taille n
 * Paramètre : n (entier)
 *
 * */
double **creerMatrice() {
    // initialisation
    double **A = (double **) malloc(sizeof(double *) * 5);
    for (int k = 0; k < 5; k++) {
        *(A + k) = (double *) malloc(sizeof(double) * 5);
    }

    // remplissage
    for (int i=0;i<5;i++){
    	for (int j=0;j<5;j++){
    		A[i][j]=0;
    	}
    }
    A[0][0]=1;
    A[1][1]=1;
    A[2][2]=1;
    A[3][3]=1;
    A[4][4]=1;
    A[2][0]=1;
    A[3][1]=1;
    A[4][2]=1;
    A[1][0]=-4;
    A[2][1]=-4;
    A[3][2]=-4;
    A[4][3]=-4;

    return A;
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
double *creerVecteur() {
    double *vecteur = (double *) malloc(sizeof(double) * 5);
    vecteur[0]=-4;
    vecteur[1]=1;
    vecteur[2]=0;
    vecteur[3]=0;
    vecteur[4]=-2.5;
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

void AN1() {
    // Calcul de P6(2) avec algo de descente
    double **A;
    double *x;
    double *b2;

    A=creerMatrice();
    b2=creerVecteur();
    x=methodeDescente(A,b2,5);

    for (int i=0;i<5;i++){
    	printf("x[%d] = %.16lf\n",i,x[i]);
    }
}
