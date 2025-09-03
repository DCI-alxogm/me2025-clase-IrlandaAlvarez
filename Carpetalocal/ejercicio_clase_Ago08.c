#include <stdio.h>
#include <math.h>
int main()
{
  float a,b,c,d,e;
  a=1.2;
  b=4.7;
  c=6.1;
  d=9.9;
  e=3.4;

  //Impresión de los números 
  printf("Números: \n %f, %f, %f, %f, %f \n",a,b,c,d,e);

  //Arreglo 
  float i[5];
  i[0]=a;
  i[1]=b;
  i[2]=c;
  i[3]=d;
  i[4]=e;

  //Función x²
  printf("Cuadrados:\n");
  float cuad[5];

  for (int x=0;x<5;x++)
  {
    cuad[x]= i[x]*i[x];
    printf("%f,",cuad[x]);
  }

  //Función log(x+1)
  printf("\n Logaritmo log(x+1):\n");
  float l[5];

  for (int y=0;y<5;y++)
  {
    l[y]=log(i[y]+1);
    printf("%f,",l[y]);
  }

  //Función exponencial + coseno
  printf("\n exp+cos:\n");
  float ex[5];

  for (int z=0;z<5;z++)
  {
    ex[z]=exp(i[z]) + cos (i[z]);
    printf("%f,",ex[z]);
  }

return 0;
}