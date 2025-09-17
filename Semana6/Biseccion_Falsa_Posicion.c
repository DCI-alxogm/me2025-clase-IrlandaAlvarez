
#include<stdio.h>
#include<math.h>

float biseccion1();
float biseccion2();
float falsa_posicion1();
float falsa_posicion2();

int main(){
    printf("f(c) = ((gm/c) * (1 - e^(-c/mt)))-v\n");
    printf("Por método de bisección: \n");
    biseccion1();
    
    printf("\nPor método de flasa posición: \n");
    falsa_posicion1();
    
    printf("\nf(x) = x^10 - 1\n");
    printf("Por método de bisección: \n");
    biseccion2();
    
    printf("\nPor método de flasa posición: \n");
    falsa_posicion2();
    
}

//f(c) = ((gm/c) * (1 - e^(-c/mt)))-v
float biseccion1(){
    float a=4, b=20, fa, fb, t=10, m=68.1, v=40, g=9.81, k, kant, fk, erel, emax=0.0001;
    int iter=0, itermax=100;

    printf("%-6s %-12s %-12s %-12s %-12s %-12s %-12s %-12s\n","Iter","a","b","k","f(a)","f(b)","f(k)","E_rel");

    kant=a;

    do{
        k=(a+b)/2;
        fa=(g*m/a)*(1-exp(-a*t/m))-v;
        fb=(g*m/b)*(1-exp(-b*t/m))-v;
        fk=(g*m/k)*(1-exp(-k*t/m))-v;
        erel=(fabs(k - kant)/k)*100;

        printf("%-6d %-12.6f %-12.6f %-12.6f %-12.5f %-12.5f %-12.5f %-12.6f\n",
        iter, a, b, k, fa, fb, fk, erel);

        if(fa*fk<0){
            b=k;
        }
        else{
            a=k;
        }

        if(fk==0){
            break;
        }
        kant=k;
        iter++;

    } while(erel > emax && iter < itermax);
}

float falsa_posicion1(){
    float a=4, b=20, fa, fb, t=10, m=68.1, v=40, g=9.81, k, kant, fk, erel, emax=0.0001;
    int iter=0, itermax=100;

    printf("%-6s %-12s %-12s %-12s %-12s %-12s %-12s %-12s\n","Iter","a","b","k","f(a)","f(b)","f(k)","E_rel");

    kant=a;

    do{
        fa=(g*m/a)*(1-exp(-a*t/m))-v;
        fb=(g*m/b)*(1-exp(-b*t/m))-v;
        
        k=(a*fb - b*fa)/(fb - fa);
        
        fk=(g*m/k)*(1-exp(-k*t/m))-v;
        erel=(fabs(k - kant)/k)*100;

        printf("%-6d %-12.6f %-12.6f %-12.6f %-12.5f %-12.5f %-12.5f %-12.6f\n",
        iter, a, b, k, fa, fb, fk, erel);

        if(fa*fk<0){
            b=k;
        }
        else{
            a=k;
        }

        if(fk==0){
            break;
        }
        kant=k;
        iter++;

    } while(erel > emax && iter < itermax);
}

//f(x) = x^10 - 1
float biseccion2(){
    float a=0, b=1.3, fa, fb, k, kant, fk, erel, emax=0.0001;
    int iter=0, itermax=100;
    
    printf("%-6s %-12s %-12s %-12s %-12s %-12s %-12s %-12s\n","Iter","a","b","k","f(a)","f(b)","f(k)","E_rel");
    
    kant=a;
    
    do{
        k=(a+b)/2;
        fa=pow(a,10) - 1;
        fb=pow(b,10) - 1;
        fk=pow(k,10) - 1;
        erel=(fabs(k - kant)/k)*100;
        
        printf("%-6d %-12.6f %-12.6f %-12.6f %-12.5f %-12.5f %-12.5f %-12.6f\n",
        iter, a, b, k, fa, fb, fk, erel);

        if(fa*fk<0){
            b=k;
        }
        else{
            a=k;
        }

        if(fk==0){
            break;
        }
        kant=k;
        iter++;
        
    }  while(erel > emax && iter < itermax);
}

float falsa_posicion2(){
    float a=0, b=1.3, fa, fb, k, kant, fk, erel, emax=0.0001;
    int iter=0, itermax=100;
    
    printf("%-6s %-12s %-12s %-12s %-12s %-12s %-12s %-12s\n","Iter","a","b","k","f(a)","f(b)","f(k)","E_rel");
    
    kant=a;
    
    do{
        fa=pow(a,10) - 1;
        fb=pow(b,10) - 1;
        
        k=(a*fb - b*fa)/(fb - fa);
        
        fk=pow(k,10) - 1;
        erel=(fabs(k - kant)/k)*100;
        
        printf("%-6d %-12.6f %-12.6f %-12.6f %-12.5f %-12.5f %-12.5f %-12.6f\n",
        iter, a, b, k, fa, fb, fk, erel);

        if(fa*fk<0){
            b=k;
        }
        else{
            a=k;
        }

        if(fk==0){
            break;
        }
        kant=k;
        iter++;
        
    }  while(erel > emax && iter < itermax);
}