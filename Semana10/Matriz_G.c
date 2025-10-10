#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define n 3
int main() {
    float A[n][n+1] = {
        {3.0, -0.1, -0.2, 7.85},
        {0.1, 7.0, -0.3, -19.3},
        {0.3, -0.2, 10.0, 71.4}
    };

    float x[n];
    int i,j,k;
    // Proceso de eliminación
    for (k = 0; k < n - 1; k++) {
        for (i = k + 1; i < n; i++) {
            for (j = k; j < n + 1; j++) {
                A[i][j] -=(A[i][k] / A[k][k]) * A[k][j];
            }
        }
    }
    //Sustitución en la matriz
    for (i=n-1; i>=0; i--)
    {
        float sust=0;
        for (j = i+1; j <n; j++)
        {
           sust +=A[i][j] * x[j];
        }
        x[i] = (A[i][n] - sust) / A[i][i];
        
    }
    

    //Matriz actualizda
    printf("\nMatriz con los valores nuevos:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j <n + 1; j++) {
            printf("%.6f ", A[i][j]);
        }
        printf("\n");
    }

    //Resultados de x
    printf("Resultados de x\n");
    for (i = 0; i < n; i++) {
        printf("x%d = %.6f\n", i + 1, x[i]);
    }

   
    return 0;
}

