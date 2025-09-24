#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//f1(x)=e^(-x) - x, x0=0
//f2(x)=x^10 - 1, x0=0.5
//f3(x)=x^3 - 5x^2 - 7x - 3, x0=0 y x0=4 
//El número de iteracciones máximo sera de 100
//El número de tolerancia en el error será de 1e-6
//Para todas las funcuones las variables son:x0=valor inicial, x1=valor nuevo, ea= error aproximado, iter=iteracciones 

//Punto Fijo
void puntoFijo() {
    printf("\nMétodo de Punto Fijo:\n");

    double x0, x1, ea;
    int iter;

    // f1(x) = e^(-x) - x
    printf("\nFunción 1: f(x) = e^(-x) - x, x0=0\n");
    x0 = 0; iter = 0;
    do {
        x1 = x0 + (exp(-x0) - x0); //g(x)= x +e^(-x) -x
        ea = fabs((x1 - x0) / x1) * 100;
        printf("Iter %d: x = %.6f, Error aprox = %.6f\n", iter+1, x1, ea);
        x0 = x1; iter++;
    } while(ea > 1e-6 && iter < 100);

    // f2(x) = x^10 - 1
    printf("\nFunción 2: f(x) = x^10 - 1, x0=0.5\n");
    x0 = 0.5; iter = 0;
    do {
        x1 = x0 + (pow(x0,10) - 1); //g(x)=x+x^10 - 1
        ea = fabs((x1 - x0) / x1) * 100;
        printf("Iter %d: x = %.6f, Error aprox = %.6f\n", iter+1, x1, ea);
        x0 = x1; iter++;
    } while(ea > 1e-6 && iter < 100);

    // f3(x) = x^3 - 5x^2 - 7x - 3, x0=0
    printf("\nFunción 3a: f(x) = x^3 - 5x^2 - 7x - 3, x0=0\n");
    x0 = 0; iter = 0;
    do {
        x1 = x0 + (pow(x0,3) - 5*pow(x0,2) - 7*x0 - 3); //g(x)=x+ x^3 - 5x^2 - 7x - 3
        ea = fabs((x1 - x0) / x1) * 100;
        printf("Iter %d: x = %.6f, Error aprox = %.6f\n", iter+1, x1, ea);
        x0 = x1; iter++;
    } while(ea > 1e-6 && iter < 100);

    // f3(x) con x0=4
    printf("\nFunción 3b: f(x) = x^3 - 5x^2 - 7x - 3, x0=4\n");
    x0 = 4; iter = 0;
    do {
        x1 = x0 + (pow(x0,3) - 5*pow(x0,2) - 7*x0 - 3); //g(x)=x+ x^3 - 5x^2 - 7x - 3
        ea = fabs((x1 - x0) / x1) * 100;
        printf("Iter %d: x = %.6f, Error aprox = %.6f\n", iter+1, x1, ea);
        x0 = x1; iter++;
    } while(ea > 1e-6 && iter < 100);
}

//Newton_Rhapson 
void newtonRaphson() {
    printf("\nMétodo de Newton-Raphson:\n");

    double x0, x1, ea;
    int iter;

    // f1
    printf("\nFunción 1: f(x) = e^(-x) - x, x0=0\n");
    x0 = 0; iter = 0;
    do {
        x1 = x0 - (exp(-x0)-x0)/(-exp(-x0)-1);
        ea = fabs((x1 - x0)/x1) * 100;
        printf("Iter %d: x = %.6f, Error aprox = %.6f\n", iter+1, x1, ea);
        x0 = x1; iter++;
    } while(ea > 1e-6 && iter < 100);

    // f2
    printf("\nFunción 2: f(x) = x^10 - 1, x0=0.5\n");
    x0 = 0.5; iter = 0;
    do {
        x1 = x0 - (pow(x0,10)-1)/(10*pow(x0,9));
        ea = fabs((x1 - x0)/x1) * 100;
        printf("Iter %d: x = %.6f, Error aprox = %.6f\n", iter+1, x1, ea);
        x0 = x1; iter++;
    } while(ea > 1e-6 && iter < 100);

    // f3 con x0=0
    printf("\nFunción 3a: f(x) = x^3 - 5x^2 - 7x - 3, x0=0\n");
    x0 = 0; iter = 0;
    do {
        x1 = x0 - (pow(x0,3)-5*pow(x0,2)-7*x0-3)/(3*pow(x0,2)-10*x0-7);
        ea = fabs((x1 - x0)/x1) * 100;
        printf("Iter %d: x = %.6f, Error aprox = %.6f\n", iter+1, x1, ea);
        x0 = x1; iter++;
    } while(ea > 1e-6 && iter < 100);

    // f3 con x0=4
    printf("\nFunción 3b: f(x) = x^3 - 5x^2 - 7x - 3, x0=4\n");
    x0 = 4; iter = 0;
    do {
        x1 = x0 - (pow(x0,3)-5*pow(x0,2)-7*x0-3)/(3*pow(x0,2)-10*x0-7);
        ea = fabs((x1 - x0)/x1) * 100;
        printf("Iter %d: x = %.6f, Error aprox = %.6f\n", iter+1, x1, ea);
        x0 = x1; iter++;
    } while(ea > 1e-6 && iter < 100);
}

