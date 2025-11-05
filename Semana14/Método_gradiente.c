#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double funcion(double x, double y)
{
   return 2*x*y + 2*x - x*x - 2*y*y;
}

int main()
{
    // Método del gradiente 
    double x = -1, y = 1, dfdx, dfdy, dx, dy;
    int iter = 1000, i;
    double h = 0.1;  // Tasa de aprendizaje

    printf("%s  %s  %s  %s  %s  %s  %s\n", 
           "Iter", "x", "y", "f(x,y)", "df/dx", "df/dy", "Convergencia");

    for (i = 0; i < iter; i++)
    {
        dx = 0.01;
        dy = 0.01;
        // Cálculo de derivadas parciales
        dfdx = (funcion(x + dx, y) - funcion(x - dx, y)) / (2 * dx);
        dfdy = (funcion(x, y + dy) - funcion(x, y - dy)) / (2 * dy);
       
        // Norma del gradiente para convergencia
        double convergencia = sqrt(dfdx * dfdx + dfdy * dfdy);
        
        printf("%d  %.6f  %.6f  %.6f  %.6f  %.6f  %.6f\n", 
               i + 1, x, y, funcion(x, y), dfdx, dfdy, convergencia);

        // Verificar convergencia
        if (convergencia < 0.00001) {
            printf("Convergencia final en iteración: %d\n", i + 1);
            break;
        }
        
        //Valores nuevos
        double x_nuevo = x + h * dfdx;  
        double y_nuevo = y + h * dfdy;  

        // Actualizar para siguiente iteración
        x = x_nuevo;
        y = y_nuevo;
    }
    
    // Resultado final
    printf("Punto óptimo: (%.6f, %.6f)\n", x, y);
    printf("Valor óptimo: f(x,y) = %.6f\n", funcion(x, y));
    return 0;
}