#include <stdio.h>
#include <math.h>

//Ecuación del problema
double f(double t, double C) {
    double C0 = 0.02,k = 0.45,Cmax = 1.0;
    return k * C * (Cmax - C);
}

int main() {
    double C0 = 0.02,k = 0.45,Cmax = 1.0;
    double t0 = 0.0;      
    double h = 0.1;       
    double t_final = 25.0; 
    int n = (int)(t_final / h);  
    double t = t0;
    double C = C0;
    double k1, k2, k3, k4;
    
    printf("MÉTODO DE RUNGE-KUTTA 4TO ORDEN\n");
    
    for(int i = 0; i <= n; i++) {
        //Imprimir cada 2.5 minutos
        if (i % 25 == 0) {
            printf("%.6f\t%.6f\n", t, C);
        }
        
        if (i < n) {
            //Runge-Kutta de 4to orden
            k1 = f(t, C);
            k2 = f(t + h/2, C + k1*h/2);
            k3 = f(t + h/2, C + k2*h/2);
            k4 = f(t + h, C + k3*h);
            
            C = C + (k1 + 2*k2 + 2*k3 + k4)*h/6;
            t = t + h;
        }
    }
    
    //COMPARACIÓN CON RK2
    printf("\nCOMPARACIÓN CON RUNGE-KUTTA 2DO ORDEN\n");
    
    //Mostramos el resultado de RK4 para tomarlo como referencia 
    double C_final_rk4 = C;
    printf("Solución final RK4 (h=0.1): C(25) = %.6f mol/L\n\n", C_final_rk4);
    
    // Probamos RK2 con diferentes h
    double h_val[] = {0.1, 0.05, 0.02, 0.01, 0.005};
    int num_tests = 5;
    
    for(int j = 0; j < num_tests; j++) {
        //Estas variables son de prueba para RK2
        double h_pru = h_val[j];
        double t_pru = t0;
        double C_pru = C0;
        int n_pru = (int)(t_final / h_pru);
        
        // Método de Runge-Kutta de 2do orden
        for(int i = 0; i < n_pru; i++) {
            double k1_rk2, k2_rk2;
            
            k1_rk2 = f(t_pru, C_pru);
            k2_rk2 = f(t_pru + h_pru, C_pru + k1_rk2*h_pru);
            
            C_pru = C_pru + (k1_rk2 + k2_rk2)*h_pru/2;
            t_pru = t_pru + h_pru;
        }
        
        double diferencia = fabs(C_pru - C_final_rk4);
        
        printf("%.3f\t\t%.6f\t\t%.6f\n", 
               h_pru, C_pru, diferencia);
    }

    //Esta es mi conclusión ya viendo los resultados de ambos métodos
    printf("\nCONCLUSIÓN:\n");
    printf("Para obtener resultados similares con RK2, se necesita:\n");
    printf("h=0.01 min o menor ya que viendo los resultados se observa que son iguales\n");
    printf("\nEsto se debe a que RK4 es más preciso y puede usar intervalos\n");
    printf("más grandes manteniendo buena precisión.\n");
    
    return 0;
}