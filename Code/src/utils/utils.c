#include "utils.h"

#include <stdio.h>

void afficherTab(double* t, int n) {
    printf("{ ");
    for(int i=0; i<n; i++) {
        printf("%.16lf", t[i]);
        if(i != n-1) printf(", ");
    }
    printf(" }\n");
}

void ajouterSortie(char* chemin, char* contenu) {
    FILE* fichier = fopen(chemin, "a");

    if (fichier != NULL) {
        fputs(contenu, fichier);

        if(fclose(fichier) != 0) {
            fprintf(stderr, "Erreur lors de la fermeture de %s", chemin);
        }
    } else {
        fprintf(stderr, "Erreur lors de l'ouverture de %s", chemin);
    }
}

void supprimerSortie(char* chemin) {
    if (remove(chemin) != 0) {
        fprintf(stderr, "Erreur lors de la suppression de %s", chemin);
    }
}