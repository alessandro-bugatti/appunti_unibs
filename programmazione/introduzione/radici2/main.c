#include <stdio.h>

int main(void) {
    double n, medio,a,b;
    printf("Inserisci il valore di n:");
    scanf("%lf",&n);
    a=0;
    b=n;
    medio=(a+b)/2;
    while (b-a>0.00001) {
        if (medio*medio>n) {
            b=medio;
        }else {
            a=medio;

        }
        medio=(a+b)/2;
    }
    printf("La radice di %lf vale %lf",n,medio);
    return 0;
}
