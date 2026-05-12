#include <iostream>
#include <cmath>

#include "integracion.h"
#include "funciones.h"

using namespace std;

int main() {

    int n;

    cout << "Ingrese el numero de subintervalos: ";
    cin >> n;

    if (n <= 0) {
        cout << "n debe ser mayor que 0." << endl;
        return 1;
    }

    double a = 0.0;
    double b = 1.0;

    double h = (b - a) / n;

    double* x = new double[n + 1];
    double* fx = new double[n + 1];

    for (int i = 0; i <= n; i++) {

        x[i] = a + i * h;
        fx[i] = f(x[i]);
    }

    double trapecio = trapecioCompuesto(fx, n, h);

    double simpson = 0.0;

    if (n % 2 == 0) {
        simpson = simpsonCompuesto(fx, n, h);
    }

    double exacto = M_PI;

    double errorTrapecio = fabs(exacto - trapecio);

    cout << endl;
    cout << "Integral de 4/(1+x^2) en [0,1]" << endl;

    cout << "Trapecio compuesto: "
         << trapecio << endl;

    if (n % 2 == 0) {

        double errorSimpson = fabs(exacto - simpson);

        cout << "Simpson compuesto: "
             << simpson << endl;

        cout << "Valor exacto: "
             << exacto << endl;

        cout << "Error trapecio: "
             << errorTrapecio << endl;

        cout << "Error Simpson: "
             << errorSimpson << endl;

    } else {

        cout << "Simpson compuesto no se puede aplicar." << endl;
        cout << "n debe ser par." << endl;

        cout << "Valor exacto: "
             << exacto << endl;

        cout << "Error trapecio: "
             << errorTrapecio << endl;
    }

    delete[] x;
    delete[] fx;

    return 0;
}