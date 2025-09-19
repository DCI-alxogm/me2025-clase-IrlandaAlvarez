#include <stdio.h>
#include <math.h>

// Prototipos
float punto_fijo();
float Newton_Rapson();
float Secante();
float Newton_Multiples();

int main()
{
    int opcion;
        printf("\nMétodos numéricos para f(x) = e^(-x) - x\n");
        printf("1. Punto fijo\n");
        printf("2. Newton-Rapson\n");
        printf("3. Secante\n");
        printf("4. Newton-Rapson con raíces múltiples\n");
        printf("Seleccione el método: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                printf("\nMétodo del punto fijo:\n");
                punto_fijo();
                break;
            case 2:
                printf("\nMétodo de Newton-Rapson:\n");
                Newton_Rapson();
                break;
            case 3:
                printf("\nMétodo de la Secante:\n");
                Secante();
                break;
            case 4:
                printf("\nMétodo de Newton-Rapson con raíces múltiples:\n");
                Newton_Multiples();
                break;
            default:
                printf("Opción inválida.\n");
        }

    return 0;
}

float punto_fijo(){
    float xant=0, g, error, errormax=0.0001;
    int iter=0, itermax=100;

    printf("%-6s %-12s %-12s\n","Iter","g(x)","Error");

    do{
        g = exp(-xant);   // g(x) = e^(-x)

        error = (fabs(g-xant)/g)*100;

        printf("%-6d %-12.6f %-12.6f\n", iter, g, error);

        xant = g;
        iter++;

    } while (error>errormax && iter<itermax);

    return xant;
}

float Newton_Rapson(){
    float xant=0, g, error, errormax=0.0001;
    int iter=0, itermax=100;

    printf("%-6s %-12s %-12s\n","Iter","x","Error");

    do{
        g = xant - ( (exp(-xant)-xant) / (-exp(-xant)-1) );

        error = (fabs(g-xant)/g)*100;

        printf("%-6d %-12.6f %-12.6f\n", iter, g, error);

        xant = g;
        iter++;

    } while (error>errormax && iter<itermax);

    return xant;
}

float Secante(){
    float x0=0, x1=0.5, x2, f0, f1, error, errormax=0.0001;
    int iter=0, itermax=100;

    printf("%-6s %-12s %-12s\n","Iter","x","Error");

    do{
        f0 = exp(-x0) - x0;
        f1 = exp(-x1) - x1;

        if (fabs(f1-f0) < 1e-12) {
            printf("Error: división por cero\n");
            break;
        }

        x2 = x1 - f1*(x1-x0)/(f1-f0);

        error = (fabs(x2-x1)/x2)*100;

        printf("%-6d %-12.6f %-12.6f\n", iter, x2, error);

        x0 = x1;
        x1 = x2;
        iter++;

    } while (error>errormax && iter<itermax);

    return x2;
}

float Newton_Multiples(){
    float xant=0, g, error, errormax=0.0001;
    int iter=0, itermax=100;

    printf("%-6s %-12s %-12s\n","Iter","x","Error");

    do{
        float fx = exp(-xant) - xant;
        float dfx = -exp(-xant) - 1;
        float d2fx = exp(-xant);

        float form = dfx*dfx - fx*d2fx;
        if (fabs(form) < 1e-12) {
            printf("Error\n");
            break;
        }

        g = xant - (fx*dfx)/denom;

        error = (fabs(g-xant)/g)*100;

        printf("%-6d %-12.6f %-12.6f\n", iter, g, error);

        xant = g;
        iter++;

    } while (error>errormax && iter<itermax);

    return xant;
}
