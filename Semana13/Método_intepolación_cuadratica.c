#include <stdio.h>
#include <math.h>

// Función f(x) = x^2 - 1
double funcion(double x) {
    return (x * x) - 1;
}

int main() {
    double x0, x1, x2;    
    double f0, f1, f2;    
    double x3;            
    double f3;
    int iter;
    int max_iter = 100;
    double epsilon = 0.0001;

    printf("Metodo de Interpolacion Cuadratica\n");

    printf("Ingrese los tres puntos iniciales:\n");
    printf("x0: "); scanf("%lf", &x0);
    printf("x1: "); scanf("%lf", &x1);
    printf("x2: "); scanf("%lf", &x2);

    printf("\nIter\tx0\t\tx1\t\tx2\t\tx3\t\tf(x3)\n");
    printf("----------------------------------------------------------------\n");

    for(iter = 0; iter < max_iter; iter++) {
        f0 = funcion(x0);
        f1 = funcion(x1);
        f2 = funcion(x2);
        
        double numerador = f0 * (x1*x1 - x2*x2) + f1 * (x2*x2 - x0*x0) + f2 * (x0*x0 - x1*x1);
        double denominador = 2 * (f0 * (x1 - x2) + f1 * (x2 - x0) + f2 * (x0 - x1));
        
        // Calcular x3 (nuevo punto)
        x3 = numerador / denominador;
        f3 = funcion(x3);
        
        printf("%d\t%.6f\t%.6f\t%.6f\t%.6f\t%.6f\n", 
               iter, x0, x1, x2, x3, f3);
        
        if(f3 > f1) {  
            if(x3 > x1) {
                x2 = x1;
                x1 = x3;
            } else {
                x0 = x1;
                x1 = x3;
            }
        } else {
            if(x3 > x1) {
                x0 = x3;
            } else {
                x2 = x3;
            }
        }
        
        // Criterio de parada
        if(fabs(f3) < epsilon || fabs(x2 - x0) < epsilon) {
            break;
        }
    }
    
    printf("\n=== RESULTADO FINAL ===\n");
    printf("Punto máximo: x = %.6f\n", x3);
    printf("f(%.6f) = %.6f\n", x3, f3);
    printf("Iteraciones: %d\n", iter);
    
    return 0;
}