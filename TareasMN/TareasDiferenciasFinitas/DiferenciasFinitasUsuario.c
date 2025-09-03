#include <stdio.h>
#include <math.h>
//Programa con valores que dara el usuario 
int main()
{
    double fi,fi_1,fi1,e;
    double atras,adelante,centrada;
    double erroratras,erroradelante,errorcentrada;
    double xi,xi_1,xi1;

    //Pedimos al usuario los valores
   printf("Ingresa el valor de xi");
   scanf("&f",xi);
   printf("Ingresa el valor de xi+1");
   scanf("&f",xi1);
   printf("Ingresa el valor de xi-1");
   scanf("&f",xi_1);
   printf("Ingresa el valor de de la función de xi");
   scanf("&f",fi);
   printf("Ingresa el valor de de la función de xi+1");
   scanf("&f",fi1);
   printf("Ingresa el valor de de la función de xi-1");
   scanf("&f",fi_1);
    
    //Derivadas funcionales
    adelante=(fi1-fi)/(xi1-xi);
	atras=(fi-fi_1)/(xi1-xi_1);
	centrada=(fi1-fi_1)/(xi1-xi_1);

    //Errores 
    erroradelante=(e-adelante)/e;
	erroratras=(e-atras)/e;
	errorcentrada=(e-centrada)/e;

    //Resultados
    printf("Derivada aproxiamda hacia adelante %.4f \n",adelante);
    printf("Error hacia adelante %.4f\n",erroradelante);
    printf("Derivada aproxiamda hacia atras %.4f\n",atras);
    printf("Error hacia adelante %.4f\n",erroratras);
    printf("Derivada aproxiamda centrada %.4f\n",centrada);
    printf("Error centrado %.4f\n",errorcentrada);




}