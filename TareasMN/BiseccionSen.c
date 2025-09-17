#include <stdio.h>
#include <math.h>

int main() {
    double a,b,k,fa, fb, fk,ea,eapp,eat;          
    double emax, k_anterior,dx; 
    int iteracion = 1;                
    int max_iter = 100;             

    printf("Ingrese el valor de a: ");
    scanf("%lf", &a); 
    printf("Ingrese el valor de b: ");
    scanf("%lf", &b);    
    printf("Ingrese el error maximo: ");
    scanf("%lf", &emax);

    printf("\n%-6s %-12s %-12s %-12s %-12s %-12s %-12s %-12s %-12s \n", "Iter", "a", "b", "f(a)", "f(b)", "E_rel(%)", "E_abs","E_teorico", "f(k)");

    dx=a-b;
    k_anterior = 0;

    do {
        k = (a + b) / 2;

        fa = sin(10*a)-cos(3*a);
        fb = sin(10*b)-cos(3*b);
        fk = sin(10*k)-cos(3*k);

        ea = k - k_anterior; 
        eapp = (fabs(ea) / k) * 100; 
        eat=dx/pow(2,iteracion);

        printf("%-6d %-12f %-12f %-12f %-12f %-12f %-12f %-12f %-12f \n", iteracion, a, b, fa, fb, eapp, ea, eat, fk);

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