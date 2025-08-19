#include <stdio.h>
#include <math.h>

int main()
{
  float x, ea, valact, valtant, serie;
  int n,i;

  printf("Porfavor ingresa el valor de x: ");
  scanf("%f",&x);
  printf("Ahora ingresa el valor de n: ");
  scanf("%d",&n);

  for (i=1; i<n; i++)
  {
    serie=((pow(x,i)/tgamma(i+1))+1);
    ea=(valact-valtant)/valact;
    printf("Su aproximación de error es de %i = %f\n",i,serie);

  }

return 0;

}