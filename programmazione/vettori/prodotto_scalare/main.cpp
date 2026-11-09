#include <iostream>

#define N 3

float prodotto_scalare(float a[], float b[], int n) {
    float risultato = 0;
    for (int i = 0; i < n; ++i) {
        risultato += a[i] * b[i];
    }
    return risultato;
}

int main() {
    float a[N] = {2.6, -5.1, 3};
    float b[N] = {-2.3, 6.34, 1.99};
    float c = prodotto_scalare(a, b, N);
    printf("Il prodotto scalare vale: %f\n", c);
    return 0;
}
