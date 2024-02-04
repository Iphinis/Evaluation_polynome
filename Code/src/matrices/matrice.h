#ifndef MATRICES_H
#define MATRICES_H

double **creerMatrice(double alpha, int n);

void afficherMatrice(double **matrice, int n);

double *creerVecteur(int n);

void afficherVecteur(double *vecteur, int n);

double *methodeDescente(double **matrice, double *b, int n);

double *multiplicationMatriceVect(double **matrice, double *x, int n);

void AN1(double alpha, int n);

#endif
