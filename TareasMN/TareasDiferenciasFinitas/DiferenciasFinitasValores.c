#include <stdio.h>
#include <math.h>
//Programa con valores dados
int main()
{
    double f0,f05,f1,e;
    double atras,adelante,centrada;
    double erroratras,erroradelante,errorcentrada;
    double xi,xi_1,xi1;

    //Valores dados
    f0=1.2;
	f05=0.925;
	f1= 0.2;
	e=-0.925;
	xi=0.5;
	xi1=1;
	xi_1= 0;
    
    //Derivadas funcionales
    adelante=(f1-f05)/(xi1-xi);
	atras=(f05-f0)/(xi1-xi_1);
	centrada=(f1-f0)/(xi1-xi_1);

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