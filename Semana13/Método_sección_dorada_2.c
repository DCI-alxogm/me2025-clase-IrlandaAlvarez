#include <stdio.h>
#include <math.h>

int main() {
    double x1, x2, fx1, fx2;
    double xl, xu; 
    double d;
    double raiz;
    int iter;               
    int max_iter = 100;                 

    printf("Metodo de la sección dorada (proporcion aurea)\n");

    printf("\nIngrese el valor de xl: ");
    scanf("%lf", &xl);
    printf("\nIngrese el valor de xu: ");
    scanf("%lf", &xu); 

    d = (sqrt(5)-1)/2;  
    
    printf("\nIter\txl\t\txu\t\tx1\t\tx2\t\tf(x1)\t\tf(x2)\n");
    printf("------------------------------------------------------------------------\n");
    
    for(iter = 0; iter < max_iter; iter++) {
        x1 = xl + d * (xu - xl);
        x2 = xu - d * (xu - xl);
        
        // Función: f(x) = x^2 - 1
        fx1 = (x1 * x1) - 1;
        fx2 = (x2 * x2) - 1;
        
        printf("%d\t%.6f\t%.6f\t%.6f\t%.6f\t%.6f\t%.6f\n", iter, xl, xu, x1, x2, fx1, fx2);
        if (fx1 > fx2) {
            xl = x1;
        } else {
            xu = x2;
        }
        
    }
    
    // Resultado final
    raiz = (xl + xu) / 2.0;
    printf("\nLa raiz aproximada se encuentra en x = %.6f\n", raiz);
    printf("f(%.6f) = %.6f\n", raiz, (raiz * raiz) - 1);
    printf("Iteraciones realizadas: %d\n", iter);

    return 0;
}