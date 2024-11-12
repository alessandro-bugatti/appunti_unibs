#include <stdio.h>

void scalatura(float *n, float s) {
    *n = *n * s;
}

float scalatura_per_copia(int n, int s) {
    return n * s;
}

int main(void) {
    float numero = 5.4, s = 0.7;
    printf("Prima della scalatura %f\n", numero);
    scalatura(&numero, s);
    printf("Dopo la scalatura %f\n", numero);
    numero = scalatura_per_copia(numero, s);
    return 0;
}
