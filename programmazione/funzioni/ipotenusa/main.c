#include <math.h>
#include <stdio.h>

double calcola_ipotenusa(double c1, double c2) {
    double somma_quadrati = c1 * c1 + c2 * c2;
    double ipotenusa = sqrt(somma_quadrati);
    return ipotenusa;
}

int main(void) {
    double c, d = 40;
    c = sqrt(d);
    printf("%lf\n", c);
    double ipotenusa = calcola_ipotenusa(3, 4);
    printf("%lf\n", ipotenusa);
    return 0;
}