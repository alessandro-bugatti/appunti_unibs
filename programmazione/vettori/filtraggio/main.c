#include <stdio.h>
#include <stdlib.h>

const int N = 100;

void filtraggio(float v[], int n, int k) {
    float appoggio[N];
    for (int i = 0; i < n; ++i) {
        float media = 0;
        int elementi = 0;
        for (int j = i - k; j <= i + k; ++j) {
            if (j >= 0 && j < N) {
                media += v[j];
                elementi++;
            }
        }
        media /= elementi;
        appoggio[i] = media;
    }
    for (int i = 0; i < N; ++i) {
        v[i] = appoggio[i];
    }
}

int main(void) {
    float valori[N];
    int k = 3;
    for (int i = 0; i < N; ++i) {
        valori[i] = (rand() % 40 - 10) + (rand()%10) / 10.0;
        printf("%4.1f ", valori[i]);
    }
    filtraggio(valori, N, k);
    printf("\n");
    for (int i = 0; i < N; ++i) {
        printf("%4.1f ", valori[i]);
    }
    return 0;
}