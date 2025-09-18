#include <stdio.h>
#include <math.h>

float punto_fijo();
float Newton_Rapson();

int main()
{
    printf("Método del punto fijo: \n");
    punto_fijo();
    
    printf("\n\nMétodo de Newton - Rapson: \n");
    Newton_Rapson();
}

float punto_fijo(){
    float xant=0, g, x, error, errormax=0.0001;
    int iter=0, itermax=100;
    
    printf("%-6s %-12s %-12s\n","Iter","g(x)","Error");
    
    do{
        
        g = exp(-xant);
        
        error = (fabs(g-xant)/g)*100;
        
        printf("%-6d %-12.6f %-12.6f\n",
        iter, g, error);
        
        xant = g;
        
        iter++;
        
    } while (error>errormax && iter<itermax);
}

float Newton_Rapson(){
    float xant=0, g, x, error, errormax=0.0001;
    int iter=0, itermax=100;
    
    printf("%-6s %-12s %-12s\n","Iter","g(x)","Error");
    
    do{
        
        g = xant + ((exp(-xant) - xant) / (exp(-xant) + 1));
        
        error = (fabs(g-xant)/g)*100;
        
        printf("%-6d %-12.6f %-12.6f\n",
        iter, g, error);
        
        xant = g;
        
        iter++;
        
    } while (error>errormax && iter<itermax);
}