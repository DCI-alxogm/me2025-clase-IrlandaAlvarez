#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define n 3

int main() {
    float A[n][n], L[n][n], U[n][n];
    float b[n], y[n], x[n];
    float identidad[n][n], inversa[n][n];
    int i, j, k, col;

    // Inicializar matrices L y U
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i == j)
                L[i][j] = 1;  // Diagonal de L es 1
            else
                L[i][j] = 0;
            U[i][j] = 0;  // Inicializar U en 0
        }
    }

    printf("Ingrese los coeficientes de la matriz:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("A[%d][%d] = ", i + 1, j + 1);
            scanf("%f", &A[i][j]);
        }
    }

    // Matriz original
    printf("\nMatriz original A:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%10.6f ", A[i][j]);
        }
        printf("\n");
    }

    // Método de descomposición LU
    for (k = 0; k < n; k++) {
        // Calcular elementos de U, método Gauss
        for (j = k; j < n; j++) {
            float suma = 0;
            for (i = 0; i < k; i++) {
                suma += L[k][i] * U[i][j];
            }
            U[k][j] = A[k][j] - suma;
        }

        // Calcular elementos de L
        for (i = k + 1; i < n; i++) {
            float suma = 0;
            for (j = 0; j < k; j++) {
                suma += L[i][j] * U[j][k];
            }
            
            if (fabs(U[k][k]) < 0.00001) {
                printf("\nError: división por cero.\n");
                return 1;
            }
            
            L[i][k] = (A[i][k] - suma) / U[k][k];
        }
    }

    printf("\nMatriz L:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%10.6f ", L[i][j]);
        }
        printf("\n");
    }

    printf("\nMatriz U:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%10.6f ", U[i][j]);
        }
        printf("\n");
    }

    // Inicializar matriz identidad
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i == j)
                identidad[i][j] = 1;
            else
                identidad[i][j] = 0;
        }
    }

    // Calcular la inversa resolviendo n sistemas: A * columna_j = columna_j de I
    for (col = 0; col < n; col++) {
        // Establecer b como la columna actual de la matriz identidad
        for (i = 0; i < n; i++) {
            b[i] = identidad[i][col];
        }

        // Ly = b 
        for (i = 0; i < n; i++) {
            float suma = 0;
            for (j = 0; j < i; j++) {
                suma += L[i][j] * y[j];
            }
            y[i] = b[i] - suma;  // L[i][i] siempre es 1
        }

        // Resolver Ux = y
        for (i = n - 1; i >= 0; i--) {
            float suma = 0;
            for (j = i + 1; j < n; j++) {
                suma += U[i][j] * x[j];
            }
            x[i] = (y[i] - suma) / U[i][i];
        }

        // Guardar la solución como columna de la matriz inversa
        for (i = 0; i < n; i++) {
            inversa[i][col] = x[i];
        }
    }

    // Mostrar la matriz inversa
    printf("\nMatriz inversa A⁻¹:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%10.6f ", inversa[i][j]);
        }
        printf("\n");
    }

    // Verificación: A*A^-1=I
    printf("\nVerificación (A * A⁻¹):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            float suma = 0;
            for (k = 0; k < n; k++) {
                suma += A[i][k] * inversa[k][j];
            }
            printf("%10.6f ", suma);
        }
        printf("\n");
    }

    return 0;
}