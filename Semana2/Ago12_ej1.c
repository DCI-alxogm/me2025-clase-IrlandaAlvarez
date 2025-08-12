#include <stdio.h>
#include <math.h>

int main()
{
  int numeros[5];
  int indx;
  float resultados[5];

  //Arreglo
  numeros[0]=1;
  numeros[1]=2;
  numeros[2]=3;
  numeros[3]=4;
  numeros[4]=5;

  //printf("x  x² log(x+1) exp(x)+cos(x)\n");

  for(indx=0;indx<5;indx++)
  {
    //printf("%d %f\n",numeros[indx],numeros[indx]%2);
    if(numeros[indx]%2==0)
    {
      resultados[indx]=log10(numeros[indx]+1);
      printf("x=%d log(x+1)=%f\n",numeros[indx],resultados[indx]);
    }
    else 
    {
      resultados[indx]=exp(numeros[indx])+cos(numeros[indx]);
      printf("x=%d exp(x)+cos(x)=%f\n",numeros[indx],resultados[indx]);
    }
    //printf("%f %f %f %f\n",numeros[indx],numeros[indx]*numeros[indx],log10(numeros[indx]+1),exp(numeros[indx])+cos(numeros[indx]));
  }
  printf("\nResultados:\n");
  for(indx=0;indx<5;indx++)
  {
    printf("%f\n",resultados[indx]);
  }
  //Redondeo o trunqueo 
  float suma;
  suma=3.141592653+3.14159265;
  printf("\nSuma de pis:\n");
  printf("Pi+Pi=%.8f",suma);

}