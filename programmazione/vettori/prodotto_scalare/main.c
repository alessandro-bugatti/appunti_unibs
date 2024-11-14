#include <stdio.h>

#define N 3

float prodotto_scalare(float v1[], float v2[], int n) {
    int risultato = 0;
    for (int i = 0; i < n; ++i) {
        risultato += v1[i]*v2[i];
    }
    return risultato;
}

int main(void) {
    float v1[N], v2[N];
    //Inserimento valori, da fare

    float r = prodotto_scalare(v1, v2, N);
    printf("Il prodotto scalare è %f\n", r);
    return 0;
}
