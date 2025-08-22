#include <stdio.h>
#include <math.h>

int main() {
    double a, b, c, x1, x2, xi1, xi2, discr;
    char opcion;

    do {
        printf("\nIngrese a: ");
        scanf("%lf", &a);
        printf("Ingrese b: ");
        scanf("%lf", &b);
        printf("Ingrese c: ");
        scanf("%lf", &c);

        if (a == 0) {
            if (b != 0) {
                x1 = -c / b;
                printf("x1 = %.2lf\n", x1);
            } else {
                printf("Solucion trivial\n");
            }
        } else {
            discr = b*b - 4*a*c;

            if (discr >= 0) {
                x1 = (-b + sqrt(discr)) / (2*a);
                x2 = (-b - sqrt(discr)) / (2*a);
                printf("x1 = %.2lf\n", x1);
                printf("x2 = %.2lf\n", x2);
            } else {
                x1 = -b / (2*a);                  
                xi1 = sqrt(fabs(discr)) / (2*a);  
                x2 = x1;                          
                xi2 = -xi1;                       

                printf("x1 = %.2lf + %.2lfi\n", x1, xi1);
                printf("x2 = %.2lf %.2lfi\n", x2, xi2);
            }
        }

        printf("\n¿Desea realizar otra operacion? (S/N): ");
        scanf(" %c", &opcion); 

    } while (opcion != 'N' && opcion != 'n');

    return 0;
}
