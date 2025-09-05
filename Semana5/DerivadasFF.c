#include<stdio.h>
#include<math.h>
//Función
float fx(float x);

int main()
{
    float a,b,h;
    int n=((b-a)/h+1),i;
    //Función y primeras derivadas 
    float x[n],fpa[n],fpat[n],fpc[n];
    //Segundas derivadas 
    float spa[n],spat[n],spc[n];
    a=2;
	b=-2;
	h=0.25;
	
    for(i=0;i<n;i++)
    {
        x[i]=a+i*h;
    }

    for(i=0;i<n;i++)
    {
        //Primera derivada hacia adelante
        fpa[i]=(fx(x[i+1]) - fx(x[i])) / h; 
        printf("Adelante %f \n %f ",x[i],fpa[i]);
        //Primera derivada hacia atrás 
        fpat[i]=(fx(x[i]) - fx(x[i-1])) / h; 
        printf("Atrás %f \n %f ",x[i],fpa[i]);
        //Primera derivada centrada 
        fpc[i]=(fx(x[i+1]) - fx(x[i-1])) / h; 
        printf("Centrada %f \n %f ",x[i],fpa[i]);
        //Segunda derivada hacia adelante
        spa[i] = (fx(x[i+2]) - 2*fx(x[i+1]) + fx(x[i])) / (h*h);
        //Segunda derivada hacia atrás 
        spat[i] = (fx(x[i] - 2)*fx(x[i-1]) + fx(x[i-2])) / (h*h); 
        //Segunda derivada centrada 
        spc[i] = (fx(x[i+1]) - 2*fx(x[i]) + fx(x[i-1])) / (h*h);

    }

}

float fx(float x)
{
    float f;
    f=(x*x*x)-(2*x)+4;
    return f;
}
