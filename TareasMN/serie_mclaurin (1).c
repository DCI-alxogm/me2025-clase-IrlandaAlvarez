#include <stdio.h>
#include <math.h>

int main()
{
  // La variable ea se iguala a 50 para darle un valor grande para que el ea<=Es se cumpla y el ciclo entre por primera vez
  //La variable termino es para cada nuevo termino de la serie 
    float x, ea=50.0, Es; 
    float valact, valtant, termino;
    int n, i;

    printf("Por favor ingrese el valor de x: ");
    scanf("%f", &x);

    printf("Ingrese el porcentaje de error deseado: ");
    scanf(" %f", &Es);

    // Si aun existen valores posibles de error se sigue preguntando por n
    while (ea > Es) {
        printf("Ingrese el numero de terminos a usar: ");
        scanf("%d", &n);
        // Los valores de abajo se igualan a 1 para reiniciar la serie
        valact = 1.0;
        termino = 1.0;

        for (i = 1; i <= n; i++) {
            //La función pow calcula una potencia, se coloca primero la base y después el exponente
            //La función tgamma calcula el factorial
            termino = pow(x, i) / tgamma(i + 1);
            //Esto actualiza la aproximación
            valact += termino;
        }

        // La función fabs es para que el error siempre salga positivo, ya que existe la posibilidad de que de negativo por la misma formula
        ea = fabs((exp(x) - valact) / exp(x)) * 100.0;

        printf("Con n = %d, apaoximacion = %f, error = %f%%\n", n, valact, ea);

        if (ea <= Es) {
            printf("El número de terminos es correcto para el error deseado \n");
            break;
        } else {
            printf("Aun no se alcanza el error, intenta con mas terminos \n");
        }
    }

    return 0;
}
