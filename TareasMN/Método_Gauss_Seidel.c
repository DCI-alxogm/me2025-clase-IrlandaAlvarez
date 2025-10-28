#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define n 3

int main() {
    float A[n][n], b[n], x[n] = {0, 0, 0};
    float x_2[n],suma;
    int i, j, iter;
    

    
    printf("Ingrese la matriz A (%dx%d):\n", n, n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("  A[%d][%d] = ", i + 1, j + 1);
            scanf("%f", &A[i][j]);
        }
    }

    printf("\nIngrese los valores de b:\n");
    for (i = 0; i < n; i++) {
        printf("b[%d] = ", i + 1);
        scanf("%f", &b[i]);
    }

    printf("\nIngrese valores iniciales de x (o 0 para empezar con ceros):\n");
    for (i = 0; i < n; i++) {
        printf("x%d inicial = ", i + 1);
        scanf("%f", &x[i]);
    }

    // Matriz original
    printf("\nMatriz original:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (j == 0)
                printf("%.1fx%d", A[i][j], j + 1);
            else
                printf(" + %.1fx%d", A[i][j], j + 1);
        }
        printf(" = %.1f\n", b[i]);
    }


    for (i = 0; i < n; i++) {
        printf("x%d^(k+1) = (%.1f", i + 1, b[i]);
        for (j = 0; j < n; j++) {
            if (j != i && A[i][j] != 0) {
                if (j < i)
                    printf(" - %.1f*x%d^(k+1)", A[i][j], j + 1);
                else
                    printf(" - %.1f*x%d^(k)", A[i][j], j + 1);
            }
        }
        printf(") / %.1f\n", A[i][i]);
    }

    // Método de Gauss-Seidel
    for (iter = 0; iter < 100; iter++) {
        // Guardar valores anteriores
        for (i = 0; i < n; i++) {
            x_2[i] = x[i];
        }

        // Actualizar cada variable usando Gauss-Seidel
        for (i = 0; i < n; i++) {
            suma = 0;
            
            // Sumar términos con coeficientes distintos de cero
            for (j = 0; j < n; j++) {
                if (j != i) {
                    suma += A[i][j] * x[j]; // Usa valores nuevos si j < i, viejos si j > i
                }
            }
            if (fabs(A[i][i]) < 0.00001) {
                printf("\nERROR: Division por cero \n");
                return 1;
            }
            
            // Nuevo valor de x[i]
            x[i] = (b[i] - suma) / A[i][i];
        }

        // Iteración actual
        printf("\nIteración %d:\n", iter + 1);
        for (i = 0; i < n; i++) {
            printf("  x%d = %.6f", i + 1, x[i]);
        }

    }

    // Resultados finales
    printf("\nResultados finales\n");
    for (i = 0; i < n; i++) {
        printf("x%d = %.6f\n", i + 1, x[i]);
    }

    // Verificación de los resultados
    printf("Sustituyendo en las ecuaciones originales:\n");
    for (i = 0; i < n; i++) {
        suma = 0.0;
        for (j = 0; j < n; j++) {
            suma += A[i][j] * x[j];
        }
        float residuo = suma - b[i];
        printf("Ecuación %d: %.6f = %.6f (residuo: %.6f)\n", 
               i + 1, suma, b[i], residuo);
    }

    return 0;
}