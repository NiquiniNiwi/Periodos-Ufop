#include <stdio.h>
#include <math.h>

double funcao(double x) {
    return pow(x,3) + (0.4133*pow(x,2)) - (4*x) - 1;
}

double funcIteracao(double a, double b, double fa, double fb) {
    return ((a*fb) - (b*fa)) / (fb-fa);
}

int main()
{
    double fa, fb, xk, fxk;
    int interval = 5;
    double a = 1, b = 2;
    printf("k  |ak        |bk        |xk        |f(xk)        ||f(xk)|      |\n");
    for(int i = 0; i < interval; i++) {
        fa = funcao(a);
        fb = funcao(b);
        xk = funcIteracao(a, b, fa, fb);
        fxk = funcao(xk);
        printf("%d  |  %.4lf|  %.4lf|  %.4lf|  %.4lf \n", i, a, b, xk, fxk);
        if((fa * fxk) < 0) {
            b = xk;
        } else {
            a = xk;
        }
    }
    
    return 0;
}