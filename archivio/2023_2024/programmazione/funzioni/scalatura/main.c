#include <stdio.h>

void scalatura(double *n, double s){
    *n *= s;
}

int main() {
    double valore = 10, scala = 0.5;
    scalatura(&valore, scala);
    printf("%lf", valore);
    return 0;
}
