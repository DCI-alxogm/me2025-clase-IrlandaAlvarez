#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define n 3

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
    
    // Matriz original
    printf("\nMatriz original:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n + 1; j++) {
            printf("%.6f ", A[i][j]);
        }
        printf("\n");
    }
    
    // Eliminación hacia adelante Gauss-Jordan
    for (k = 0; k < n; k++) {
        pivote = k;
        
        // Búsqueda del pivote
        for (i = k + 1; i < n; i++) {
            if (fabs(A[i][k]) > fabs(A[pivote][k])) {
                pivote = i;
            }
        }
        
        if (fabs(A[pivote][k]) < 0.0001) {
            printf("\nError: pivote cero en columna %d.\n", k + 1);
            return 1;
        }

        // Intercambio de filas
        if (pivote != k) {
            for (j = k; j < n + 1; j++) {
                float temp = A[k][j];
                A[k][j] = A[pivote][j];
                A[pivote][j] = temp;
            }
            printf("\nIntercambio de filas %d y %d\n", k + 1, pivote + 1);
        }

        // Normalizar la fila pivote
        float pivot_value = A[k][k];
        for (j = k; j < n + 1; j++) {
            A[k][j] /= pivot_value;
        }

        // Eliminación hacia adelante
        for (i = k + 1; i < n; i++) {
            float factor = A[i][k];
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
        x[i] = (A[i][n] - suma) / A[i][i];
    }

    // Matriz final
    printf("\nMatriz triangular superior final:\n");
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