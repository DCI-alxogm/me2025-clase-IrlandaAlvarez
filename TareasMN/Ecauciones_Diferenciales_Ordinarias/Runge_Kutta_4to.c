#include <stdio.h>
#include <math.h>

//Ecaución del problema 
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
    double k1, k2, k3, k4;
    
    printf("MÉTODO DE RUNGE-KUTTA 4TO ORDEN\n");
    
    for(int i = 0; i < n; i++) {
        printf("%.6f\t%.6f\n", t, v);
        
        // Fórmulas de Runge-Kutta de 4to orden
        k1 = f(t, v);
        k2 = f(t + h/2, v + k1/2*h);
        k3 = f(t + h/2, v + k2/2*h);
        k4 = f(t + h, v + k3*h);
        
        v = v + (k1 + 2*k2 + 2*k3 + k4)*h/6;
        t = t + h;
    }
    
    return 0;
}