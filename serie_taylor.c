#include <stdio.h>
#include <math.h>

//Funcion factorial
long double factorial(int n) {
    long double f = 1.0;
    for (int i = 1; i <= n; i++) {
        f *= i;
    }
    return f;
}

int main() {
    int op, nmax, n, residuo;
    long double fact, x, h, x0, f, valorreal, xi, error, r;
    n = 0;
    fact = 1;

    printf("Escoge qué función quieres aproximar\n");
    printf("1. e^x, 2. sen(x), 3. cos(x), 4. arctan(x), 5. ln(1+x)\n");
    scanf("%d", &op);
    printf("Ingresa el punto en el que deseas calcular el valor de tu función: ");
    scanf("%Lf", &x);
    printf("Ingresa tu valor de h: ");
    scanf("%Lf", &h);

    x0 = x - h;
    xi = (x + x0) / 2.0;

    printf("Ingresa el número de aproximaciones que deseas: ");
    scanf("%d", &nmax);
    switch(op) {
        case 1: // e^x
            valorreal = expl(x);
            while (n < nmax) {
                if (n == 0) {
                    f = expl(x0);
                    r = expl(xi) * h;
                } else {
                    f = f + (expl(x0) * powl(h, n)) / factorial(n);
                    r = (expl(xi) * powl(h, n+1)) / factorial(n+1);
                } 
                error = valorreal - f;
                printf("%Lf %Lf %Lf\n", f, r, error);
                n++;
            } 
            break;

        case 2: // sen(x)
            valorreal = sinl(x);
            while (n < nmax) {
                // residuo <- n MOD 4
                residuo = n % 4;
                switch (residuo) {
                    case 0:
                        if (n == 0) {
                            f = sinl(x0);
                            r = cosl(xi) * h;
                        } else { // SiNo
                            f = f + (sinl(x0) * powl(h, n))/factorial(n);
                            r = (cosl(xi) * powl(h, n+1))/factorial(n+1);
                        } 
                        break;
                    case 1:
                        f = f + (cosl(x0) * powl(h, n))/factorial(n);
                        r = (-sinl(xi) * powl(h, n+1))/factorial(n+1);
                        break;
                    case 2:
                        f = f + (-sinl(x0) * powl(h, n))/factorial(n);
                        r = (-cosl(xi) * powl(h, n+1))/factorial(n+1);
                        break;
                    case 3:
                        f = f + (-cosl(x0) * powl(h, n))/factorial(n);
                        r = (sinl(xi) * powl(h, n+1))/factorial(n+1);
                        break;
                } 
                error = valorreal - f;
                printf("%Lf %Lf %Lf\n", f, r, error);
                n++;
            } 
            break;

        case 3: // cos(x)
            valorreal = cosl(x);
            while (n < nmax) {
                residuo = n % 4;
                switch (residuo) {
                    case 0:
                        if (n == 0) {
                            f = cosl(x0);
                            r = -sinl(xi) * h;
                        } else {
                            f = f + (cosl(x0) * powl(h, n))/factorial(n);
                            r = (-sinl(xi) * powl(h, n+1))/factorial(n+1);
                        }
                        break;
                    case 1:
                        f = f + (-sinl(x0) * powl(h, n))/factorial(n);
                        r = (-cosl(xi) * powl(h, n+1))/factorial(n+1);
                        break;
                    case 2:
                        f = f + (-cosl(x0) * powl(h, n))/factorial(n);
                        r = (sinl(xi) * powl(h, n+1))/factorial(n+1);
                        break;
                    case 3:
                        f = f + (sinl(x0) * powl(h, n))/factorial(n);
                        r = (cosl(xi) * powl(h, n+1))/factorial(n+1);
                        break;
                }
                error = valorreal - f;
                printf("%Lf %Lf %Lf\n", f, r, error);
                n++;
            }
            break;

        case 4: // arctan(x)
            valorreal = atanl(x);
            while (n < nmax) {
                switch (n) {
                    case 0:
                        f = atanl(x0);
                        r = (1/(1+powl(xi,2))) * h;
                        break;
                    case 1:
                        f = f + ((1/(1+powl(x0,2))) * h)/factorial(1);
                        r = ((-2*xi)/powl(1+powl(xi,2),2)) * powl(h,2)/factorial(2);
                        break;
                    case 2:
                        f = f + (((-2*x0)/powl(1+powl(x0,2),2)) * powl(h,2))/factorial(2);
                        r = ((6*powl(xi,2) - 2)/powl(1+powl(xi,2),3)) * powl(h,3)/factorial(3);
                        break;
                    case 3:
                        f = f + (((6*powl(x0,2) - 2)/powl(1+powl(x0,2),3)) * powl(h,3))/factorial(3);
                        r = ((-24*powl(xi,3)+24*xi)/powl(1+powl(xi,2),4)) * powl(h,4)/factorial(4);
                        break;
                } 
                error = valorreal - f;
                printf("%Lf %Lf %Lf\n", f, r, error);
                n++;
            } 
            break;

        case 5: // ln(1+x)
            valorreal = logl(1+x);
            
            if (x0 <= -1) {
                printf("Funcion no definida\n");
            } else { 
                while (n < nmax) {
                    if (n == 0) {
                        f = logl(1+x0);
                        r = (1/(1+xi)) * h;
                    } else {
                        f = f + (powl(-1, n+1) * powl(h, n))/n;
                        r = (powl(-1, n+2) * powl(h, n+1))/(n+1);
                    } 
                    error = valorreal - f;
                    printf("%Lf %Lf %Lf\n", f, r, error);
                    n++;
                } 
            } 
            break;
        default:
            printf("Opcion no valida\n");
            break;
    } 

    return 0;
}
