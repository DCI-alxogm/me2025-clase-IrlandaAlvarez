#include <stdio.h>
#include <math.h>

int main()
{
  int numero;
  char cont;

  do
  {
    printf("Coloca un número entero: ");
  scanf("%d",&numero);

  //Comprobar si es par o impar

  if(numero % 2==0)
  {
    printf("El número %d es par\n",numero);

  }
  else 
  {
    printf("El número %d es impar\n",numero);
  }
   printf("¿Quieres ingresar otro número?(S=si/N=no)");
   scanf(" %c",&cont);
  }
  while(cont=='S'||cont=='s');
  
  printf("Programa finalizado");

  return 0;

}