#include "matrice.h"

#include <stdio.h>
#include <stdlib.h>

/*
 * Crée une matrice carrée de taille nxn en demandant à l'utilisateur chacun des coefficients de la matrice
 * Paramètre : n (entier)
 *
 * */
double **creerMatrice(double alpha, int n) {
    // initialisation
    double **A = (double **) malloc(sizeof(double *) * n);
    for (int k = 0; k < n; k++) {
        *(A + k) = (double *) malloc(sizeof(double) * n);
    }

    // remplissage
    for (int i=0;i<n;i++){
    	for (int j=0;j<n;j++){
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
    A[1][0]=-2*alpha;
    A[2][1]=-2*alpha;
    A[3][2]=-2*alpha;
    A[4][3]=-2*alpha;

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
 * Crée un vecteur à n composantes en les demandant à l'utilisateur
 * Paramètre : n (entier)
 *
 * */
double *creerVecteur(int n, int mode) {
    double *vecteur = (double *) malloc(sizeof(double) * n);
    double v;

    for (int i=0;i<n;i++){
    	if(mode == 2) printf("Coefficient %d :\n",i);
    	scanf("%lf",&v);
    	vecteur[i]=v;
    }

    return vecteur;
}

/*
 * Afficher un vecteur de dimension n
 * Paramètres : vecteur (double *), n (entier)
 * 
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