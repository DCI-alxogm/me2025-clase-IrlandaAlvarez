#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define n 4  // 4 reactores

int main() {
    float A[n][n], b[n], x[n] = {0, 0, 0, 0};
    float x_anterior[n], suma;
    int i, j, iter;
    int max_iter = 100;
    float tolerancia = 1e-6;
    
    //Datos del problema
    float Q = 1.0;
    float c_in = 1.0;
    float V[4] = {1.0, 1.2, 0.9, 1.5};
    float k[4] = {0.10, 0.08, 0.12, 0.09};
    
    //Matriz A y vector b 
    printf("METODO DE GAUSS-SEIDEL, 4 REACTORES CSTR \n");
    printf("Datos del sistema:\n");
    printf("Q = %.2f m3/s, c_in = %.2f mol/m3\n", Q, c_in);
    printf("Volumenes: [%.1f, %.1f, %.1f, %.1f] m3\n", V[0], V[1], V[2], V[3]);
    printf("Constantes k: [%.2f, %.2f, %.2f, %.2f] s-1\n\n", k[0], k[1], k[2], k[3]);
    
    //Inicializar matriz A y vector b con ceros
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            A[i][j] = 0.0;
        }
        b[i] = 0.0;
    }
    //Reactor 1: (Q + k1*V1)*c1 = Q*c_in
    A[0][0] = Q + k[0] * V[0];
    b[0] = Q * c_in;
    
    //Reactor 2: -Q*c1 + (Q + k2*V2)*c2 = 0
    A[1][0] = -Q;
    A[1][1] = Q + k[1] * V[1];
    b[1] = 0.0;
    
    //Reactor 3: -Q*c2 + (Q + k3*V3)*c3 = 0
    A[2][1] = -Q;
    A[2][2] = Q + k[2] * V[2];
    b[2] = 0.0;
    
    //Reactor 4: -Q*c3 + (Q + k4*V4)*c4 = 0
    A[3][2] = -Q;
    A[3][3] = Q + k[3] * V[3];
    b[3] = 0.0;
    
    //Matriz original 
    printf("Sistema de ecuaciones:\n");
    for (i = 0; i < n; i++) {
        printf("Ecuacion %d: ", i + 1);
        for (j = 0; j < n; j++) {
            if (A[i][j] != 0) {
                if (j == 0)
                    printf("%.3f*c%d", A[i][j], j + 1);
                else if (A[i][j] > 0)
                    printf(" + %.3f*c%d", A[i][j], j + 1);
                else
                    printf(" - %.3f*c%d", -A[i][j], j + 1);
            }
        }
        printf(" = %.3f\n", b[i]);
    }
    
    // Valores iniciales
    printf("\nValores iniciales: c1 = %.1f, c2 = %.1f, c3 = %.1f, c4 = %.1f\n", 
           x[0], x[1], x[2], x[3]);
    printf("Tolerancia: %.2e\n", tolerancia);
    printf("Maximo de iteraciones: %d\n\n", max_iter);
    
    //Método de Gauss-Seidel
    int convergio = 0;
    for (iter = 0; iter < max_iter; iter++) {
        //Guardar valores anteriores
        for (i = 0; i < n; i++) {
            x_anterior[i] = x[i];
        }

        //Actualizar cada variable usando Gauss-Seidel
        for (i = 0; i < n; i++) {
            suma = 0.0;
            
            //Sumar términos con coeficientes distintos de cero
            for (j = 0; j < n; j++) {
                if (j != i) {
                    suma += A[i][j] * x[j]; // Usa valores nuevos si j < i, viejos si j > i
                }
            }
            if (fabs(A[i][i]) < 1e-10) {
                printf("\nERROR: Division por cero en ecuacion %d\n", i + 1);
                return 1;
            }
            
            // Nuevo valor de x[i]
            x[i] = (b[i] - suma) / A[i][i];
        }

        // Calcular error
        float error_max = 0.0;
        for (i = 0; i < n; i++) {
            float error = fabs(x[i] - x_anterior[i]);
            if (error > error_max) {
                error_max = error;
            }
        }
        
        //Iteracción 
        printf("Iteracion %2d: ", iter + 1);
        for (i = 0; i < n; i++) {
            printf("c%d = %8.6f  ", i + 1, x[i]);
        }
        printf("Error: %.2e\n", error_max);
        
        //Covengencia
        if (error_max < tolerancia) {
            convergio = 1;
            break;
        }
    }

    //RESULTADOS
    printf("\nRESULTADOS FINALES\n");
    
    if (convergio) {
        printf("Convergencia alcanzada en %d iteraciones\n", iter + 1);
    } else {
        printf("Maximo de iteraciones alcanzado (%d)\n", max_iter);
    }
    
    printf("\nCONCENTRACIONES DE ETILENO:\n");
    for (i = 0; i < n; i++) {
        printf("Reactor %d: c%d = %.6f mol/m3\n", i + 1, i + 1, x[i]);
    }

    return 0;
}