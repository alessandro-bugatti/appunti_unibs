#include <stdio.h>
#include <stdlib.h>

#define N 100

void filtraggio(float v[], int n, int k) {
    float appoggio[N];
    for (int i = 0; i < n; ++i) {
        float somma = 0;
        int conta = 0;
        for (int j = i - k; j < i + k + 1; ++j) {
            if ( j >= 0 && j < n) {
                somma += v[j];
                conta++;
            }
        }
        appoggio[i] = somma / conta;
    }
    for (int i = 0; i < n; ++i) {
        v[i] = appoggio[i];
    }
}

void inizializza(float v[], int n) {
    for (int i = 0; i < n; ++i) {
        v[i] = rand()%1000 / 10.0;
    }
}

void stampa(float v[], int n) {
    for (int i = 0; i < n; ++i) {
        printf("%6.1f", v[i]);
    }
    printf("\n");
}

int main(void) {
    float v[N];
    int n = 10;
    inizializza(v, n);
    stampa(v, n);
    filtraggio(v, n, 1);
    stampa(v, n);
    return 0;
}
