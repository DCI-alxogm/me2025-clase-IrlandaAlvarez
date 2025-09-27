//Problema 10
//Método Newton-Rhapson
//El mismo que el problema 3 pero ahora con 3 iteracciones y utlizando el Método de Newton
#include <stdio.h>
#include <math.h>

// Función f(h) = V(h) - 30
double f(double h) {
    double R = 3.0;
    double V = (3.1416 * h * h * (3.0 * R - h)) / 3.0;
    return V - 30.0;
}

// Derivada de f(h)
double df(double h) {
    double R = 3.0;
    return 3.1416 * (6.0 * h - h * h); // f'(h) = pi(6h - h²)
}

// Método de Newton-Raphson
void newton_raphson(double h0, int max_iter) {
    double h_actual = h0;
    double h_anterior;
    double error_relativo;
    
    printf("Iteración     h          f(h)         f'(h)       error Relativo\n");
    
    for (int i = 1; i <= max_iter; i++) {
        double fh = f(h_actual);
        double dfh = df(h_actual);
        
        h_anterior = h_actual;
        h_actual = h_anterior - fh / dfh;
        //En la primera iteracción no hay un valor anterior por lo que no se puede calcular el error relativo
        if (i == 1) {
            printf("%d      %6f   %6f   %6f    -\n", 
                   i, h_anterior, fh, dfh);
        } else {
            error_relativo = fabs((h_actual - h_anterior) / h_actual) * 100.0;
            printf("%d      %.6f   %.6f   %.6f    %.6f\n", 
                   i, h_anterior, fh, dfh, error_relativo);
        }
    }
    
    printf("\nSolución final: h = %.6f m\n", h_actual);
    printf("Volumen verificado: V(%.6f) = %.6f m^3\n", h_actual, f(h_actual) + 30.0);
}

int main() {
    double h0 = 2.0;  // Valor inicial
    int iteraciones = 3;
    
    printf("MÉTODO DE NEWTON-RAPHSON - Tanque esférico\n");
    printf("Objetivo: V(h) = 30 m^3, R = 3 m\n");
    printf("Valor inicial h0 = %.1f m\n\n", h0);
    
    newton_raphson(h0, iteraciones);
    
    return 0;
}