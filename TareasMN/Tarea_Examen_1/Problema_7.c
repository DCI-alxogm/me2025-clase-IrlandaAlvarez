//Problema 7
//Método bisección 
//ln(osf) = -139.34 + 1.575701e5/Ta - 6.642309e7/Ta^2 + 8.621949e11/Ta^4

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//Función para la ecuación APHA 
double rhs(double Ta) {
    double Ta2 = Ta * Ta;
    double Ta4 = Ta2 * Ta2;
    return -139.34 + 1.575701e5 / Ta - 6.642309e7 / Ta2 + 8.621949e11 / Ta4;
}

// f(Ta) = RHS(Ta) - ln(osf_given), raiz: f(Ta) = 0 
double f(double Ta, double osf) {
    return rhs(Ta) - log(osf); /* log = ln (naturaleza) */
}

int main(void) {
    double osf;
    printf("Ingrese la concentración de saturación de O2 (mg/L): ");
    if (scanf("%lf", &osf) != 1) {
        fprintf(stderr, "Entrada inválida.\n");
        return 1;
    }
    if (osf <= 0.0) {
        fprintf(stderr, "La concentración debe ser mayor a 0.\n");
        return 1;
    }

    //Itervalo incial en Kelvin
    double a = 273.15;
    double b = 373.15;
    //Funciones con los intervalos inciales y la concetración de O2
    double fa = f(a, osf);
    double fb = f(b, osf);

    //Si no hay signos diferentes, expandimos el intervalo
    int expansión = 0;
    while (fa * fb > 0.0 && expansión < 10) {
        //Expandir 50 K por cada lado, pero sin bajar de 1 K 
        a = (a > 51.0) ? a - 50.0 : 1.0;
        b = b + 50.0;
        fa = f(a, osf);
        fb = f(b, osf);
        expansión++;
    }

    if (fa * fb > 0.0) {
        fprintf(stderr, "No se encontró cambio de signo en el intervalo inicial expandido\n");
        fprintf(stderr, "Prueba con otra concentración\n");
        return 1;
    }

    //Parámetros de la bisección 
    int max_iter = 1000;
    double tol_K = 1e-6;
    //mid=punto medio actualizado
    double mid = 0.0, fmid;
    double prev_mid = NAN;
    double approx_error = NAN;

    printf("\nIter |     a(K)    |     b(K)    |     mid(K)   |   mid(°C)   |   f(mid)\n");
    printf("-----------------------------------------------------------------------------\n");

    int k;
    for (k = 1; k <= max_iter; ++k) {
        mid = 0.5 * (a + b);
        fmid = f(mid, osf);

        printf("%4d | %10.6f | %10.6f | %10.6f | %10.6f | %12.6e\n",
               k, a, b, mid, mid - 273.15, fmid);

        //Comprobar la convergencia
        if ( (b - a) / 2.0 < tol_K ) {
            break;
        }

        //Si los signos son distintos
        if (fa * fmid <= 0.0) {
            b = mid;
            fb = fmid;
        } else {
            a = mid;
            fa = fmid;
        }
        prev_mid = mid;
    }
    printf("Iteraciones realizadas: %d\n", k);
    printf("Temperatura aproximada: Ta = %.6f K  (%.6f °C)\n", mid, mid - 273.15);
    printf("f(Ta) = %.6e\n", fmid);

    return 0;
}