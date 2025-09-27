//Problema 6
//Método falsa posición 
//Tres iteraciones del método de la falsa posición para V(h) = 30, R = 3.

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//Función f(h)
double f(double h) {
    double R = 3.0;
    double V = (3.1416 * h*h * (3.0*R - h)) / 3.0; /* V(h) */
    return V - 30.0;
}

int main(void) {
    //Limite inferior del tanque 
    double a = 0; 
    //Limite superior 2R=6 del tanque 
    double b = 6;  
    double fa = f(a);
    double fb = f(b);

    if (fa * fb > 0.0) {
        printf("No hay cambio de signo en el intervalo inicial [%.6f, %.6f].\n", a, b);
        return 1;
    }
    //Aproximación actual
    double xa = a;
    //Aporximación anterior para calcular el error relativo 
    double xa_ant = 0; 
    double ea = 0.0; 

    printf("Iter      a          b          xr         f(xr)        err_rel\n");
    
    //Iteracción de 3 veces
    for (int i = 1; i <= 3; ++i) {

       //Método falsa posición 
        xa = b - fb * (b - a) / (fb - fa);
        double fxa = f(xa); //Valor de la aproximación en la función

       //En la primera iteracción no hay un valor anterior por lo que no se puede calcular el error relativo
        if (i == 1) {
            printf("%3d   %.6f  %.6f  %.6f  %.6f  -\n",i, a, b, xa, fxa);
        } else {
            ea = fabs((xa - xa_ant) / xa) * 100.0;
            printf("%3d   %.6f  %.6f  %.6f  %.6f  %.6f\n",i, a, b, xa, fxa, ea);
        }

    //Si tienen signos opuestos
        if (fa * fxa < 0.0) {
            b = xa;
            fb = fxa;
        } else {
            a = xa;
            fa = fxa;
        }
     //Valor actual para la siguiente iteracción 
        xa_ant = xa;
    }

    return 0;
}
