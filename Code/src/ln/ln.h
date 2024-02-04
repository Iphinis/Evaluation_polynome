#ifndef LN_H
#define LN_H

#include <math.h>

#define abs(x) (x >= 0 ? x : -x)

/*
* Algorithme de calcul approché de la valeur ln(10 + 6x) avec une erreur absolue strictement inférieure à 10^-4
* Paramètre : -1 <= x <= 1
* Valeur de retour : valeur approchée de ln(10 + 6x)
*/
double calcul_ln(double x);

/*
* Validation de la précision
* Paramètres : 
*   - val_th : valeur théorique
*   - val_empirique : valeur approchée
* Valeur de retour : 1 si la précision est suffisante (strictement inférieure à 10^-4), 0 sinon.
*/
int verif_prec(double val_th, double val_empirique);

#endif
