#include <stdio.h>

#define PRECISIONE 0.000001

int main() {
    double N,a,b,m;
    printf("inserisci N: ");
    scanf("%lf",&N);
    a = 0;
    b = N;
    while(b - a > PRECISIONE){
        m = (a + b) / 2;
        if(m * m > N){
            b = m;
        }
        else{
            a = m;
        }
    }
    printf("il valore della radice di %lf è %lf",N ,m);
    return 0;
}
