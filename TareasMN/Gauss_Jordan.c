#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define n 3

int main() {
    float A[n][n+1];
    float x[n];
    int i, j, k, pivote;
    int cambiosFila = 0;
    float determinante = 1.0;

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
    printf("\nMatriz inicial:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n + 1; j++) {
            printf("%10.6f ", A[i][j]);
        }
        printf("\n");
    }
    
    // GAUSS-JORDAN 
    for (k = 0; k < n; k++) {
        pivote = k;
        
        //Pivote
        for (i = k + 1; i < n; i++) {
            if (fabs(A[i][k]) > fabs(A[pivote][k])) {
                pivote = i;
            }
        }
        
        if (fabs(A[pivote][k]) < 0.0001) {
            printf("\nError: pivote cero en columna %d.\n", k + 1);
            return 1;
        }

        //Intercambio de filas
        if (pivote != k) {
            for (j = 0; j < n + 1; j++) {
                float temp = A[k][j];
                A[k][j] = A[pivote][j];
                A[pivote][j] = temp;
            }
            cambiosFila++;
            printf("\nIntercambio de filas %d y %d\n", k + 1, pivote + 1);
        }

        //Determinante
        determinante *= A[k][k];

        //Normalización
        float pivot_value = A[k][k];
        for (j = k; j < n + 1; j++) {
            A[k][j] /= pivot_value;
        }

        printf("\nDespues de normalizar fila %d:\n", k + 1);
        for (i = 0; i < n; i++) {
            for (j = 0; j < n + 1; j++) {
                printf("%10.6f ", A[i][j]);
            }
            printf("\n");
        }

        //Eliminación
        for (i = 0; i < n; i++) {
            if (i != k) {  // Para todas las filas excepto la pivote
                float factor = A[i][k];
                for (j = k; j < n + 1; j++) {
                    A[i][j] -= factor * A[k][j];
                }
            }
        }

        printf("\nDespues de eliminar columna %d:\n", k + 1);
        for (i = 0; i < n; i++) {
            for (j = 0; j < n + 1; j++) {
                printf("%10.6f ", A[i][j]);
            }
            printf("\n");
        }
    }

    //Valor absoluto del determinante
    if (cambiosFila % 2 == 1) {
        determinante = -determinante;
    }
    for (i = 0; i < n; i++) {
        x[i] = A[i][n];
    }

    // Matriz final 
    printf("\nMatriz final\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n + 1; j++) {
            printf("%10.6f ", A[i][j]);
        }
        printf("\n");
    }

    // Mostrar resultados
    printf("Determinante: %.6f\n", determinante);
    
    if (fabs(determinante) < 0.0001) {
        printf("El sistema no esta determinado \n");
    } else {
        printf("El sistema esta bien determinado.\n");
    }
    
    printf("\nSoluciones:\n");
    for (i = 0; i < n; i++) {
        printf("x%d = %.6f\n", i + 1, x[i]);
    }

    return 0;
}