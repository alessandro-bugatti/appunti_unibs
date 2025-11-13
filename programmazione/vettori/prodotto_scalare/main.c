#include <stdio.h>


float prodotto_scalare(float a[], float b[], int n) {
    float somma = 0;
    for (int i = 0; i < n; ++i) {
        somma += a[i] * b[i];
    }
    return somma;
}

int main(void) {
    float v1[3], v2[3];
    v1[0] = 0.75;
    v1[1] = 2.75;
    v1[2] = 1.75;
    v2[0] = 0.7;
    v2[1] = 10.175;
    v2[2] = 3.75;
    printf("%f\n", prodotto_scalare(v1, v2, 3));
    return 0;
}