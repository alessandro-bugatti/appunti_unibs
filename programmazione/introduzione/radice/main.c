#include <stdio.h>

int main(void) {
    double N, a, b, m;
    const double PRECISIONE = 0.0001;
    printf("Inserisci il numero: ");
    scanf("%lf", &N);
    a = 1;
    b = N;
    while(b - a > PRECISIONE) {
        m = (a + b)/2;
        if (m*m > N) {
            b = m;
        }
        if (m*m < N) { //else
            a = m;
        }
    }
    printf("La radice di %lf è %lf\n", N, m);
    return 0;
}
