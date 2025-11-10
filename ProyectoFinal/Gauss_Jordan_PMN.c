#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define n 4  // 4 reactores

int main() {
    float A[n][n+1];
    float x[n];
    int i, j, pivote, iter;
    int cambiosFila = 0;
    float determinante = 1.0;
    
    // Datos del problema
    float Q = 1.0;
    float c_in = 1.0;
    float V[4] = {1.0, 1.2, 0.9, 1.5};
    float k[4] = {0.10, 0.08, 0.12, 0.09};
    
    //Matriz A y vectro b
    printf("SISTEMA DE 4 REACTORES CSTR EN SERIE\n");
    printf("Datos del sistema:\n");
    printf("Q = %.2f m3/s, c_in = %.2f mol/m3\n", Q, c_in);
    printf("Volumenes: [%.1f, %.1f, %.1f, %.1f] m3\n", V[0], V[1], V[2], V[3]);
    printf("Constantes k: [%.2f, %.2f, %.2f, %.2f] s-1\n\n", k[0], k[1], k[2], k[3]);
    
    //Inicializar matriz A con ceros
    for (i = 0; i < n; i++) {
        for (j = 0; j < n + 1; j++) {
            A[i][j] = 0.0;
        }
    }
    
    //Reactor 1: (Q + k1*V1)*c1 = Q*c_in
    A[0][0] = Q + k[0] * V[0];
    A[0][4] = Q * c_in;  // vector b
    
    //Reactor 2: -Q*c1 + (Q + k2*V2)*c2 = 0
    A[1][0] = -Q;
    A[1][1] = Q + k[1] * V[1];
    A[1][4] = 0.0;
    
    //Reactor 3: -Q*c2 + (Q + k3*V3)*c3 = 0
    A[2][1] = -Q;
    A[2][2] = Q + k[2] * V[2];
    A[2][4] = 0.0;
    
    //Reactor 4: -Q*c3 + (Q + k4*V4)*c4 = 0
    A[3][2] = -Q;
    A[3][3] = Q + k[3] * V[3];
    A[3][4] = 0.0;
    
    //Matriz original
    printf("Matriz del sistema A|c:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%.6f ", A[i][j]);
        }
        printf("| %.6f\n", A[i][4]);
    }
    printf("\n");
    
    //GAUSS-JORDAN
    for (iter = 0; iter < n; iter++) { 
        pivote = iter;
        
        //Pivote
        for (i = iter + 1; i < n; i++) {
            if (fabs(A[i][iter]) > fabs(A[pivote][iter])) {
                pivote = i;
            }
        }
        if (fabs(A[pivote][iter]) < 0.0001) {
            printf("\nError: Sistema singular - pivote cero en columna %d\n", iter + 1);
            return 1;
        }

        // Intercambio de filas
        if (pivote != iter) {
            for (j = 0; j < n + 1; j++) {
                float temp = A[iter][j];
                A[iter][j] = A[pivote][j];
                A[pivote][j] = temp;
            }
            cambiosFila++;
            printf("Intercambio de filas %d y %d\n", iter + 1, pivote + 1);
        }

        //Determinante
        determinante *= A[iter][iter];

        //Normalización en la fila del pivote
        float pivot_value = A[iter][iter];
        for (j = iter; j < n + 1; j++) {
            A[iter][j] /= pivot_value;
        }

        // Eliminación en otras filas
        for (i = 0; i < n; i++) {
            if (i != iter) {
                float factor = A[i][iter];
                for (j = iter; j < n + 1; j++) {
                    A[i][j] -= factor * A[iter][j];
                }
            }
        }  // ¡AQUÍ FALTABA ESTA LLAVE!
    }  // Esta cierra el for principal de Gauss-Jordan

    //En caso, ajustar signo del determinante por intercambios de fila
    if (cambiosFila % 2 == 1) {
        determinante = -determinante;
    }
    
    //Extraer soluciones
    for (i = 0; i < n; i++) {
        x[i] = A[i][n];
    }

    //RESULTADOS
    printf("\nRESULTADOS FINALES\n");
    
    printf("\nMatriz identidad | soluciones:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%.6f ", A[i][j]);
        }
        printf("| %.6f\n", A[i][n]);
    }
    
    printf("\nDeterminante: %.6f\n", determinante);
    
    if (fabs(determinante) < 0.0001) {
        printf("El sistema no esta determinado.\n");
    } else {
        printf("El sistema esta determinado.\n");
    }
    
    printf("\nCONCENTRACIONES DE ETILENO EN CADA REACTOR:\n");
    for (i = 0; i < n; i++) {
        printf("Reactor %d: c%d = %.6f mol/m3\n", i + 1, i + 1, x[i]);
    }
    

    return 0;
}