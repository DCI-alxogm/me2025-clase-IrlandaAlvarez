#include <stdio.h>
#include <math.h>

//Función
double funcion(double x) {
    return 2*sin(x)-pow(x,2)/10;
}

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
        x1 = xu - d * (xu - xl);
        x2 = xl + d * (xu - xl);
        
        // Función: f(x) = 2Sen(x)-x^2/10
        fx1 = funcion(x1);
        fx2 = funcion(x2);
        
        printf("%d\t%.6f\t%.6f\t%.6f\t%.6f\t%.6f\t%.6f\n", 
               iter, xl, xu, x1, x2, fx1, fx2);
        
        // Actualizar intervalo 
        if (fx1 > fx2) {
            xl = x1;
        } else {
            xu = x2;
        }
         //Parada
        if (fabs(xu - xl) < 0.0001) {
            break;
        }
    }
    
    // Resultado final
    raiz = (xl + xu) / 2.0;
    printf("\nLa raiz aproximada se encuentra en x = %.6f\n", raiz);
    printf("f(%.6f) = %.6f\n", raiz, (raiz * raiz) - 1);
    printf("Iteraciones realizadas: %d\n", iter);

    return 0;
}