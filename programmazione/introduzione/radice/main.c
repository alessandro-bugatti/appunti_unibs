#include <math.h>
#include <stdio.h>

#define PRECISION 0.000001

int main(void) {
    double n, radice, a, b, m;
    printf("Inserisci un numero maggiore o uguale a 1:");
    scanf("%lf", &n);
    a = 1;
    b = n;
    while (b - a > PRECISION) {
        m = (a + b) / 2;
        if (m * m > n){
            b = m;
        }
        else {
            a = m;
        }

    }
    radice = sqrt(n);
    printf("La radice di %lf calcolata con sqrt è %lf\n", n, radice);
    printf("La radice di %lf calcolata con bisezione è %lf\n", n, m);
    return 0;
}