#include <stdio.h>
#include <math.h>

int main() {
    double x1,x2,fx1,fx2;
    double xl,xu; 
    double d; 
    int iter;               
    int max_iter = 100;                 

    printf("Metodo de la sección doorada(proporcior aurea)\n");

    printf("\nIngrese el valor de xl:");
    scanf("%f", &xl); 
    printf("\nIngrese el valor de xu: ");
    scanf("%f", &xu); 

    d=0.61803;
    //Valores de x1
    x1=xu+d*(xu-xl);
    x2=xu-d*(xu-xl);
    //Función con ese valor f(x)=x^2-1
    fx1=(x1*x1)-1;
    fx2=(x2*x2)-1;

    //Comprobación de parametros
    if (fx1 > fx2)
    {
        xl=x1;
    }
    else
    {
        xu=x2;
    }
    
    // Resultado final
    double raiz = (xl + xu) / 2.0;
    printf("\nLa raiz aproximada se encuentra en x = %.6f\n", raiz);

    return 0;
}