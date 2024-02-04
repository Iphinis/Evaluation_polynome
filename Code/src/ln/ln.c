#include "ln.h"

double calcul_ln(double x) {
    double res = log(9);
    for (int k = 1; k <= 6; k++) {
        res = res - 2 * pow(-1, k) / (k * pow(3, k)) * cos(k * acos(x));
    }
    return res;
}

int verif_prec(double val_th, double val_empirique) {
    return abs(val_th - val_empirique) < 1e-4;
}