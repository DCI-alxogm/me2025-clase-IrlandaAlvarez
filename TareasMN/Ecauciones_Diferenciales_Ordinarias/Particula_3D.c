#include <stdio.h>
#include <math.h>

//Esto sirve para agrupar las tres variables en una sola
typedef struct {
    double x, y, z;
} Vector3D;

//dx/dt = vx, dy/dt = vy, dz/dt = vz
//dvx/dt = Fx/m, dvy/dt = Fy/m, dvz/dt = Fz/m - g

void derivadas(double t, double* y, double* dydt) {
    // y[0]=x, y[1]=y, y[2]=z, y[3]=vx, y[4]=vy, y[5]=vz
    double g=9.81;//gravedad
    double m = 1.0; // masa
    double Fx = 0.0, Fy = 0.0, Fz = 0.0; // fuerzas externas
    
    // Posiciones
    dydt[0] = y[3]; // dx/dt = vx
    dydt[1] = y[4]; // dy/dt = vy
    dydt[2] = y[5]; // dz/dt = vz
    
    // Velocidades
    dydt[3] = Fx/m; // dvx/dt = Fx/m
    dydt[4] = Fy/m; // dvy/dt = Fy/m
    dydt[5] = Fz/m - g; // dvz/dt = Fz/m - g
}


int main() {
    //Condiciones iniciales: posición (x,y,z) y velocidad (vx,vy,vz)
    double y0[6] = {0.0, 0.0, 100.0, 10.0, 5.0, 0.0};
    double t0 = 0.0;
    double h = 0.1;
    int n = 100;
    int dim = 6;
     double t = t0;
    double y[dim], k1[dim], k2[dim], k3[dim], k4[dim], ytemp[dim];
    
    //Inicializar
    for(int i = 0; i < dim; i++) {
        y[i] = y0[i];
    }
    
    printf("MOVIMIENTO EN 3D - RUNGE-KUTTA 4TO ORDEN\n");
    for(int paso = 0; paso < n; paso++) {
        printf("%.6f\t%.6f\t%.6f\t%.6f\n", t, y[0], y[1], y[2]);
        
        // k1
        derivadas(t, y, k1);
        
        // k2
        for(int i = 0; i < dim; i++) {
            ytemp[i] = y[i] + (h/2) * k1[i];
        }
        derivadas(t + h/2, ytemp, k2);
        
        // k3
        for(int i = 0; i < dim; i++) {
            ytemp[i] = y[i] + (h/2) * k2[i];
        }
        derivadas(t + h/2, ytemp, k3);
        
        // k4
        for(int i = 0; i < dim; i++) {
            ytemp[i] = y[i] + h * k3[i];
        }
        derivadas(t + h, ytemp, k4);
        
        // Actualizar
        for(int i = 0; i < dim; i++) {
            y[i] = y[i] + (h/6) * (k1[i] + 2*k2[i] + 2*k3[i] + k4[i]);
        }
        t = t + h;
    }
    
    return 0;
}