#include <stdio.h>
#include <math.h>

int main()
{
  float a,b,c,x1,x2,discr,xi1,xi2;
  printf("Ingrese el valor de a: ");
  scanf("%f",&a);
  printf("Ingrese el valor de b: ");
  scanf("%f",&b);
  printf("Ingrese el valor de c: ");
  scanf("%f",&c);

  if(a==0)
  {
    if(b!=0)
    {
      x1=-c/b;
      printf("x1= %f ",x1);
    }
    else
    {
      printf("Solución trivial ");
    }
  }
     else 
     {
      discr=b*b-4*a*c;

      if(discr>=0)
      {
        x1=(-b +sqrt(discr))/(2*a);
        x2=(-b -sqrt(discr))/(2*a);
        printf("x1= %f\n",x1);
        printf("x2= %f\n",x2);
      }
     }
     else
     {
      x1=-b/(2*a);
      xi1=sqrt(fabs(discr))/(2*a);
      x2=x1;
      xi2=-xi1;
      printf("xi1= %f\n",xi1);
      printf("xi2= %f\n",xi2);
     }
  }
  return 0;
}