//Secante
void secante() {
    printf("\nMétodo de la Secante:\n");

    double x0, x1, x2, ea;
    int iter;

    // f1
    printf("\nFunción 1: f(x) = e^(-x) - x, x0=0, x1=0.1\n");
    x0 = 0; x1 = 0.1; iter = 0;
    do {
        x2 = x1 - (exp(-x1)-x1)*(x1-x0)/((exp(-x1)-x1)-(exp(-x0)-x0));
        ea = fabs((x2 - x1)/x2) * 100;
        printf("Iter %d: x = %.6f, Error aprox = %.6f\n", iter+1, x2, ea);
        x0 = x1; x1 = x2; iter++;
    } while(ea > 1e-6 && iter < 100);

    // f2
    printf("\nFunción 2: f(x) = x^10 - 1, x0=0.5, x1=0.6\n");
    x0 = 0.5; x1 = 0.6; iter = 0;
    do {
        x2 = x1 - (pow(x1,10)-1)*(x1-x0)/((pow(x1,10)-1)-(pow(x0,10)-1));
        ea = fabs((x2 - x1)/x2) * 100;
        printf("Iter %d: x = %.6f, Error aprox = %.6f\n", iter+1, x2, ea);
        x0 = x1; x1 = x2; iter++;
    } while(ea > 1e-6 && iter < 100);

    // f3 con x0=0 y x1=4
    printf("\nFunción 3a: f(x) = x^3 - 5x^2 - 7x - 3, x0=0, x1=4\n");
    x0 = 0; x1 = 4; iter = 0;
    do {
        x2 = x1 - (pow(x1,3)-5*pow(x1,2)-7*x1-3)*(x1-x0) /
                  ((pow(x1,3)-5*pow(x1,2)-7*x1-3) - (pow(x0,3)-5*pow(x0,2)-7*x0-3));
        ea = fabs((x2 - x1)/x2) * 100;
        printf("Iter %d: x = %.6f, Error aprox = %.6f\n", iter+1, x2, ea);
        x0 = x1; x1 = x2; iter++;
    } while(ea > 1e-6 && iter < 100);
}

//Newton_Rhapson Modificado
void newtonModificado() {
    printf("\nMétodo de Newton-Raphson Modificado:\n");

    double x0, x1, ea;
    int iter;

    // f1
    printf("\nFunción 1: f(x) = e^(-x) - x, x0=0\n");
    x0 = 0; iter = 0;
    do {
        x1 = x0 - ((exp(-x0)-x0)*(-exp(-x0)-1)) /
                  (pow(-exp(-x0)-1,2) - (exp(-x0)-x0)*exp(-x0));
        ea = fabs((x1 - x0)/x1) * 100;
        printf("Iter %d: x = %.6f, Error aprox = %.6f\n", iter+1, x1, ea);
        x0 = x1; iter++;
    } while(ea > 1e-6 && iter < 100);

    // f2
    printf("\nFunción 2: f(x) = x^10 - 1, x0=0.5\n");
    x0 = 0.5; iter = 0;
    do {
        x1 = x0 - ((pow(x0,10)-1)*(10*pow(x0,9))) /
                  (pow(10*pow(x0,9),2) - (pow(x0,10)-1)*(90*pow(x0,8)));
        ea = fabs((x1 - x0)/x1) * 100;
        printf("Iter %d: x = %.6f, Error aprox = %.6f\n", iter+1, x1, ea);
        x0 = x1; iter++;
    } while(ea > 1e-6 && iter < 100);

    // f3 con x0=0
    printf("\nFunción 3a: f(x) = x^3 - 5x^2 - 7x - 3, x0=0\n");
    x0 = 0; iter = 0;
    do {
        x1 = x0 - ((pow(x0,3)-5*pow(x0,2)-7*x0-3)*(3*pow(x0,2)-10*x0-7)) /
                  (pow(3*pow(x0,2)-10*x0-7,2) - (pow(x0,3)-5*pow(x0,2)-7*x0-3)*(6*x0-10));
        ea = fabs((x1 - x0)/x1) * 100;
        printf("Iter %d: x = %.6f, Error aprox = %.6f\n", iter+1, x1, ea);
        x0 = x1; iter++;
    } while(ea > 1e-6 && iter < 100);

    // f3 con x0=4
    printf("\nFunción 3b: f(x) = x^3 - 5x^2 - 7x - 3, x0=4\n");
    x0 = 4; iter = 0;
    do {
        x1 = x0 - ((pow(x0,3)-5*pow(x0,2)-7*x0-3)*(3*pow(x0,2)-10*x0-7)) /
                  (pow(3*pow(x0,2)-10*x0-7,2) - (pow(x0,3)-5*pow(x0,2)-7*x0-3)*(6*x0-10));
        ea = fabs((x1 - x0)/x1) * 100;
        printf("Iter %d: x = %.6f, Error aprox = %.6f\n", iter+1, x1, ea);
        x0 = x1; iter++;
    } while(ea > 1e-6 && iter < 100);
}

int main() {
    int opcion;

    do {
        printf("Funciones a analizar:\n f1(x)=e^(-x) - x, x0=0 \n f2(x)=x^10 - 1, x0=0.5 \n f3(x)=x^3 - 5x^2 - 7x - 3, x0=0 y x0=4 \n");
        printf("Introduzca el método que quiera calcular:\n");
        printf("1. Punto fijo\n");
        printf("2. Newton-Raphson\n");
        printf("3. Secante\n");
        printf("4. Newton-Raphson Modificado\n");
        printf("0. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1: puntoFijo(); break;
            case 2: newtonRaphson(); break;
            case 3: secante(); break;
            case 4: newtonModificado(); break;
            case 0: break;
            default: printf("Opción no válida.\n");
        }
    } while(opcion != 0);

    return 0;
}
