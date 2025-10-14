#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define n 2

int main() {
    float A[n][n+1];
    float x[n];
    int i, j, k, pivote;

   printf("Ingrese los coeficientes de la matriz:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n + 1; j++) {
            if (j < n)
                printf("A[%d][%d] = ", i + 1, j + 1);
            else
                printf("b[%d] = ", i + 1);
            scanf("%f", &A[i][j]);
        }
    }
    
    // Verificar los coeficientes que no sean ceros
    for (k = 0; k < n - 1; k++) {
        pivote = k;
        for (i = k + 1; i < n; i++) {
            if (fabs(A[i][k]) > fabs(A[pivote][k])) {
                pivote = i;
            }
        }
        if (fabs(A[pivote][k]) < 0.1) {
            printf("\nError: pivote nulo en la columna %d. Sistema sin solución única.\n", k + 1);
            return 1;
        }

        //Intercambiador de filas
        if (pivote != k) {
            for (j = k; j < n + 1; j++) {
                float temp = A[k][j];
                A[k][j] = A[pivote][j];
                A[pivote][j] = temp;
            }
            printf("\nIntercambio de filas %d y %d\n", k + 1, pivote + 1);
        }

        // Eliminación de coeficientes
        for (i = k + 1; i < n; i++) {
            float factor = A[i][k] / A[k][k];
            for (j = k; j < n + 1; j++) {
                A[i][j] -= factor * A[k][j];
            }
        }
    }

    // Sustitución regresiva
    for (i = n - 1; i >= 0; i--) {
        float suma = 0;
        for (j = i + 1; j < n; j++) {
            suma += A[i][j] * x[j];
        }

        if (fabs(A[i][i]) < 1e-10) {
            printf("\nError: división por cero en la ecuación %d.\n", i + 1);
            return 1;
        }

        x[i] = (A[i][n] - suma) / A[i][i];
    }

    // Matriz resultante
    printf("\nMatriz triangular superior:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n + 1; j++) {
            printf("%10.4f ", A[i][j]);
        }
        printf("\n");
    }

    // Mostrar resultados
    printf("\nResultados:\n");
    for (i = 0; i < n; i++) {
        printf("x%d = %.6f\n", i + 1, x[i]);
    }

    return 0;
}
