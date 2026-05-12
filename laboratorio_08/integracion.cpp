#include "integracion.h"

double trapecioCompuesto(double fx[], int n, double h) {

    double suma = fx[0] + fx[n];

    for (int i = 1; i < n; i++) {

        suma += 2 * fx[i];
    }

    return (h / 2.0) * suma;
}

double simpsonCompuesto(double fx[], int n, double h) {

    if (n % 2 != 0) {
        return -1;
    }

    double suma = fx[0] + fx[n];

    for (int i = 1; i < n; i++) {

        if (i % 2 != 0) {
            suma += 4 * fx[i];
        }

        else {
            suma += 2 * fx[i];
        }
    }

    return (h / 3.0) * suma;
}