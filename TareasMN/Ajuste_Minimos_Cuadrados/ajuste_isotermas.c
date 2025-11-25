#include <stdio.h>
#include <math.h>

#define MAX 500
#define LR 0.00000001 
#define ITER 40000       

double aw[MAX], Xe[MAX];
int N;

double peleg(double aw, double b0, double b1, double b2, double b3) {
    double t = pow(aw, b1);
    double denom = b2 + b3 * t;

    if (fabs(denom) < 1e-9)
        denom = (denom < 0 ? -1e-9 : 1e-9);

    return (b0 * t) / denom;
}

double dlp(double aw, double b0, double b1, double b2, double b3) {
if (aw <= 0 || aw >= 1) return 0;
double x = log(-log(aw));
return b0 + b1*x + b2*x*x + b3*x*x*x;
}

double chi2_peleg(double b0, double b1, double b2, double b3) {
double sum = 0;
for(int i=0; i<N; i++) {
double pred = peleg(aw[i], b0, b1, b2, b3);
sum += pow(Xe[i] - pred, 2);
}
return sum;
}

double chi2_dlp(double b0, double b1, double b2, double b3) {
double sum = 0;
for(int i=0; i<N; i++) {
double pred = dlp(aw[i], b0, b1, b2, b3);
sum += pow(Xe[i] - pred, 2);
}
return sum;
}

int main() {

//Leer datos de archivo externo
FILE *f = fopen("datos.csv", "r");
if(!f) {
    printf("No se pudo abrir datos.csv\n");
    return 1;
}

N = 0;
while(!feof(f)) {
    fscanf(f, "%lf,%lf", &aw[N], &Xe[N]);
    N++;
}
fclose(f);

printf("Se leyeron %d datos.\n", N);

//Modelo Peleg
double b0 = 0.1;
double b1 = 0.1;
double b2 = 0.5;
double b3 = 0.1;


for(int it=0; it<ITER; it++) {

    double d0=0, d1=0, d2=0, d3=0;

    for(int i=0; i<N; i++) {

        double t = pow(aw[i], b1);
        double denom = b2 + b3 * t;

        if (fabs(denom) < 1e-12) denom = 1e-12;

        double p = peleg(aw[i], b0, b1, b2, b3);
        double e = Xe[i] - p;
        double dp_db0 = t / denom;
        double dp_db1 = (b0 * t * log(aw[i]) * b2) / (denom * denom);
        double dp_db2 = -(b0 * t) / (denom * denom);
        double dp_db3 = -(b0 * t * t) / (denom * denom);

        d0 += -2 * e * dp_db0;
        d1 += -2 * e * dp_db1;
        d2 += -2 * e * dp_db2;
        d3 += -2 * e * dp_db3;
    }

    b0 -= LR * d0;
    b1 -= LR * d1;
    b2 -= LR * d2;
    b3 -= LR * d3;
}

printf("MODELO PELEG \n");
printf("b0 = %lf\n", b0);
printf("b1 = %lf\n", b1);
printf("b2 = %lf\n", b2);
printf("b3 = %lf\n", b3);
printf("Chi2 final = %lf\n", chi2_peleg(b0,b1,b2,b3));


//Modelo DLP
double c0 = 2.0, c1 = 0.5, c2 = 0.1, c3 = 0.05;

for(int it=0; it<ITER; it++) {

    double d0=0, d1=0, d2=0, d3=0;

    for(int i=0; i<N; i++) {

        if (aw[i] <= 0 || aw[i] >= 1) continue;

        double x = log(-log(aw[i]));
        double p = dlp(aw[i], c0, c1, c2, c3);
        double e = Xe[i] - p;

        double dp_dc0 = 1;
        double dp_dc1 = x;
        double dp_dc2 = x*x;
        double dp_dc3 = x*x*x;

        d0 += -2 * e * dp_dc0;
        d1 += -2 * e * dp_dc1;
        d2 += -2 * e * dp_dc2;
        d3 += -2 * e * dp_dc3;
    }

    c0 -= LR * d0;
    c1 -= LR * d1;
    c2 -= LR * d2;
    c3 -= LR * d3;
}

printf("MODELO DLP\n");
printf("c0 = %lf\n", c0);
printf("c1 = %lf\n", c1);
printf("c2 = %lf\n", c2);
printf("c3 = %lf\n", c3);
printf("Chi2 final = %lf\n", chi2_dlp(c0,c1,c2,c3));

return 0;

}
