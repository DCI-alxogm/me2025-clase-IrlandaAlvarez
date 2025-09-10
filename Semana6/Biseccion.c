#include <stdio.h>
#include <math.h>

int main() {
    double fa, fb, fk;
    // Valores de la función en los extremos y en el punto medio
    double a, b, c;           
    double error_actual, error_deseado, c_anterior;  
    double g = 9.81, m = 68.1, v = 40, t = 10; 
    int iteracion;                
    int max_iter = 100;                 

    printf("Metodo de Biseccion\n");
    printf("Funcion: f(c) = (g*m/c) * (1 - exp(-c*t/m)) - v\n");
    printf("Busqueda de raiz en un intervalo [a, b]\n\n");

    printf("Ingrese el valor inicial a: ");
    scanf("%lf", &a); 
    printf("Ingrese el valor inicial b: ");
    scanf("%lf", &b);    
    printf("Ingrese el error deseado Es (%%): ");
    scanf("%lf", &error_deseado);

    iteracion = 0;
    error_actual = 1e9;  
    c_anterior = 0.0;

    printf("\n%-6s %-12s %-12s %-16s %-16s %-12s\n", 
           "Iter", "a", "b", "f(a)", "f(b)", "Error(%)");
    printf("-------------------------------------------------------------------------\n");

    // Método de bisección
    while (error_actual > error_deseado && iteracion < max_iter) {
        c = (a + b) / 2.0;  
        // Punto medio
        fa = (g * m / a) * (1 - exp(-a * t / m)) - v;
        fb = (g * m / b) * (1 - exp(-b * t / m)) - v;
        fk = (g * m / c) * (1 - exp(-c * t / m)) - v;
        if (iteracion > 0)
            error_actual = fabs((c - c_anterior) / c) * 100;
        printf("%-6d %-12f %-12f %-16f %-16f %-12f\n", 
               iteracion, a, b, fa, fb, error_actual);
        if (fa * fk < 0)
            b = c;
        else
            a = c;

        c_anterior = c;
        iteracion++;
    }

    printf("\nLa raiz aproximada se encuentra en c = %f\n", c);

    return 0;
}
