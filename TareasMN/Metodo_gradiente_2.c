#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//Función
double funcion(double *x, int n)
{
    if (n == 2) {
        return 2*x[0]*x[1] + 2*x[0] - x[0]*x[0] - 2*x[1]*x[1];
    }
    return 0;
    
}

int main()
{
    int dimension = 2;  // Aquí podemos cambiar la dimensión 
    double x[10] = {-1, 1}; 
    double h = 0.1; 
    
    double grad[10], x_nuevo[10];
    int iter = 1000, i, j;
    double dx = 0.01;

    printf("Iter");
    for (j = 0; j < dimension; j++) printf("  x%d", j);
    printf("  f(x)");
    for (j = 0; j < dimension; j++) printf("  df/dx%d", j);
    printf("  Convergencia\n");

    for (i = 0; i < iter; i++)
    {
        // Cálculo del gradiente con diferencias finitas
        for (j = 0; j < dimension; j++) {
            double temp = x[j];
            
            x[j] = temp + dx;
            double f_plus = funcion(x, dimension);
            
            x[j] = temp - dx;
            double f_minus = funcion(x, dimension);
            
            x[j] = temp;  // restaurar valor
            grad[j] = (f_plus - f_minus) / (2 * dx);
        }
       
        // Norma del gradiente para convergencia
        double convergencia = 0;
        for (j = 0; j < dimension; j++) {
            convergencia += grad[j] * grad[j];
        }
        convergencia = sqrt(convergencia);
        

        printf("%d", i + 1);
        for (j = 0; j < dimension; j++) printf("  %.6f", x[j]);
        printf("  %.6f", funcion(x, dimension));
        for (j = 0; j < dimension; j++) printf("  %.6f", grad[j]);
        printf("  %.6f\n", convergencia);

        //Convergencia
        if (convergencia < 0.00001) {
            printf("Convergencia final en iteración: %d\n", i + 1);
            break;
        }
        
        //Actualizar posición
        for (j = 0; j < dimension; j++) {
            x_nuevo[j] = x[j] + h * grad[j];
        }
        
        //Copiar nuevos valores
        for (j = 0; j < dimension; j++) {
            x[j] = x_nuevo[j];
        }
    }
    
    //Resultados
    printf("Punto óptimo: (");
    for (j = 0; j < dimension; j++) {
        printf("%.6f", x[j]);
        if (j < dimension-1) printf(", ");
    }
    printf(")\n");
    
    printf("Valor óptimo: f(x) = %.6f\n", funcion(x, dimension));
    return 0;
}