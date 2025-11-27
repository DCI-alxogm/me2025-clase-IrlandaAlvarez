#include <stdio.h>
#include <math.h>

//Ecuación del problema
double f(double t, double v) {
    double g=9.81,c=12.5,m=68.1,a=8.3,b=2.2,vmax=46;
    return g - (c/m) * (v + a * pow(fabs(v/vmax), b));
}

int main() {
    double t0 = 0.0;    // tiempo inicial
    double v0 = 0.0;    // velocidad inicial
    double h = 0.1;     // paso de tiempo
    int n = 5;        // número de iteracciones
    double t = t0;
    double v = v0;
    
    printf("MÉTODO DE EULER\n");
    for(int i = 0; i < n; i++) {
        printf("%.6f\t%.6f\n", t, v);
        
        // Fórmula de Euler: v_{i+1} =f(t_i, v_i)*v_i + h 
        v = v + h * f(t, v);
        t = t + h;
    }
    return 0;
}