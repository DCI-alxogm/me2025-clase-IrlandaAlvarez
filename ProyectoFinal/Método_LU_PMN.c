#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define n 4  // 4 reactores

int main() {
    float A[n][n], L[n][n], U[n][n];
    float b[n], y[n], x[n];
    int i, j, k;
    
    //Datos del problema
    float Q = 1.0;
    float c_in = 1.0;
    float V[4] = {1.0, 1.2, 0.9, 1.5};
    float k_const[4] = {0.10, 0.08, 0.12, 0.09};  // Cambié el nombre para evitar conflicto

    //Inicializar matrices L y U
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i == j)
                L[i][j] = 1.0;  //Diagonal de L es 1
            else
                L[i][j] = 0.0;
            U[i][j] = 0.0;  //Inicializar U en 0
        }
    }

    printf("METODO DE DESCOMPOSICION LU - 4 REACTORES CSTR\n");
    printf("Datos del sistema:\n");
    printf("Q = %.2f m3/s, c_in = %.2f mol/m3\n", Q, c_in);
    printf("Volumenes: [%.1f, %.1f, %.1f, %.1f] m3\n", V[0], V[1], V[2], V[3]);
    printf("Constantes k: [%.2f, %.2f, %.2f, %.2f] s-1\n\n", k_const[0], k_const[1], k_const[2], k_const[3]);
    
    //Construcción automática de la matriz A y vector b
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            A[i][j] = 0.0;
        }
        b[i] = 0.0;
    }
    
    //Reactor 1: (Q + k1*V1)*c1 = Q*c_in
    A[0][0] = Q + k_const[0] * V[0];
    b[0] = Q * c_in;
    
    //Reactor 2: -Q*c1 + (Q + k2*V2)*c2 = 0
    A[1][0] = -Q;
    A[1][1] = Q + k_const[1] * V[1];
    b[1] = 0.0;
    
    //Reactor 3: -Q*c2 + (Q + k3*V3)*c3 = 0
    A[2][1] = -Q;
    A[2][2] = Q + k_const[2] * V[2];
    b[2] = 0.0;
    
    //Reactor 4: -Q*c3 + (Q + k4*V4)*c4 = 0
    A[3][2] = -Q;
    A[3][3] = Q + k_const[3] * V[3];
    b[3] = 0.0;

    //Matriz original
    printf("Matriz del sistema A | b:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%10.6f ", A[i][j]);
        }
        printf("| %10.6f\n", b[i]);
    }

    //Descomposición LU
    printf("\nDESCOMPOSICION LU\n");
    for (k = 0; k < n; k++) {
        //Calculamos elementos de la fila k de U
        for (j = k; j < n; j++) {
            float suma = 0.0;
            for (i = 0; i < k; i++) {
                suma += L[k][i] * U[i][j];
            }
            U[k][j] = A[k][j] - suma;
            printf("U[%d][%d] = A[%d][%d] - (L[%d][i]*U[i][%d]) = %.6f\n", 
                   k+1, j+1, k+1, j+1, k+1, j+1, U[k][j]);
        }

        //Calculamos elementos de la columna k de L
        for (i = k + 1; i < n; i++) {
            float suma = 0.0;
            for (j = 0; j < k; j++) {
                suma += L[i][j] * U[j][k];
            }
            if (fabs(U[k][k]) < 1e-10) {
                printf("\nError: Division por cero en U[%d][%d] = %.6f\n", k+1, k+1, U[k][k]);
                return 1;
            }
            L[i][k] = (A[i][k] - suma) / U[k][k];
            printf("L[%d][%d] = (A[%d][%d] - (L[%d][j]*U[j][%d])) / U[%d][%d] = %.6f\n", 
                   i+1, k+1, i+1, k+1, i+1, k+1, k+1, k+1, L[i][k]);
        }
    }

    //Matrices L y U
    printf("\nMATRIZ L (Triangular Inferior)\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%10.6f ", L[i][j]);
        }
        printf("\n");
    }

    printf("\nMATRIZ U (Triangular Superior)\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%10.6f ", U[i][j]);
        }
        printf("\n");
    }

    //Ly = b 
    printf("\n Ly = b\n");
    for (i = 0; i < n; i++) {
        float suma = 0.0;
        for (j = 0; j < i; j++) {
            suma += L[i][j] * y[j];
        }
        y[i] = b[i] - suma;  // L[i][i] siempre es 1
        printf("y[%d] = b[%d] - (L[%d][j]*y[j]) = %.6f\n", i + 1, i + 1, i + 1, y[i]);
    }

    //Ux = y
    printf("\nUx = y\n");
    for (i = n - 1; i >= 0; i--) {
        float suma = 0.0;
        for (j = i + 1; j < n; j++) {
            suma += U[i][j] * x[j];
        }
        if (fabs(U[i][i]) < 1e-10) {
            printf("\nError: Division por cero en U[%d][%d] = %.6f\n", i+1, i+1, U[i][i]);
            return 1;
        }
        
        x[i] = (y[i] - suma) / U[i][i];
        printf("c[%d] = (y[%d] - (U[%d][j]*c[j])) / U[%d][%d] = %.6f\n", 
               i + 1, i + 1, i + 1, i + 1, i + 1, x[i]);
    }

    //Resultados
    printf("\nRESULTADOS FINALES\n");
    printf("\nCONCENTRACIONES DE ETILENO:\n");
    for (i = 0; i < n; i++) {
        printf("Reactor %d: c%d = %.6f mol/m3\n", i + 1, i + 1, x[i]);
    }
    return 0;
}