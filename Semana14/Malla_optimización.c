#include <stdio.h>
#include <math.h>

// Función
double funcion(double x, double y) {
    return y - x - 2*x*x - 2*x*y - y*y;
}

int main() {
    //Valores de los intervalos
    double x_min = -2.0, x_max = 2.0;
    double y_min = 1.0, y_max = 3.0;
    int N=10;
    int iter = 0;
    double valor_maximo=-1000;
    double x_optimo, y_optimo;
    
    printf(" Iteración     x         y        f(x,y)    x_optimo  y_optimo \n");
    
    // Malla 
    for(int i = 0; i < N; i++) {
        double x = x_min + i * (x_max - x_min) / (N - 1);
        for(int j = 0; j < N; j++) {
            double y = y_min + j * (y_max - y_min) / N;
            
            double valor = funcion(x, y);
            iter++;
            
            // Evaluamos si la función ya llego a su valor maximo
            if(valor > valor_maximo) {
                valor_maximo = valor;
                x_optimo = x;
                y_optimo = y;
            }
            printf(" %d  %.6f  %.6f  %.6f  %.6f  %.6f \n", 
                   iter, x, y, valor, x_optimo, y_optimo);
        }
    }
    
    // Resultados
    printf("Iteraciones totales: %d\n", iter);
    printf("Valor máximo: %.6f\n", valor_maximo);
    printf("Coordenadas donde se alcanza el valor máximo: (%.6f, %.6f)\n", x_optimo, y_optimo);
    
    return 0;
}