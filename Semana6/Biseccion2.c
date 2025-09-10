#include <stdio.h>
#include <math.h>

int main() {
    double a,b,k,fa, fb, fk,ea,eapp;          
    double emax, k_anterior; 
    double g = 9.81, m = 68.1, v = 40, t = 10; 
    int iteracion = 1;                
    int max_iter = 100;             

    printf("Ingrese el valor de a: ");
    scanf("%lf", &a); 
    printf("Ingrese el valor de b: ");
    scanf("%lf", &b);    
    printf("Ingrese el error maximo: ");
    scanf("%lf", &emax);

    printf("\n%-6s %-12s %-12s %-12s %-12s %-12s %-12s %-12s\n", "Iter", "a", "b", "f(a)", "f(b)", "E_rel(%)", "E_abs", "f(k)");

    k_anterior = 0;

    do {
        k = (a + b) / 2;

        fa = (g * m / a) * (1 - exp(-a * t / m)) - v;
        fb = (g * m / b) * (1 - exp(-b * t / m)) - v;
        fk = (g * m / k) * (1 - exp(-k * t / m)) - v;

        ea = k - k_anterior; 
        eapp = (fabs(ea) / k) * 100; 

        printf("%-6d %-12f %-12f %-12f %-12f %-12f %-12f %-12f\n", iteracion, a, b, fa, fb, eapp, ea, fk);

        if (fa * fk < 0) {
            b = k;
        } else {
            a = k;
        }

        if (fk == 0) { 
            break;
        }

        k_anterior = k;
        iteracion++;

    } while (eapp > emax && iteracion < max_iter);
    
    return 0;
}
