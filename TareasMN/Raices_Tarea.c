#include <stdio.h>
#include <math.h>
#include <stdlib.h>


//La función será f(x)=cos(x)-x
//El número de iteracciones máximo sera de 100
//El número de tolerancia en el error será de 1e-6
// Método Punto Fijo
//x=valor original, x1=valor nuevo, ea= error aproximado, iter=iteracciones 
void puntoFijo(double x0) {
    printf("\nMétodo de Punto Fijo:\n");
    int iter = 0;
    double x = x0, x1, ea;

    do {
        x1 = cos(x); //g(x)=cos(x), es el nuevo valor 
        ea = fabs((x1 - x) / x1) * 100;
        printf("Iter %d: x = %.6f, Error aprox = %.6f\n", iter+1, x1, ea);
        x = x1;
        iter++;
    } while (ea > 1e-6 && iter < 1000);

    printf("Raíz aproximada = %.6f\n", x);
}

// Método Newton-Raphson
//x=valor original, x1=valor nuevo, ea= error aproximado, iter=iteracciones 
void newtonRaphson(double x0) {
    printf("\nMétodo de Newton-Raphson:\n");
    int iter = 0;
    double x = x0, x1, ea;

    do {
        x1 = x - (cos(x) - x)/(-sin(x) - 1); // Fórmula de Newton-Rhapson
        ea = fabs((x1 - x) / x1) * 100;
        printf("Iter %d: x = %.6f, Error aprox = %.6f\n", iter+1, x1, ea);
        x = x1;
        iter++;
    } while (ea > 1e-6 && iter < 100);

    printf("Raíz aproximada = %.6f\n", x);
}

// Método de la Secante
//x=valor original, x1=segundo valor original,x2=valor nuevo ea= error aproximado, iter=iteracciones 
void secante(double x0, double x1) {
    printf("\nMétodo de la Secante:\n");
    int iter = 0;
    double x2, ea;

    do {
        x2 = x1 - (cos(x1)-x1)*(x1 - x0)/((cos(x1)-x1) - (cos(x0)-x0));
        ea = fabs((x2 - x1) / x2) * 100;
        printf("Iter %d: x = %.6f, Error aprox = %.6f\n", iter+1, x2, ea);
        x0 = x1;
        x1 = x2;
        iter++;
    } while (ea > 1e-6 && iter < 100);

    printf("Raíz aproximada = %.6f\n", x1);
}

// Variante: Newton-Raphson Modificado
//x=valor original, x1=valor nuevo, ea= error aproximado, iter=iteracciones 
void newtonModificado(double x0) {
    printf("\nMétodo de Newton-Raphson Modificado:\n");
    int iter = 0;
    double x = x0, x1, ea;
    double dfx = -sin(x0) - 1; // derivada fija

    do {
        x1 = x - (cos(x) - x)/dfx;
        ea = fabs((x1 - x) / x1) * 100;
        printf("Iter %d: x = %.6f, Error aprox = %.6f\n", iter+1, x1, ea);
        x = x1;
        iter++;
    } while (ea > 1e-6 && iter < 100);

    printf("Raíz aproximada = %.6f\n", x);
}

int main() {
    int opcion;
    double x0, x1;

    do {
        printf("Función: f(x) = cos(x) - x\n");
        printf("1. Punto fijo\n");
        printf("2. Newton-Raphson\n");
        printf("3. Secante\n");
        printf("4. Newton-Raphson Modificado\n");
        printf("5.Salir: Ingrese 0\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                printf("Ingrese x0: ");
                scanf("%lf", &x0);
                puntoFijo(x0);
                break;
            case 2:
                printf("Ingrese x0: ");
                scanf("%lf", &x0);
                newtonRaphson(x0);
                break;
            case 3:
                printf("Ingrese x0 y x1: ");
                scanf("%lf %lf", &x0, &x1);
                secante(x0, x1);
                break;
            case 4:
                printf("Ingrese x0: ");
                scanf("%lf", &x0);
                newtonModificado(x0);
                break;
            case 0:
                 break;    
            default:
                printf("Opción no válida.\n");
        }
    } while(opcion != 0);

    return 0;
}
