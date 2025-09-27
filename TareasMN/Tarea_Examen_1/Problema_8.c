//Problema 8
//Balance de materia
//Q - Q*c - k*V*raiz(c) + W

#include <stdio.h>
#include <math.h>

// Función f(c)
double f(double c) {
    int V=1e6,Q=1e5,W=1e6,k=0.25;
    return Q - Q*c - k*V*sqrt(c) + W;
}

int main() {
    //Valor incial
    double c0 = 4.0;  
    //Desplazamiento   
    double d = 0.5; 
    //Segundo valor
    double c1 = c0 + d; 
    double c2, e;
    
    printf("Iteracion   c aproximado   error relativo\n");

    for (int i = 0; i < 3; i++) {
        // Método de la secante
        c2 = c1 - f(c1)*(c1 - c0)/(f(c1) - f(c0));
        
        // Error relativo
        e = fabs((c2 - c1)/c2)*100;
        
        printf("%d          %lf    %lf\n", i+1, c2, e);
        
        //Valores actuales
        c0 = c1;
        c1 = c2;
    }
    
    return 0;
}
