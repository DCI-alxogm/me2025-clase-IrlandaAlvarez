#include <stdio.h>
#include <math.h>

// Función original: f(x) = -x^2 + 4x
double funcion(double x) {
    return -pow(x, 2) + 4*x;
}

// Primera derivada: f'(x) = -2x + 4
double derivada1(double x) {
    return -2*x + 4;
}

// Segunda derivada: f''(x) = -2
double derivada2(double x) {
    return -2;
}

int main() {
    double x_actual, x_siguiente;
    double f_actual, f_siguiente;
    // Primera y segunda derivada
    double f1, f2;  
    int iter;
    int max_iter = 100;
    double epsilon = 0.0001;

    printf("Metodo de Newton\n");
    printf("Funcion: f(x) = -x^2 + 4x\n");
    printf("Ingrese el punto inicial x0: ");
    scanf("%lf", &x_actual);

    printf("\nIter\tx_actual\tf(x)\t\tf'(x)\t\tf''(x)\t\tx_siguiente\n");
    printf("----------------------------------------------------------------------------\n");

    for(iter = 0; iter < max_iter; iter++) {
        f_actual = funcion(x_actual);
        f1 = derivada1(x_actual); 
        f2 = derivada2(x_actual);  
        
        if(fabs(f2) < 1e-10) {
            printf("Error: Segunda derivada cero\n");
            break;
        }
        
        x_siguiente = x_actual - f1 / f2;
        f_siguiente = funcion(x_siguiente);
        
        printf("%d\t%.6f\t%.6f\t%.6f\t%.6f\t%.6f\n", 
               iter, x_actual, f_actual, f1, f2, x_siguiente);
        
        //Convergencia
        if(fabs(x_siguiente - x_actual) < epsilon) {
            printf("Convergencia alcanzada\n");
            break;
        }
        
        x_actual = x_siguiente;
    }
    
   //Resultado final
    printf("Maximo en: x = %.6f\n", x_actual);
    printf("Valor de la funcion: f(%.6f) = %.6f\n", x_actual, funcion(x_actual));
    printf("Valor de f'(x) en el punto: %.6f \n", derivada1(x_actual));
    printf("Iteraciones: %d\n", iter);
    
    return 0;
}